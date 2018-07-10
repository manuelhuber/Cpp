#include <HashMap.cpp>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class HashMapTest : public ::testing::Test {
public:
    HashMap<std::string, int> *map;
protected:

    virtual void SetUp() {
        map = new HashMap<std::string, int>();
    }

    virtual void TearDown() {
        delete map;
    }
};

TEST_F(HashMapTest, test_constructor) {
    EXPECT_NE(map, nullptr);
}

TEST_F(HashMapTest, test_add) {
    map->add("foo", 42);
    EXPECT_EQ(map->get("foo"), 42);
}

TEST_F(HashMapTest, test_add_override) {
    map->add("foo", 42);
    map->add("foo", 43);
    EXPECT_EQ(map->get("foo"), 43);
}