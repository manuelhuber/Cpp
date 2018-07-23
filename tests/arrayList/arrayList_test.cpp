#include <ArrayList.cpp>
#include "gtest/gtest.h"
#include <string>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class ArrayListTest : public ::testing::Test {
public:
    ArrayList<std::string> *list;
protected:

    void SetUp() override {
        list = new ArrayList<std::string>();
    }

    void TearDown() override {
        delete list;
    }
};

TEST_F(ArrayListTest, test_constructor) {
    ASSERT_NE(list, nullptr);
}

TEST_F(ArrayListTest, test_add) {
    EXPECT_EQ(list->size(), 0);
    std::string string = "foo";
    list->add(&string);
    EXPECT_EQ(list->size(), 1);
}

TEST_F(ArrayListTest, test_add_many) {
    EXPECT_EQ(list->size(), 0);
    std::string foo = "foo";
    for (int i = 0; i < 50; i++) {
        list->add(&foo);
    }
    EXPECT_EQ(list->size(), 50);
    for (int i = 0; i < 50; i++) {
        list->remove(0);
    }
    EXPECT_EQ(list->size(), 0);
    delete foo;
}

TEST_F(ArrayListTest, test_remove) {
    EXPECT_EQ(list->size(), 0);
    auto foo = new std::string();
    list->add(foo);
    EXPECT_EQ(list->size(), 1);
    EXPECT_TRUE(list->remove(0));
    delete foo;
    EXPECT_EQ(list->size(), 0);
}

TEST_F(ArrayListTest, test_remove_false) {
    EXPECT_FALSE(list->remove(0));
}