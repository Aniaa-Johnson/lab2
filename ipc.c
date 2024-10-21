#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h> 
#include <sys/stat.h>
#include "lab2.h"

// Function to create a shared memory object
void* ipc_create(size_t size) {
    int shm_fd = shm_open("lab2", O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Failed to create shared memory");
        exit(EXIT_FAILURE);
    }
    if (ftruncate(shm_fd, size) == -1) {
        perror("Failed to set size of shared memory");
        exit(EXIT_FAILURE);
    }
    void* ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("Failed to map shared memory");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Function to close shared memory
void ipc_close() {
    shm_unlink("lab2");
}
