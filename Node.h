#ifndef NODE_H
#define NODE_H

template <typename K>
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    K data;
};

#endif
