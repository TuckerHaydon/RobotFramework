cmake_minimum_required(VERSION 3.2)

project(TestRobotFramework)
set(CMAKE_CXX_STANDARD 14)

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# Add header files
FILE(GLOB_RECURSE header_list ${CMAKE_SOURCE_DIR}/include/*.h)
FOREACH(file_path ${header_list})
    GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
    include_directories(${dir_path})
ENDFOREACH()

# Make test executable
file(GLOB_RECURSE TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE CODE_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
list(REMOVE_ITEM CODE_SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp)
add_executable(${PROJECT_NAME} ${TEST_SOURCES} ${CODE_SOURCES})
target_link_libraries(${PROJECT_NAME} Catch)

# Coveralls Setup
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/modules/code-coverage)
include(CodeCoverage)
SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
setup_target_for_coverage(
        NAME ${PROJECT_NAME}_coverage
        EXECUTABLE ${PROJECT_NAME}
        DEPENDENCIES ${PROJECT_NAME}
)
