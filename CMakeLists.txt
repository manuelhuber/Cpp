cmake_minimum_required(VERSION 3.1)
project(Cpp)

#set(CMAKE_CXX_STANDARD 11)
add_definitions(-std=gnu++17)

set(SOURCE_FILES main.cpp)
add_executable(my_main ${SOURCE_FILES})

add_subdirectory(src/arraylist)
include_directories(src/arraylist)

add_subdirectory(src/hashmap)
include_directories(src/hashmap)

add_subdirectory(src/tree)
include_directories(src/tree)

add_subdirectory(tests)

target_link_libraries(my_main hashmap)

