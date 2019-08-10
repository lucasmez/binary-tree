#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "./TreeNode.h"
#include "TraversalIterators/PreorderIterator.h"
#include "TraversalIterators/InorderIterator.h"

template <typename T>
class BinaryTree {
    private:
        TreeNode<T>* root;

    public:
        BinaryTree(const T& rootData): root {nullptr} {
            this->root = new TreeNode<T>(rootData);
            this->root->left = nullptr;
            this->root->right = nullptr;
        }

        BinaryTree(BinaryTree&& src) {
            this->root = src.root;
            src.root = nullptr;
        }

        TreeNode<T>* getRoot() {
            return this->root;
        }

        ~BinaryTree() {
            if (root == nullptr) {
                return;
            }
            // Free all nodes
        }

    // Iterators
    public:
        typedef PreorderIterator<Node<T>> preorder_iterator;
        typedef InorderIterator<Node<T>> inorder_iterator;

        preorder_iterator begin_preorder() { return preorder_iterator {this->root}; }
        preorder_iterator end_preorder() { return preorder_iterator {nullptr}; }
        preorder_iterator begin_inorder() { return inorder_iterator {this->root}; }
        preorder_iterator end_inorder() { return inorder_iterator {nullptr}; }
};


#endif