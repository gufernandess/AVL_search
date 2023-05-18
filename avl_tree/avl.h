#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <string>
#include <stack>

#include "node.h"

#include "../person/Person.h"
#include "../cpf/CPF.h"
#include "../date/Date.h"

using namespace std;

template <typename type> class avl_tree {

public:

    avl_tree() = default;
    avl_tree(const avl_tree& tree) = delete;
    void add(type key, Person *pointer_to_person);
    void bshow() const;
    void clear();

    Person search_by_CPF(CPF cpf);
    vector<Person> search_by_name(string name);
    vector<Person> search_by_date(Date initial_date, Date final_date);

    ~avl_tree();

private:

    Node<type> *root { nullptr };

    int height(Node<type> *node);
    int balance(Node<type> *node);

    Node<type>* rightRotation(Node<type> *node);
    Node<type>* leftRotation(Node<type> *node);
    Node<type>* fixup_node(Node<type> *node, type key);


    Node<type>* add(Node<type> *node, type key, Person *pointer_to_person);
    Node<type>* clear(Node<type> *node);

    Person* search_by_CPF(Node<CPF> *node, CPF cpf);
    vector<Person*> search_by_name(Node<string> *node, string name);
    vector<Person*> search_by_date(Node<Date> *node, Date initial_date, Date final_date);

    void bshow(Node<type> *node, std::string heritage) const;

};

template <typename type>
void avl_tree<type>::add(type key, Person *pointer_to_person) {
    root = add(root, key, pointer_to_person);
}

template <typename type>
void avl_tree<type>::bshow() const {
    bshow(root, "");
}

template <typename type>
void avl_tree<type>::clear() {
    root = clear(root);
}

/**
 * A função pública de pesquisa de CPF retorna uma instância de Person
*/

template <typename type>
Person avl_tree<type>::search_by_CPF(CPF cpf) {
   return *search_by_CPF(root, cpf);
}

/**
 * A função pública de pesquisa de nome retorna um vetor de instâncias
 * de Person que possuem o nome passado como parâmetro.
*/

template <typename type>
vector<Person> avl_tree<type>::search_by_name(string name) {
   vector<Person> people;

   for(Person *person : search_by_name(root, name)) {
        people.push_back(*person);
   }

   return people;
}

/**
 * A função pública de pesquisa de data retorna um vetor de instâncias
 * de Person baseado em um intervalo de datas.
*/

template <typename type>
vector<Person> avl_tree<type>::search_by_date(Date initial_date, Date final_date) {
    vector<Person> people;
    
    for(Person *person : search_by_date(root, initial_date, final_date)) {
          people.push_back(*person);
    }
    
    return people;
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

/**
 * Visando suprir o caso onde há chaves repetidas, segui as normas de
 * Thomas Cormen e modifiquei a função fixup_node para fazer as
 * rotações necessárias ao encontrar chaves iguais.
*/

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

    else if(new_balance > 1 && key >= node->right->key) node = leftRotation(node);

    else if(new_balance > 1 && key <= node->right->key) {
        node->right = rightRotation(node->right);
        node = leftRotation(node);
    }

    return node;
}

/**
 * Assim como sugerido por Thomas Cormen, nós com chaves repetidas
 * são adicionados á direita.
*/

template <typename type>
Node<type>* avl_tree<type>::add(Node<type> *node, type key, Person *pointer_to_person) {
    if(node == nullptr) return new Node<type>(key, pointer_to_person);

    if(node->key > key) node->left = add(node->left, key, pointer_to_person);

    else node->right = add(node->right, key, pointer_to_person);
    
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

/**
 * A pesquisa por CPF é feita de forma recursiva, e retorna um ponteiro
 * para a pessoa que possui o CPF pesquisado, que é acessado pela função
 * pública.
*/

template <>
Person* avl_tree<CPF>::search_by_CPF(Node<CPF> *node, CPF cpf) {
    if(node == nullptr) return nullptr;

    if(node->key == cpf) return node->pointer_to_person;

    else if(node->key > cpf) return search_by_CPF(node->left, cpf);

    return search_by_CPF(node->right, cpf);
}

/**
 * A pesquisa por nome é feita de forma iterativa, visto que eu posso
 * ter mais de uma pessoa como resultado da pesquisa, então tenho de
 * retornar um vetor de pessoas.
 * 
 * Neste caso eu retorno um vetor de ponteiros para pessoas, cujos
 * dados são acessados pela função pública.
*/

template <>
vector<Person*> avl_tree<string>::search_by_name(Node<string> *node, string name) {
    vector<Person*> people_with_name;
    stack<Node<string>*> node_stack;

    while(node != nullptr || !node_stack.empty()) {
        while(node != nullptr) {
            node_stack.push(node);
            node = node->left;
        }

        node = node_stack.top();
        node_stack.pop();

        if(node->key.substr(0, name.length()) == name) {
            people_with_name.push_back(node->pointer_to_person);
        }

        node = node->right;
    }

    return people_with_name;
}

/**
 * Decidi seguir a mesma lógica da pesquisa por nome, visto que a
 * pesquisa por data também pode retornar mais de uma pessoa.
*/

template <>
vector<Person*> avl_tree<Date>::search_by_date(Node<Date> *node, Date initial_date, Date final_date) {
    vector<Person*> people_with_date_interval;
    stack<Node<Date>*> node_stack;

    while(node != nullptr || !node_stack.empty()) {
        while(node != nullptr) {
            node_stack.push(node);
            node = node->left;
        }

        node = node_stack.top();
        node_stack.pop();

        if(node->key >= initial_date && node->key <= final_date) {
            people_with_date_interval.push_back(node->pointer_to_person);
        }

        node = node->right;
    }

    return people_with_date_interval;
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