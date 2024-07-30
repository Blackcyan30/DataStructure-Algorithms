#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <stdexcept>
#include <functional>
using namespace std;

template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
    
public:

    /// @brief Constructor.
    DoublyLinkedList();

    /// @brief Copy constructor.
    /// @param DoublyLinkedList Takes in the original list and
    ///                         makes a deep copy of it.
    DoublyLinkedList(const DoublyLinkedList<T>&);

    /// @brief Assignment operator.
    /// @param DoublyLinkedList Takes in the DoublyLinkedList on the
    ///                         rhs.
    /// @return Deep copy of the list to the lhs.
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);

    /// @brief Destructor.
    ~DoublyLinkedList();

    /// @brief This function inserts node at the
    ///        end of the linked list.
    /// @param val 
    /// @details This function appends to the end of the
    /// linked list. This is done by updating the head and
    /// the tail pointers when inserting the first element.
    /// in all other cases only the tail pointer is updated
    /// making the insertions happen in constant time on 
    /// average and having a time complexity of O(1).
    /// @note Insertion at the end of a doubly linked list
    ///       is done in constant time. O(1)
    void append(T val);

    /// @brief This function inserts the node at the
    ///        front of the list.
    /// @param val 
    void prepend(T val);

    /// @brief This function inserts at the given index in the 
    ///        linked list. Given that it is a valid index or
    ///        else it throws an exception.
    /// @param idx Index to insert at.
    /// @param val The value to be inserted.
    void insertAt(int idx, T val);

    /// @brief This function removes the node from the 
    ///        linked list. By default it removes it from
    ///        the end of the list, but provided an index
    ///        it then removes the node at that index. Given
    ///        that it is a valid index to remove from.
    ///        Indexing starts from 0.
    /// @param idx Indext to remove node from.
    /// @return The value stored in the node is returned.
    T pop(int idx = -1);

    /// @brief Returns the value stored in the first node.
    /// @return T Generic type.
    T peekFront();

    /// @brief Tells you if the element exists in the list
    ///        or not?
    /// @param val The value to be found.
    /// @return Boolean if found or not.
    bool find(T val);

    /// @brief Returns the size of the linked list.
    /// @return int
    int getSize();

    /// @brief Tells you if the list is empty or not?
    /// @return Boolean.
    bool isEmpty();

    /// @brief Cleans the list of all values.
    void clear();

    /// @brief Prints list to the terminal
    void printList();

};

#include "DoublyLinkedList.cpp"
#endif