#pragma once
using namespace std;

template<typename T>
class Node {
    T val;
    Node<T>* next;
    Node<T>* prev;

    Node(T val = T(), Node<T>* next = nullptr, Node<T>* prev = nullptr) {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};