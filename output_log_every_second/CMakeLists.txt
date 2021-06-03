cmake_minimum_required(VERSION 3.13)  
project(output_log_every_second)             
set(CMAKE_CXX_STANDARD 14)            


set(SOURCE_FILES "service.cpp", "service.h")


add_executable(simple_example ${SOURCE_FILES})


