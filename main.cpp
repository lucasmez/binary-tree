#include <iostream>
#include <algorithm>
#include "./TreeNode.h"
#include "./BinaryTree.h"
#include "./BinaryTreeBuilder.h"
using namespace std;

template <typename T>
BinaryTree<T> createBinaryTree() {

    BinaryTree<T> tree {0};
    TreeNode<T>* root = tree.getRoot();
    BinaryTreeBuilder<T> treeBuilder {root};

    treeBuilder
        .addLeftChild(1)
            .addLeftChild(2)
            .done()
        .done()
        .addRightChild(3)
            .addLeftChild(4)
                .addLeftChild(5)
                .done()
            .done()
            .addRightChild(6)
                .addLeftChild(7)
                    .addLeftChild(8)
                    .done()
                .done()
            .done();

    return tree;
}

int main() {
    BinaryTree<int> tree { createBinaryTree<int>() };

    // Pre-order traversal
    for_each(tree.begin_preorder(), tree.end_preorder(), [](auto& node){
        cout << node.data << " ";
    });

    // In-order traversal
    for_each(tree.begin_inorder(), tree.end_inorder(), [](auto& node){
        cout << node.data << " ";
    });
}