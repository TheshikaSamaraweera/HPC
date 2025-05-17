#include <stdio.h>
#include<omp.h>


void normal_loopPI();
void parallel_loop();


int main(){
normal_loopPI();
parallel_loop();


}
void normal_loopPI(){
    static long num_step = 1000000000;
    double step;
    int i;
    double x, pi, sum = 0.0;
    step = 1.0/(double)num_step;

    double start_time = omp_get_wtime();  // Start timer
    for (i=0; i<num_step; i++){
            x = (i+0.5)*step;
            sum += 4.0/(1.0+x*x);
    }
    pi = step*sum;
    double end_time = omp_get_wtime();  // End timer

    printf("pi = %f\n", pi);
    printf("Time taken: %f seconds\n", end_time - start_time);
    return ;
}




void parallel_loop(){
    static long num_step = 1000000000;
    double step;
    int i;
    double x, pi, sum = 0.0;
    step = 1.0/(double)num_step;
    omp_set_num_threads(4); //this use 4 threads
    double start_time = omp_get_wtime();  // Start timer
    #pragma omp parallel for private(x) reduction(+:sum)
    for (i = 0; i < num_step; i++) {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    

    pi = step * sum;
    double end_time = omp_get_wtime();  // End timer
    printf("pi = %.15f\n", pi);  // More precision
    printf("Time taken: %f seconds\n", end_time - start_time);
    return ;
}