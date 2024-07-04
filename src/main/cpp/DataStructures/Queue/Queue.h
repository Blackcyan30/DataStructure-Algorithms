#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
template<typename T>
class Queue {

private:
    Node<T>* top;

public:

    /// @brief Constructor.
    Queue();

    /// @brief Copy constructor
    /// @param Queue Takes in the original queuq and 
    ///              makes a deep copy of it.
    Queue(const Queue<T>&);

    /// @brief Assignment operator
    /// @param Queue Take in the queue on the rhs
    /// @return Deep copy of the queue to the lhs/.
    Queue<T>& operator=(const Queue<T>&);

    /// @brief Queue Destructor.
    ~Queue();

    /// @brief Returns size of queue.
    /// @return int.
    int getSize();

    /// @brief Returns a boolean if queue is empty.
    /// @return boolean.
    bool isEmpty();

    /// @brief Adds value to the queue.
    /// @param val Any type of value.
    void enqueue(T val);

    /// @brief Removes and returns the value at
    ///        the start of the queue.
    /// @return T The value at the start of the queue.
    T dequeue();

    /// @brief Returns the value at the start of the
    ///        queu but does not remove it.
    /// @return T The value at the start of the queue.
    T peek();

    /// @brief Clears the queue of all items.
    void clear();

};



#include "Queue.cpp" // Including implementation for the interface
#endif