include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runTreeTests tree_test.cpp)

target_link_libraries(runTreeTests gtest gtest_main)
target_link_libraries(runTreeTests tree)