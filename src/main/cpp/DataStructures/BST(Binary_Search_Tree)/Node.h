#pragma once

template<typename T>
class Node {
    T val;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;

    Node(T val = T(), Node<T>* left = NULL, Node<T>* right = NULL, Node<T>* parent = NULL) : val(val), left(left), right(right), parent(parent) {} 
};
