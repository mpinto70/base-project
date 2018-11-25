
add_library(
    mck_dir
    fileMock.cpp
)

target_include_directories(
    mck_dir
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
