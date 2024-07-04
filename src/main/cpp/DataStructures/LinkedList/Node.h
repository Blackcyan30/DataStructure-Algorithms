# pragma once
using namespace std;

/// @brief This is the defination of node class
///        that is to be used for linked list.
/// @tparam T

template<typename T>
class Node {
public:
    T val;
    Node* next;
    
    Node(T value = T(), Node* next = nullptr) : val(value), next(next) {}
};