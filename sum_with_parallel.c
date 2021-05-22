#include <stdio.h>
#include <omp.h>

#define SIZE 1000000

int a[SIZE], b[SIZE], c[SIZE];

int main(int argc, char *argv[]){

int i;
for(i=0; i < SIZE; i++){
    a[i] = b[i] = i;
}

#pragma omp parallel for// compiler directive
for(i=0; i<SIZE; i++){
    c[i] = a[i] + b[i];
}


return 0;
}
