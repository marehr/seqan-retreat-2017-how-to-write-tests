cmake_minimum_required (VERSION 3.0)

set(CMAKE_CXX_COMPILER "/usr/local/bin/g++-7")

project (test CXX)

enable_testing()

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++17")

set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(../include)

add_subdirectory(align)
