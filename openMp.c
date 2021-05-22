#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){

omp_set_num_threads(7);

#pragma omp parallel // compiler directive
{printf("OpenMp thread: %d\n", omp_get_thread_num);}

return 0;

}
