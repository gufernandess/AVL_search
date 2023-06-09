#ifndef NODE_H
#define NODE_H

template <typename type> struct Node {

    type key;
    Person *pointer_to_person; // Cada nó da árvore terá um ponteiro para a pessoa que ele representa.
    int height;
    Node *left;
    Node *right;

    Node(type key, Person *pointer_to_person) : key(key), pointer_to_person(pointer_to_person), height(1), left(nullptr),
                                                right(nullptr) {}
};

#endif
