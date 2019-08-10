
#ifndef PREORDERITERATOR_H
#define PREORDERITERATOR_H

#include <stack>
using namespace std;

template <typename T>
class PreorderIterator {
    public:
        using interator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        PreorderIterator(pointer curNode): curNode{curNode} {}
        PreorderIterator(const PreorderIterator& rhs): curNode{rhs.curNode} {}
        ~PreorderIterator() {}

        bool operator==(const PreorderIterator& rhs) const { return curNode == rhs.curNode; }
        bool operator!=(const PreorderIterator& rhs) const { return curNode != rhs.curNode; }
        PreorderIterator& operator++() { nextNode(); return *this; }
        PreorderIterator operator++(int) { PreorderIterator tmp{*this}; nextNode(); return tmp; }
        reference operator*() const { return *curNode; }
        pointer operator->() const { return curNode; }


    private:
        pointer curNode;
        stack<pointer> st; // Used to keep track of parent nodes while traversing.

        void nextNode() {
            if (!curNode) return;

            if (curNode->left) {
                st.push(curNode);
                curNode = curNode->left;

            } else if (curNode->right) {
                st.push(curNode);
                curNode = curNode->right;

            } else if (st.size() > 0) {
                pointer parent {nullptr};

                do {
                   parent = st.top(); 
                   st.pop();

                } while (parent && !parent->right && st.size() > 0);

                if (parent) {
                    curNode = parent->right;
                }
            }
        }
};

#endif