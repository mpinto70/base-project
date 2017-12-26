set(dir_srcs
    fileTest.cpp
)

set(dir_libs
    dir
    boost_filesystem
    boost_system
)

add_unit_test(
    dir
    dir_srcs
    dir_libs
)
