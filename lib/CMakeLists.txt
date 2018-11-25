include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.8.1
)

FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

function(add_gtest name target deps)
    message("${name} ${target} ${deps}")
    add_executable(${name} ${target})
    #target_include_directories(${name} PRIVATE ${deps})
    target_link_libraries(${name} gmock_main gtest gtest_main ${deps})

    add_test(${name} ${name})
endfunction()