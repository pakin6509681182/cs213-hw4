cmake_minimum_required(VERSION 3.0.0)
project(hw4 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(hw4 main.cpp)
add_executable(testpriority test_heap.cpp)
add_executable(test_graph test_graph.cpp)
add_executable(vector ex_vector.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
