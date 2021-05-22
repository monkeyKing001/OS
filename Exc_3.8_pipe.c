#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(){
    char write_msg[BUFFER_SIZE] = "Hello Pipe World!";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;

    //create pipe
    pipe(fd);

    //fork new process
    pid = fork();
    //parent process write
    if(pid>0){
        close(fd[READ_END]);

        write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
        close(fd[WRITE_END]);
    }
    //child process read
    else if (pid ==0)
    {
        close(fd[WRITE_END]);
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("read %s\n", read_msg);
        close(fd[READ_END]);
    }
    else{//error case
    printf("failed to fork");
    }

    return 0;
}