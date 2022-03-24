cmake_minimum_required(VERSION 3.0.0)
project(hpc_toolbox VERSION 0.1.0)

find_package(MPI REQUIRED)

enable_testing()
add_subdirectory(tests)