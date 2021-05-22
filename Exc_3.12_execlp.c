#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<wait.h>

int main(){

    pid_t pid, pid1;
    pid = fork();

    if(pid == 0){//incase child process
       execlp("/bin/ls", "ls", NULL);
       printf("print after execlp");
    }
    else if(pid>0){//incase parent process
        wait(NULL);
        printf("Child complete\n");
    }
    else{//incse error
        printf("failed to fork!");
        return -1;
    }

return 0;
}