#include <HashMap.cpp>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(basic_check, test_eq) {
    auto *mappo = new HashMap<std::string, int>();
    EXPECT_NE(mappo, nullptr);
}

TEST(basic_check, test_neq) {
    EXPECT_NE(1, 0);
}