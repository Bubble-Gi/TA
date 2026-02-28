cmake_minimum_required(VERSION 3.22.1)
project(lab1)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(smc)
include_directories(smc)
add_executable(laba main.cpp)
target_link_libraries(laba smc)
target_include_directories(smc PUBLIC  /root/smc/smc_7_6_0/lib/C++)
