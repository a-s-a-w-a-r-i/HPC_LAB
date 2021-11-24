#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])  
{
      int numtasks,root=0,rank,tag1=100;

      MPI_Init(&argc,&argv);
      MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
      MPI_Comm_rank(MPI_COMM_WORLD, &rank);

      srand(time(NULL));  
    double total_time = 0.0;  
    double start_time = 0.0;

    start_time = MPI_Wtime();

     /*
      if(rank == root)
      {
	int i;
		 
    	for (i = 0; i < numtasks; i++) 
	{
      		if (i != rank) 
		{
        		MPI_Send(&tag1,1,MPI_INT,i,0,MPI_COMM_WORLD);
      		}
       }	
      }
      else 
      {
    		// If we are a receiver process, receive the data from the root
      		MPI_Recv(&tag1,1,MPI_INT, root,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

		printf("Process %d received message %d with tag %d from process %d\n",rank,tag1,1,root);
      }
     */

     MPI_Bcast(&tag1,1,MPI_INT,root,MPI_COMM_WORLD);

     if(rank!=root)
	printf("Process %d received message %d with tag %d from process %d\n",rank,tag1,1,root);

	total_time += (MPI_Wtime() - start_time); 

      MPI_Finalize();

	if(rank==0)       
    		printf("Execution time : %f secs\n", total_time); 
}