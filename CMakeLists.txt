cmake_minimum_required(VERSION 3.0.0)
project(hpc_toolbox VERSION 0.1.0)

find_package(MPI REQUIRED)

include(CTest)
enable_testing()

add_executable(hpc_toolbox main.cpp)
target_include_directories(hpc_toolbox PRIVATE ${MPI_INCLUDE_PATH})
target_link_libraries(hpc_toolbox ${MPI_C_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
