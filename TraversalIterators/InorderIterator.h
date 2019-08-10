
#ifndef INORDERITERATOR_H
#define INORDERITERATOR_H

#include <stack>
using namespace std;

template <typename T>
class InorderIterator {
    public:
        using interator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        InorderIterator(pointer curNode): curNode{curNode} { nextNode(); }
        InorderIterator(const InorderIterator& rhs): curNode{rhs.curNode} { nextNode(); }
        ~InorderIterator() {}

        bool operator==(const InorderIterator& rhs) const { return curNode == rhs.curNode; }
        bool operator!=(const InorderIterator& rhs) const { return curNode != rhs.curNode; }
        InorderIterator& operator++() { nextNode(); return *this; }
        InorderIterator operator++(int) { InorderIterator tmp{*this}; nextNode(); return tmp; }
        reference operator*() const { return *curNode; }
        pointer operator->() const { return curNode; }


    private:
        pointer curNode;
        stack<pointer> st; // Used to keep track of parent nodes while traversing.

        void nextNode() {
            if (curNode->left) {
                while (curNode->left) {
                    st.push(curNode);
                    curNode = curNode->left;
                }
            } else if (st.size() > 0) {
                curNode = st.top();
                st.pop();
            }

        }
};

#endif