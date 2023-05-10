#ifndef NODE_H
#define NODE_H

template <typename type> struct Node {

    type key;
    int height;
    Node *left;
    Node *right;

    Node(type key, Node *left = nullptr, Node *right = nullptr, int height = 1) {
        this->key = key;
    }
};

#endif
