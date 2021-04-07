cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)

project(hidden)
add_executable(hidden WIN32 hidden.cpp)

project(hiddenw)
add_executable(hiddenw WIN32 hidden.cpp)
target_compile_definitions(hiddenw PUBLIC WAIT_UNTIL_TERMINATE)