#include<stdio.h>
#include<omp.h>

// Add function prototype
int normal_loop();
void parallel_loop();


int main()
{
    normal_loop();
    parallel_loop();
    return 0;  
}

int normal_loop(){
    int i,sum =0;
    for (i=1;i<=100; i++)
    {
        sum += i;
    }
    printf("sum = %d\n" , sum);  
    return sum;
}

void parallel_loop()
{
    int i,sum =0;
    int thread_sum[4];
    omp_set_num_threads(4); //this use 4 threads
    #pragma omp parallel //use openmp (cpmiler directive as parell)
    {
        int ID = omp_get_thread_num();  //get thread id and assign to ID
        thread_sum[ID] = 0;  //save sum of each thread by each specific ID --thread_sum1=70, thread_sum2=30...
        #pragma omp for //use openmp for loop
        for(i=1; i<=100 ; i++)
        {
            thread_sum[ID] += i;
        }
    }
    for(int i = 0;i<4;i++){
        sum += thread_sum[i]; //add 4 sum calculate by 4 threads
    }
    printf("sum = %d",sum);
}