#include <stdlib.h>   
#include <stdio.h>    
#include <omp.h>      

#define ARRAY_SIZE 8     
#define NUM_THREADS 4    

int main (int argc, char *argv[]) 
{
	int *a,*c;
        
    int n = ARRAY_SIZE; 
	
	a = (int *) malloc(sizeof(int)*n);
	c = (int *) malloc(sizeof(int)*n);
	
	int n_per_thread;                   // elements per thread
	int total_threads = NUM_THREADS;    // number of threads to use  
	int i;       
        
	int x=10;
	
    for(i=0; i<n; i++) 
	{
		a[i] = i;
    }   
        
	omp_set_num_threads(total_threads);
	n_per_thread = n/total_threads;

	printf("\nTotal no. of threads : %d",total_threads);
	printf("\n\nEach thread will work on %d element(/s)",n_per_thread);
	
	printf("\n\n");
	
	#pragma omp parallel for shared(a,x,c) private(i) schedule(static, n_per_thread)
    for(i=0; i<n; i++) 
	{
		c[i] = a[i]+ x;
	
		printf("Thread %d works on element%d\n", omp_get_thread_num(), i);
    }

	printf("\nOriginal array    :");
	for(int i=0;i<n;i++)
	{
		printf("  %d",a[i]);
	}
	
	printf("\n\nValue to be added : ");
	printf(" %d",x);
	
	printf("\n\nNew array         : ");
	for(int i=0;i<n;i++)
	{
		printf(" %d",c[i]);
	}
        
	printf("\n");
	
	free(a); free(c);
	
	return 0;
}