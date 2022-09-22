#include<omp.h>
#include<stdio.h>
#include <time.h>

static int sum =0;
int main(int argc, char* argv)
{
	double time_spent = 0.0;
	clock_t begin = clock();
	
    #pragma omp parallel 
    {
        for(int i=1; i<=100;i++)
        {
           
                printf("thread No. %d Number : %d Square : %d\n", omp_get_thread_num(), i, i * i);  
                sum+=i*i;
           
        }
        printf("Sum is %d \n",sum);
    }
    
    clock_t end = clock();
 
   
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("Runtime is %f seconds", time_spent);
}
