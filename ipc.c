#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // Required for ftruncate
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "lab2.h"

char* ipc_create(int size) {  // Match the signature in lab2.h
    // Create a shared memory object called "lab2"
    int shm_fd = shm_open("/lab2", O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        return NULL; // Return NULL on error
    }

    // Set the size of the shared memory object
    if (ftruncate(shm_fd, size) == -1) {
        perror("ftruncate");
        return NULL; // Return NULL on error
    }

    // Map the shared memory object
    char* ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return NULL; // Return NULL on error
    }

    return ptr;  // Return a pointer to the memory map
}

void ipc_close() {
    // Unlink the shared memory object
    shm_unlink("/lab2");
}
