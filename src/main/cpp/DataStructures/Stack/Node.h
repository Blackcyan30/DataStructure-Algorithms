#pragma once

template<typename T>
class Node {

    T val;
    Node<T>* next;
    
    Node(T val = T(), Node<T>* next = nullptr) : val(val) , next(next) {}
};