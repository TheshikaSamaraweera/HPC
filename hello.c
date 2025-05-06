#include<stdio.h>
#include<omp.h>

void main()
{
    omp_set_num_threads(4); //using 4 threads
    int id;
    #pragma omp parallel //use pragma OpenMP
    {
        id = omp_get_thread_num(); //get thread number
        printf(" Thread No %d :Hello world\n",id);

    }
    return;
}