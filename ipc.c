#include <sys/mman.h>
#include <sys/stat.h>        
#include <fcntl.h>
#include <unistd.h>


/**************************************************************
 *  ipc_create - creates a shared memory object called lab2 and
 *               returns a char pointer to the memory shared
 *               memory object.
 * 
 *  size - is the size of the memory object to create.
 *   
 ***************************************************************/
char* ipc_create(int size){
    /* shared memory file descriptor */
    int fd;
    /* pointer to shared memory obect */
    char* ptr;

    fd = shm_open("lab2", O_CREAT | O_RDWR, 0666);

    // TODO: configure the size of the shared memory object 
    ftruncate(fd,size);

    // TODO: memory map the shared memory object */
    ptr =  mmap(0,size,PROT_READ | PROT_WRITE, MAP_SHARED,fd,0);

    return ptr;
}


/**************************************************************
 * ipc_close - closes the ipc communication channel that was
 *             created with ipc_create.
 * 
 **************************************************************/
void ipc_close(){
    shm_unlink("lab2");
}