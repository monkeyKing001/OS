#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<wait.h>
int main(){

    pid_t pid;
    printf("process start!\n");    
    pid = fork();

    if(pid<0){//incase fork fail
        printf("failed to fork\n");
    }
    else if (pid==0)//incase child process, pid = 0
    {
        printf("This process is child process pid : %d\n", pid);
    }
    else{//incase parent process
        wait(NULL);
        printf("This process is parent process pid : %d\n", pid);
    }
    
    printf("process exit\n");
    printf("vim test\n");
    return 0;
}
