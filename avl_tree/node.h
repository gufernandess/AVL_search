#ifndef NODE_H
#define NODE_H

template <typename type> struct Node {

    type key;
    int height;
    Node *left;
    Node *right;

    Node(type key) : key(key), height(1), left(nullptr), right(nullptr) {}
};

#endif
