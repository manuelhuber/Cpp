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

    void SetUp() override {
        map = new HashMap<std::string, int>();
    }

    void TearDown() override {
        delete map;
    }
};

TEST_F(HashMapTest, test_constructor) {
    ASSERT_NE(map, nullptr);
}

TEST_F(HashMapTest, test_add) {
    map->add("foo", 42);
    EXPECT_TRUE(map->get("foo").has_value());
    EXPECT_EQ(map->get("foo").value(), 42);
}

TEST_F(HashMapTest, test_add_override) {
    map->add("foo", 42);
    EXPECT_TRUE(map->get("foo").has_value());
    map->add("foo", 43);
    EXPECT_TRUE(map->get("foo").has_value());
    EXPECT_EQ(map->get("foo").value(), 43);
}

TEST_F(HashMapTest, test_get_null) {
    EXPECT_FALSE(map->get("nothing").has_value());
}
