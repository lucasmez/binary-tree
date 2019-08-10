#ifndef TREENODE_H
#define TREENODE_H

#include "./Node.h"

template <typename J>
struct TreeNode: public Node<J> {
    TreeNode() = default;

    TreeNode(const J& data) {
        this->data = data;
    }

    TreeNode(const J&& data) {
        this->data = data;
    }

    bool operator==(const TreeNode& rhs) {
        return this->data == rhs.data;
    }

    bool operator!=(const TreeNode& rhs) {
        return this->data != rhs.data;
    }

    Node<J>* addLeftChild(TreeNode<J>* newNode) {
        if (!this->left) {
            this->left = newNode;
        }
        return this->left;
    }

    Node<J>* addRightChild(TreeNode<J>* newNode) {
        if (!this->right) {
            this->right = newNode;
        }
        return this->right;
    }
};

#endif