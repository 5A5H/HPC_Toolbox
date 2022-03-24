# include <iostream>
# include <mpi.h>

int main( int argc, char *argv[] )
{
    int ierr, size, rank, master(0);
    double wall_time;

    // initialize mpi communicator
    ierr = MPI_Init( &argc, &argv );
    if (ierr!=0) std::cerr << "Error! Could not initialize MPI Communicator." << std::endl;

    // identify ranks
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );

    // master rank tracks time
    if (rank==master) wall_time = MPI_Wtime();

    // every rank sents a message
    std::cout << "Hello from rank " << rank << " out of " << size << std::endl;

    // track the time
    MPI_Barrier( MPI_COMM_WORLD );
    if (rank==master) std::cout << "Elapsed wall clock time: " << MPI_Wtime ( ) - wall_time << " seconds." << std::endl;

    // finalize mpi communicator
    MPI_Finalize();


}
