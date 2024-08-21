#pragma once

template<typename T>
class Node {
public:
    T val;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;

    Node(T val = T(), Node<T>* left = nullptr, Node<T>* right = nullptr, Node<T>* parent = nullptr) : val(val), left(left), right(right), parent(parent) {} 
};
