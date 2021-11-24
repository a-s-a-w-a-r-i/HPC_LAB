#include <stdio.h>
#include <omp.h>
#include <time.h>

int main(void)
{    
    int sum = 0;

    printf("\n Demonstration of master clause : \n");

    #pragma omp parallel
    {
    	#pragma omp master
    	{
            printf("Thread %d is executing master construct\n", omp_get_thread_num());
    	}
    	printf("Thread %d is executing non-master construct\n", omp_get_thread_num());
    }

    clock_t start,end;

    printf("\n Demonstration of reduction clause : \n");
	
	start=clock();

    #pragma omp parallel for reduction(+ : sum)
    for (int i = 1; i <= 4; i++)
    {
        sum += i;
    }

    printf("Sum is : %d\n",sum);

	end=clock();
	
	double time_taken =(double)(end - start)/(double)(CLOCKS_PER_SEC);;
    printf("Time taken is : %f sec",time_taken);


    sum=0;

    printf("\n Demonstration of critical clause : \n");

	
	start=clock();

    #pragma omp parallel for 
    for (int i = 1; i <= 4; i++)
    {
 	#pragma omp critical
        sum += i;
    }

    printf("Sum is : %d\n",sum);  

	end=clock();
	
	time_taken =(double)(end - start)/(double)(CLOCKS_PER_SEC);;
    printf("Time taken is : %f sec",time_taken);

    return 0;
}  