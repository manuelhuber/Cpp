include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runArrayListTests arrayList_test.cpp)

target_link_libraries(runArrayListTests gtest gtest_main)
target_link_libraries(runArrayListTests arrayList)