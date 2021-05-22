#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<wait.h>

int main(){

    pid_t pid, pid1;
    pid = fork();

    if(pid == 0){//incase child process
        pid1 = getpid();
        printf("child processs pid: %d\n",pid);
        printf("child processs pid1: %d\n",pid1);
    }
    else if(pid>0){//incase parent process
        pid1 = getpid();
        printf("parent processs pid: %d\n",pid);
        printf("parent processs pid: %d\n",pid1);
    }
    else{//incase error
        printf("failed to fork!");
        return -1;
    }

return 0;
}