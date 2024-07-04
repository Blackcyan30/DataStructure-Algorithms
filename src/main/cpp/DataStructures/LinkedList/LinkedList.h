#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
using namespace std;

/// @file LinkedList.h
/// @author M. Talha Adnan Khan
/// @date July 02, 2024
/// @brief This Linked list file contains an implementation of a linked list.
///        This file has the dependency of the node class for the linked list
///        node. This file is created to mimic a linked list for any type of
///        data. When initializing the user needs to define the data type for 
///        the linked list before hand, like what you do in a vector.


template<typename T>
class LinkedList {
    
private:    
    Node<T>* dummyHead;
    int size;

public:

    /// @brief Constructor
    LinkedList();

    /// @brief Copy constructor
    /// @param  
    LinkedList(const LinkedList &);

    /// @brief Over loaded assignment operator
    /// @param LinkedList Takes in the linked list of the right hand
    ///                   side to copy to the left hand side.
    /// @return Node* A deep copy of the linked list on the right hand side.
    LinkedList<T>& operator=(const LinkedList &);

    /// @brief Destructor -> Deletes the linked list
    ~LinkedList();

    /// @brief Getter for head of the linked list
    /// @return Node* Returns the pointer to the head
    ///         head of the linked list.
    Node<T>* getHead();

    /// @brief Setter for the head of the linked list
    /// @param node Takes in a node pointer to the new head
    ///             to be set of the linked list.
    void setHead(Node<T>* node);

    /// @brief This function clears the linked list by releasing
    ///        all memory allocations for all nodes.
    void clear();

    /// @brief This function inserts node at 
    ///        the front of the Linked list
    /// @param val 
    void prepend(T val);

    /// @brief This function inserts node
    ///        at the end of the linked list.
    /// @param val 
    void append(T val);

    /// @brief This function inserts at the given idx in 
    ///        the linked list. Given that it is a valid idx
    ///        or else it throws an exception.
    /// @param pos 
    /// @param val 
    void insertAt(int pos, T val);

    /// @brief This function removes a node from the
    ///        linked list. By default it removes it from
    ///        the end of the linked list but provided an
    ///        index it then removes the node at that index
    ///        given that it is a valid index to remove from.
    ///        indexing starts from 0.
    /// @param idx Index to pop node from.
    /// @return 
    T pop(int idx = -1);

    /// @brief Returns the data in the first node
    /// @return T
    T peekFront();

    /// @brief Tell you if an element exists in the linked list or not
    /// @return boolean if element exists
    bool find(T val);

    /// @brief Returns the number of nodes in the linked list
    /// @return int The size of linked list.
    int getSize();

    /// @brief Tells you if the linked list is empty or not.
    /// @return Boolean
    bool isEmpty();
};

#include "LinkedList.cpp"

#endif