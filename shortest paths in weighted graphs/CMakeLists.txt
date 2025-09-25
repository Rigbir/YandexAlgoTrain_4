cmake_minimum_required(VERSION 3.31)
project(shortest_paths_in_weighted_graphs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(shortest_paths_in_weighted_graphs
        task_1.cpp
        task_2.cpp
        task_3.cpp
        task_4.cpp)

add_executable(Test1 task_1.cpp)
add_executable(Test2 task_2.cpp)
add_executable(Test3 task_3.cpp)
add_executable(Test4 task_4.cpp)

target_compile_options(shortest_paths_in_weighted_graphs PRIVATE -Wextra -Werror)
