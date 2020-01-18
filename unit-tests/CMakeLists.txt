cmake_minimum_required(VERSION 3.0)

project(unit-tests)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${unit-tests_SOURCE_DIR})

set (WSJCPP_LIBRARIES "")
set (WSJCPP_INCLUDE_DIRS "")
set (WSJCPP_SOURCES "")

# Sources

# wsjcpp_wsjcpp_core
list (APPEND WSJCPP_INCLUDE_DIRS "../src.wsjcpp/wsjcpp_wsjcpp_core/")
list (APPEND WSJCPP_SOURCES "../src.wsjcpp/wsjcpp_wsjcpp_core/wsjcpp_core.h")
list (APPEND WSJCPP_SOURCES "../src.wsjcpp/wsjcpp_wsjcpp_core/wsjcpp_core.cpp")

# wsjcpp-arguments
list (APPEND WSJCPP_INCLUDE_DIRS "../src")
list (APPEND WSJCPP_SOURCES "../src/wsjcpp_arguments.h")
list (APPEND WSJCPP_SOURCES "../src/wsjcpp_arguments.cpp")

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "../src")
list (APPEND WSJCPP_INCLUDE_DIRS "src")

list (APPEND WSJCPP_SOURCES "./src/main.cpp")
list (APPEND WSJCPP_SOURCES "./src/unit_tests.h")
list (APPEND WSJCPP_SOURCES "./src/unit_tests.cpp")
list (APPEND WSJCPP_SOURCES "./src/unit_test_simple_arguments.h")
list (APPEND WSJCPP_SOURCES "./src/unit_test_simple_arguments.cpp")
list (APPEND WSJCPP_SOURCES "./src/unit_test_arguments_with_params.h")
list (APPEND WSJCPP_SOURCES "./src/unit_test_arguments_with_params.cpp")

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable ("unit-tests" ${WSJCPP_SOURCES})

target_link_libraries("unit-tests" -lpthread ${WSJCPP_LIBRARIES} )

install(
    TARGETS
        "unit-tests"
    RUNTIME DESTINATION
        /usr/bin
)