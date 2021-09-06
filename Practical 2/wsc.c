#include <stdlib.h>  
#include <stdio.h>   
#include <omp.h>  
   
#define ARRAY_SIZE 8    
#define NUM_THREADS 4    

int main (int argc, char *argv[]) 
{
	int * a;
	int * c;
        
    int n = ARRAY_SIZE;  

	a = (int *) malloc(sizeof(int)*n);
	c = (int *) malloc(sizeof(int)*n);
	   
	int i;     

	int x=10;
	
    for(i=0; i<n; i++) 
	{
       a[i] = i;
    }
	
	#pragma omp parallel 
    {
		int id, i, Nthrds, istart, iend;
		
		id = omp_get_thread_num();
		Nthrds = omp_get_num_threads();
		
		istart = id*n/Nthrds;
		iend = (id+1)*n/Nthrds;
		
		if(id == Nthrds-1) 
			iend = n;
		
		for(i = istart; i<iend; i++)
		{
			c[i] = x+a[i];
		}
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
	
	
	free(a); 
	free(c);
	
	return 0;
}