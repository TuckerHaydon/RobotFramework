cmake_minimum_required(VERSION 3.2)

project(cmake_test)
set(CMAKE_CXX_STANDARD 14)

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# Add header files
FILE(GLOB_RECURSE header_list ${CMAKE_CURRENT_SOURCE_DIR}/../include/*.h)
FOREACH(file_path ${header_list})
    GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
    include_directories(${dir_path})
ENDFOREACH()

# Make test executable
file(GLOB_RECURSE TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests Catch)


