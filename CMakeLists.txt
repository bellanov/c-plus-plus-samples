cmake_minimum_required(VERSION 3.14)
project(cpp-samples VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Code coverage configuration
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Add library sources
set(SOURCES
    src/string_utils.cpp
)

# Create library
add_library(string_utils STATIC ${SOURCES})
target_include_directories(string_utils PUBLIC include)

# Enable testing
enable_testing()

# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP ON
)

FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(string_utils_test test/string_utils_test.cpp)
target_link_libraries(string_utils_test 
    PRIVATE 
    string_utils
    gtest_main
)
target_include_directories(string_utils_test PRIVATE include)

# Register test
add_test(
    NAME string_utils_test
    COMMAND string_utils_test
)

# Add coverage target
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_custom_target(coverage
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        COMMAND gcov -p -o . ${CMAKE_CURRENT_SOURCE_DIR}/src/string_utils.cpp
        COMMAND mkdir -p coverage_report
        COMMAND lcov --capture --directory . --output-file coverage_report/coverage.info --include='*/src/*' --exclude='*/test/*'
        COMMAND genhtml coverage_report/coverage.info --output-directory coverage_report/html
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running tests and generating coverage report"
    )
endif()
