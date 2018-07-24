#include <Tree.cpp>
#include <Node.cpp>
#include "gtest/gtest.h"
#include <string>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class TreeTest : public ::testing::Test {
public:
    Tree<std::string> *tree;
protected:

    void SetUp() override {
        tree = new Tree<std::string>();
    }

    void TearDown() override {
        delete tree;
    }
};

TEST_F(TreeTest, test_constructor) {
    ASSERT_NE(tree, nullptr);
}

TEST_F(TreeTest, test_add_root) {
    std::string foo = "foo";
    tree->setRoot(foo);
    EXPECT_NE(tree->getRoot(), nullptr);
}

TEST_F(TreeTest, test_find) {
    std::string foo = "foo";
    tree->setRoot(foo);
    Node<std::string> *root = tree->getRoot();
    Node<std::string> *node1 = new Node(std::string("bar"));
    Node<std::string> *node2 = new Node(std::string("baz"));
    Node<std::string> *node3 = new Node(std::string("bum"));
    root->addChild(node1);
    root->addChild(node2);
    node2->addChild(node3);
    EXPECT_EQ(tree->find(std::string("bum")), node3);
}

TEST_F(TreeTest, test_depth) {
    EXPECT_EQ(tree->depth(), 0);
    tree->setRoot("foo");
    EXPECT_EQ(tree->depth(), 1);
    Node<std::string> *root = tree->getRoot();
    Node<std::string> *node1 = new Node(std::string("bar"));
    root->addChild(node1);
    EXPECT_EQ(tree->depth(), 2);
    Node<std::string> *node2 = new Node(std::string("baz"));
    root->addChild(node2);
    EXPECT_EQ(tree->depth(), 2);
    Node<std::string> *node3 = new Node(std::string("bum"));
    node2->addChild(node3);
    EXPECT_EQ(tree->depth(), 3);
}

TEST_F(TreeTest, test_remove_empty) {
    EXPECT_FALSE(tree->remove("foo"));
}

TEST_F(TreeTest, test_remove) {
    tree->setRoot("foo");
    EXPECT_EQ(tree->depth(), 1);
    Node<std::string> *root = tree->getRoot();
    Node<std::string> *node1 = new Node(std::string("bar"));
    root->addChild(node1);
    EXPECT_EQ(tree->depth(), 2);
    Node<std::string> *node2 = new Node(std::string("baz"));
    root->addChild(node2);
    EXPECT_EQ(tree->depth(), 2);
    Node<std::string> *node3 = new Node(std::string("bum"));
    node2->addChild(node3);
    EXPECT_EQ(tree->depth(), 3);
    EXPECT_TRUE(tree->remove("bum"));
    EXPECT_EQ(tree->depth(), 2);
}
