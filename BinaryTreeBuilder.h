
#ifndef BINARYTREEBUILDER_H
#define BINARYTREEBUILDER_H

#include <stack>
#include "./TreeNode.h"

using namespace std;

template <typename H>
class BinaryTreeBuilder: public TreeNode<H> {
    private:
        stack<TreeNode<H>*> nodes;

    public:
        BinaryTreeBuilder(TreeNode<H>* root) {
            nodes.push(root);
        }

        BinaryTreeBuilder& addLeftChild(H data) {
            TreeNode<H>* newNode = new TreeNode<H>(data);
            nodes.top()->addLeftChild(newNode);
            nodes.push(newNode);
            return *this;
        }

        BinaryTreeBuilder& addRightChild(H data) {
            TreeNode<H>* newNode = new TreeNode<H>(data);
            nodes.top()->addRightChild(newNode);
            nodes.push(newNode);
            return *this;
        }

        BinaryTreeBuilder& done() {
            nodes.pop();    
            return *this;
        }
};

#endif