cmake_minimum_required(VERSION 3.10)

project(GOLlib LANGUAGES CXX CUDA)

set(SOURCES
    golcpu.cpp
    grid.cpp
)

set(HEADERS
    golcpu.h
    grid.h
)

set(CUDA_FILES
    gol.cu
)

add_library(CuGOL STATIC ${SOURCES} ${HEADERS} ${CUDA_FILES})
