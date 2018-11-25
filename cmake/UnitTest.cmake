################################################################################
# Google Test Setup - BEGIN ####################################################
################################################################################

download_project(
    PROJ                googletest
    GIT_REPOSITORY      https://github.com/google/googletest.git
    GIT_TAG             release-1.8.1
    ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

################################################################################
# Google Test Setup - END ######################################################
################################################################################

function(add_unit_test test_name sources_var libs_var)
    set(unit_test_name unit_${test_name})

    add_executable(
        ${unit_test_name}
        ${PROJECT_SOURCE_DIR}/test/gtest_main.cpp
        ${${sources_var}}
    )

    set_target_properties(
        ${unit_test_name}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/test/bin
    )

    target_link_libraries(
        ${unit_test_name}
        ${${libs_var}}
        gtest
        gmock_main
    )

    add_test(NAME ${unit_test_name} COMMAND ${PROJECT_SOURCE_DIR}/test/bin/${unit_test_name})
endfunction(add_unit_test)
