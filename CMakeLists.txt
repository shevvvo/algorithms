cmake_minimum_required(VERSION 3.21)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_library(listgraph src/ListGraph.cpp)
add_library(matrix src/MatrixGraph.cpp)
add_library(set src/SetGraph.cpp)
add_library(arc src/ArcGraph.cpp)

add_executable(algorithms main.cpp)

target_link_libraries(algorithms listgraph matrix set arc)

target_include_directories(listgraph PUBLIC include)
target_include_directories(matrix PUBLIC include)
target_include_directories(set PUBLIC include)
target_include_directories(arc PUBLIC include)
