cmake_minimum_required(VERSION 3.20)
project(fastImpl)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
add_subdirectory(lib)
add_subdirectory(tests)
