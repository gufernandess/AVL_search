#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <string>

#include "node.h"

using namespace std;

template <typename type> class avl_tree {

public:

    avl_tree() = default;
    avl_tree(const avl_tree& t) = delete;
    void add(type key);
    void bshow() const;
    void clear();
    void remove(type key);

    ~avl_tree();
    
private:

    Node<type> *root {nullptr};

    int height(Node<type> *node);
    int balance(Node<type> *node);

    Node<type>* rightRotation(Node<type> *node);
    Node<type>* leftRotation(Node<type> *node);
    Node<type>* fixup_node(Node<type> *node, type key);


    Node<type>* add(Node<type> *node, type key);
    Node<type>* clear(Node<type> *node);
    Node<type>* fixup_deletion(Node<type> *node);
    Node<type>* remove(Node<type> *node, type key); 
    Node<type>* remove_successor(Node<type> *root, Node<type> *node);

    void bshow(Node<type> *node, std::string heritage) const;
};

template <typename type>
void avl_tree<type>::add(type key) {
    root = add(root, key);
}

template <typename type>
void avl_tree<type>::bshow() const {
    bshow(root, "");
}

template <typename type>
void avl_tree<type>::clear() {
    root = clear(root);
}

template <typename type>
void avl_tree<type>::remove(type key) {
    root = remove(root, key);
}

template <typename type>
avl_tree<type>::~avl_tree() {
    clear();
}

template <typename type>
int avl_tree<type>::height(Node<type> *node) {
    return (node == nullptr) ? 0 : node->height;
}

template <typename type>
int avl_tree<type>::balance(Node<type> *node) {
    return (height(node->right) - height(node->left));
}

template <typename type>
Node<type>* avl_tree<type>::rightRotation(Node<type> *node) {
    Node<type>* aux = node->left;

    node->left = aux->right;
    aux->right = node;

    node->height = 1 + max(height(node->left), height(node->right));
    aux->height = 1 + max(height(aux->left), height(aux->right));

    return aux;
}

template <typename type>
Node<type>* avl_tree<type>::leftRotation(Node<type> *node) {
    Node<type>*aux = node->right;

    node->right = aux->left;
    aux->left = node;

    node->height = 1 + max(height(node->right),height(node->left));
    aux->height = 1 + max(height(aux->left),height(aux->right));

    return aux;
}

template <typename type>
Node<type>* avl_tree<type>::fixup_node(Node<type> *node, type key) {
    node->height = 1 + max(height(node->left),height(node->right));

    int new_balance = balance(node);

    if(new_balance == 0 || abs(new_balance) == 1) return node;

    if(new_balance < -1 && key < node->left->key) node = rightRotation(node);

    else if(new_balance < -1 && key > node->left->key) {
        node->left = leftRotation(node->left);
        node = rightRotation(node);
    }

    else if(new_balance > 1 && key > node->right->key) node = leftRotation(node);

    else if(new_balance > 1 && key < node->right->key) {
        node->right = rightRotation(node->right);
        node = leftRotation(node);
    }

    return node;
}

template <typename type>
Node<type>* avl_tree<type>::add(Node<type> *node, type key) {
    if(node == nullptr) return new Node<type>(key);

    if(node->key == key) return node;

    if(node->key > key) node->left = add(node->left, key);

    else node->right = add(node->right, key);
    
    node = fixup_node(node, key);

    return node;
}

template <typename type>
Node<type>* avl_tree<type>::clear(Node<type> *node) {
    if(node != nullptr) {
        node->left = clear(node->left);
        node->right = clear(node->right);

        delete node;
    }

    return nullptr;
}

template <typename type>
Node<type>* avl_tree<type>::fixup_deletion(Node<type> *node) {
    node->height = 1 + max(height(node->left), height(node->right));

    int new_balance = balance(node);

    if(new_balance > 1 && balance(node->right) >= 0) return leftRotation(node);

    else if(new_balance > 1 && balance(node->right) < 0) {
        node->right = rightRotation(node->right);

        return leftRotation(node);
    }

    else if(new_balance < -1 && balance(node->left) <= 0) return rightRotation(node);

    else if(new_balance < -1 && balance(node->left) > 0) { 
        node->left = leftRotation(node->left);

        return rightRotation(node);
    
    return node;

    }
}

template <typename type>
Node<type>* avl_tree<type>::remove(Node<type> *node, type key) {
    if(node == nullptr) return nullptr;

    if(key < node->key) node->left = remove(node->left, key);
    
    else if(key > node->key) node->right = remove(node->right, key);

    else if(node->right == nullptr) {
        Node<type>* child = node->left;

        delete node;

        return child;
    }

    else node->right = remove_successor(node, node->right);
    
    node = fixup_deletion(node);

    return node;
}

template <typename type>
Node<type>* avl_tree<type>::remove_successor(Node<type> *root, Node<type> *node) {
    if(node->left != nullptr) node->left = remove_successor(root, node->left);

    else {
        root->key = node->key;
        Node<type>* aux = node->right;

        delete node;

        return aux;
    }

    node = fixup_deletion(node);

    return node;
}

template <typename type>
void avl_tree<type>::bshow(Node<type> *node, std::string heritage) const {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->right , heritage + "r");
    for(int i = 0; i < (int) heritage.size() - 1; i++)
        std::cout << (heritage[i] != heritage[i + 1] ? "│   " : "    ");
    if(heritage != "")
        std::cout << (heritage.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->left, heritage + "l");
}

#endif