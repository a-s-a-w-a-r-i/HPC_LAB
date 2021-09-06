#include <stdlib.h>   
#include <stdio.h>  
#include <time.h> 
#include <omp.h>      

#define ARRAY_SIZE 1000   
#define NUM_THREADS 50  

int main(int argc, char *argv[]) 
{
	clock_t start,end;
	
	start=clock();
	
	int * a,* b,* c;
        
    int n = ARRAY_SIZE;                 
	
	a = (int *) malloc(sizeof(int)*n);
	b = (int *) malloc(sizeof(int)*n);
	c = (int *) malloc(sizeof(int)*n);
	
	int n_per_thread;                   // elements per thread
	int total_threads = NUM_THREADS;    // number of threads to use  
	int i;       
    
    for(i=0; i<n; i++)
        a[i] = i;
      
    for(i=0; i<n; i++) 
        b[i] = i;
         
	omp_set_num_threads(total_threads);
	n_per_thread = n/total_threads;
	
	printf("\nTotal no. of threads : %d",total_threads);
	printf("\n\nEach thread will work on %d element(/s)",n_per_thread);
	
	printf("\n\n");
	
	#pragma omp for nowait
    for(i=0; i<n; i++) 
	{
		c[i] = a[i]+b[i];
		
		printf("Thread %d works on element%d\n", omp_get_thread_num(), i);
    }
	/*
	printf("\nFirst array     :");
	for(int i=0;i<n;i++)
	{
		printf("  %d",a[i]);
	}
	
	printf("\n\nSecond array    :");
	for(int i=0;i<n;i++)
	{
		printf("  %d",b[i]);
	}
	
	printf("\n\nResultant array :");
	for(int i=0;i<n;i++)
	{
		printf("  %d",c[i]);
	}
     */   
	printf("\n");
	
    free(a);  free(b); free(c);
	
	end=clock();
	
	double time_taken =(double)(end - start)/(double)(CLOCKS_PER_SEC);;
    printf("Time taken by program is : %f sec",time_taken);
	
	return 0;
}