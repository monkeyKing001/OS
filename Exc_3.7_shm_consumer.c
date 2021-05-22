#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
    const int SIZE = 4096; // the size of shared memory
    const char *name = "OS"; // the name of shared memory
    const char *message_0 = "Hello, ";
    const char *message_1 = "Shared Memory!\n";
    int shm_fd; // the file descriptor of shared memory
    char *ptr; // pointer to shared memory

    //create teh shared memory object
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    //map the shared memory object
    ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    //read from shared memory
    printf("%s", (char *)ptr);

    //remove link
    shm_unlink(name);
    
    return 0;
}



