/* Program to compute Pi using Monte Carlo methods */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <omp.h>
#define SEED 35791246
int main(int argc, char* argv)
{
     int niter=0;
     double x,y;
     int i,count=0; /* # of points in the 1st quadrant of unit circle */
     double z;
     double pi;
     printf("Enter the number of iterations used to estimate pi: ");
     scanf("%d",&niter);

     /* initialize random numbers */
     srand(SEED);

     #pragma omp parallel for private(x,y) reduction(+:count)
     for ( i=0; i<niter; i++) 
     {
         x = (double)rand()/RAND_MAX;
         y = (double)rand()/RAND_MAX;
         
         z = x*x+y*y;
         printf("Thread %d works on iteration %d\n", omp_get_thread_num(), i);

         if (z<=1) count++;
     }

     pi=(double)count/niter*4;
     printf("# of trials= %d , estimate of pi is %g \n",niter,pi);
}