include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHashMapTests hashmap_test.cpp)

target_link_libraries(runHashMapTests gtest gtest_main)
target_link_libraries(runHashMapTests hashmap)