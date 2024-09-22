#include <gtest/gtest.h>

#include "binary_tree.hpp"

class T {};

class BinaryTreeTest : public testing::Test {
    protected:
        BinaryTree() {

        }
    private: 
        BinaryTree<int> tree({2, 1, 4, 5, 8, 1, 3});
};

TEST(BinaryTree, TestConstructor) {

    BinaryTree<T> tree_1({T(), T(), T()});
}

