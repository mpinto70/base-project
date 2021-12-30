cmake_minimum_required (VERSION 3.11)
project (PROJECT_NAME_GOES_HERE VERSION 1.0.0 LANGUAGES CXX)

# add support for CTest
include(CTest)
include(FetchContent)
include(ExternalProject)

set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS " \
    -Wno-parentheses \
    -Werror \
    -Wall \
    -Wextra \
    -pedantic-errors \
    -O2 \
    -finline-functions \
    -D PROJECT_DIR=\"\\\"${CMAKE_SOURCE_DIR}\\\"\"")

# set (CMAKE_VERBOSE_MAKEFILE on)

set(EXTERNAL_INSTALL_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/external)

###################################
# libbrasa - BEGIN ################
###################################

set(BRASA_DIR ${CMAKE_BINARY_DIR}/brasa)

ExternalProject_Add(libbrasa
        GIT_REPOSITORY https://github.com/mpinto70/libbrasa.git
        GIT_TAG        v0.10
        PREFIX ${BRASA_DIR}
        INSTALL_COMMAND
        make
        DESTDIR=${EXTERNAL_INSTALL_ROOT}
        install
        LOG_INSTALL ON
        LOG_BUILD ON
        )

include_directories(${EXTERNAL_INSTALL_ROOT}/brasa/include)
link_directories(${EXTERNAL_INSTALL_ROOT}/brasa/lib)

add_library(brasa_argparse STATIC IMPORTED)
set_property(TARGET brasa_argparse PROPERTY IMPORTED_LOCATION ${EXTERNAL_INSTALL_ROOT}/brasa/lib/libbrasa_argparse.a)
add_dependencies(brasa_argparse libbrasa)

###################################
# libbrasa - END   ################
###################################

set (CMAKE_INSTALL_PREFIX /base_dir)

INSTALL (
        DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/dir
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include
        FILES_MATCHING PATTERN "*.h"
)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/UnitTest.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CppCheck.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Boost.cmake)

# Recurse subdirectories
add_subdirectory (src)
add_subdirectory (mck)
add_subdirectory (test)
