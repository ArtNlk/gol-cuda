cmake_minimum_required(VERSION 3.20)

project(GOLApp)

# Add C++ files to the project
set(SOURCES
    main.cpp
    golapp.cpp
)

set(HEADERS
    golapp.h
)

# Tell CMake to compile the CUDA files
#set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-O3)

add_executable(GOLApp ${SOURCES} ${HEADERS})
