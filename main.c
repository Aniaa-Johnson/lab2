#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/wait.h>
#include "lab2.h"

char** get_arguments(int argc, char** argv) {
    char** cmd_args = (char**)malloc(sizeof(char*) * argc);
    if (cmd_args == NULL) {
        perror("Failed to allocate memory for command arguments");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < argc - 1; i++) {
        cmd_args[i] = argv[i + 1];
    }
    cmd_args[argc - 1] = NULL; // Set the last element to NULL
    return cmd_args;
}

int main(int argc, char** argv) {
    pid_t pid;
    struct timeval start_time, current_time;
    char* ipc_ptr = NULL;

    if (argc < 2) {
        fprintf(stderr, "SYNOPSIS: %s <cmd> <cmd arguments>\n", argv[0]);
        return 1;
    }

    ipc_ptr = ipc_create(sizeof(start_time));

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 2;
    } else if (pid == 0) {
        gettimeofday(&start_time, NULL);
        memcpy(ipc_ptr, &start_time, sizeof(start_time));
        
        char** arguments = get_arguments(argc, argv);
        execvp(argv[1], arguments);
        
        // If execvp fails
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
        gettimeofday(&current_time, NULL);
        memcpy(&start_time, ipc_ptr, sizeof(start_time));
        ipc_close();

        printf("Elapsed time: %.5f\n", elapsed_time(&start_time, &current_time));
    }

    return 0;
}
