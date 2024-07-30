# pragma once
using namespace std;

/// @brief This is the defination of node class
///        that is to be used for linked list.
/// @tparam T

template<typename T>
class Node {
public:
    T val;
    Node<T>* next;
    Node<T>* prev;
    
    Node(T value = T(), Node<T>* next = nullptr, Node<T>* prev = nullptr) {
        this->val = value;
        this->next = next;
        this->prev = prev;
    }
};