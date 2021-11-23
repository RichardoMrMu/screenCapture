project(test)

cmake_minimum_required(VERSION 2.8.7)


set(CMAKE_CXX_FLAGS "-std=c++0x")
find_package(OpenCV REQUIRED)
add_executable(test test.cpp)
target_link_libraries(test ${OpenCV_LIBS})
list(APPEND CUDA_NVCC_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "-std=c++0x") 
