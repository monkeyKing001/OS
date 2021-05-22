#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 255
#define READ_END 0
#define WRITE_END 1

int main(){

    pid_t pid1;
    char writeMsg[BUFFER_SIZE] = "Dont be afraid, try everything";
    char readMsg[BUFFER_SIZE];
    int fd[2];

    pipe(fd);


    pid1 = fork();

    if(pid1==0){//incase child, write //strlen(writeMsg)+1 BUFFER_SIZE
        close(fd[READ_END]);
        write(fd[WRITE_END], writeMsg, BUFFER_SIZE);
        close(fd[WRITE_END]);    
    }

    else if(pid1>0){//incase parent, read
        wait(NULL);
        close(fd[WRITE_END]);
        read(fd[READ_END], readMsg, BUFFER_SIZE);
        printf("read msg : %s", readMsg);
        close(fd[READ_END]);

    }
    else{
        printf("fork() error!");
    }


    return 0;
}