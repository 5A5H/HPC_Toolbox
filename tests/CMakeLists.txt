add_executable(mpi_test_a mpi_test_a.cpp)
target_include_directories(mpi_test_a PRIVATE ${MPI_INCLUDE_PATH})
target_link_libraries(mpi_test_a ${MPI_C_LIBRARIES})

add_test(NAME mpi_test_a
        COMMAND ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} 4 ./mpi_test_a
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
