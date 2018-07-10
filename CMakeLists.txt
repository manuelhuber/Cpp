cmake_minimum_required(VERSION 3.1)
project(Cpp)

#set(CMAKE_CXX_STANDARD 11)
add_definitions(-std=gnu++11)

set(SOURCE_FILES main.cpp)
add_executable(my_main ${SOURCE_FILES})

include_directories(src/hashmap)

add_subdirectory(src/hashmap)
add_subdirectory(tests)

target_link_libraries(my_main hashmap)

