
cmake_minimum_required (VERSION 2.8.11)
project (PROJECT_NAME_GOES_HERE)

# add support for CTest
enable_testing()
include(CTest)

set(CMAKE_CXX_FLAGS "-Werror \
    -Wall \
    -O2 \
    -finline-functions \
    -std=c++14 \
    -Wno-unused-local-typedefs \
    -D PROJECT_DIR=\"\\\"${CMAKE_SOURCE_DIR}\\\"\"")

#set (CMAKE_VERBOSE_MAKEFILE on)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

find_package(Boost 1.65 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

include(UnitTest.cmake)
include(CppCheck.cmake)

# Recurse subdirectories
add_subdirectory (src)
add_subdirectory (test)
