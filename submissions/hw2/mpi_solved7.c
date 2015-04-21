/******************************************************************************
* FILE: mpi_bug7.c
* DESCRIPTION:
*   This program hangs.
* AUTHOER: Blaise Barney
* LAST REVISED: 01/24/09
******************************************************************************/
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
int   numtasks, taskid, len, buffer, root, count;
char hostname[MPI_MAX_PROCESSOR_NAME];

MPI_Init(&argc, &argv);
MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
MPI_Get_processor_name(hostname, &len);

printf ("Task %d on %s starting...\n", taskid, hostname);
buffer = 23;
root = 0;
//Count is the number of MPI_INT variables to be sent by root and to be recieved by
//rest of the processes. Since count is 0 for root, nothing gets broadcasted and all
//the processes are waiting for a variable number of integers
//count = taskid;
count = 1;
if (taskid == root)
   printf("Root: Number of MPI tasks is: %d\n",numtasks);

MPI_Bcast(&buffer, count, MPI_INT, root, MPI_COMM_WORLD);


MPI_Finalize();

}

