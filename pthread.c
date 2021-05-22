#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <pthread.h>
#include <stdlib.h>

#define READ_END 0
#define WRITE_END 1
#define BUFFER_SIZE 255

int sum, readVal;
// char writeVal[BUFFER_SIZE], readVal[BUFFER_SIZE];
void * runner(void *param); //thread will call this func

int main(int argc, char *argv[]){
    pid_t pid; //process id
    pthread_t tid; //thread id
    pthread_attr_t attr; //thread attribute

    int fd[2];
    pipe(fd);

    pid = fork();

    if(pid ==0){//child
        pthread_attr_init(&attr);                       //set thread attribute -> deafault
        pthread_create(&tid, &attr, runner, argv[1]);   //create thread, Thread thread1 =  new Thread(tid, runner);
        pthread_join(tid, NULL);                        // thread.start();
        close(fd[READ_END]);
        write(fd[WRITE_END], &sum, sizeof(sum));
        close(fd[WRITE_END]);        
    }
    else if(pid > 0){//parent
        wait(NULL);   
        close(fd[WRITE_END]);
        read(fd[READ_END], &readVal, sizeof(readVal));
        printf("sum = %d \n", readVal);
        close(fd[READ_END]);
    }

    else{//thread error

    }
    return 0;
}

void *runner(void *param){
    sum = 0;
    int i, n = atoi(param);
    for(i = 1; i <= n; i++){
        sum += i;
    }
    pthread_exit(0);
}