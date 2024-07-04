#ifndef STACK_H
#define STACK_H

# include "Node.h"
# include <stdexcept>
using namespace std;
template<typename T>
class Stack {
    private:
        Node<T>* top;
        int size;
        Node<T>* getTop();
        
    public:
        
        /// @brief Constructor.
        Stack();

        /// @brief Copy constructor.
        /// @param Stack Takes in the original stack and
        ///              makes a deep copy of it.
        Stack(const Stack<T>&);

        /// @brief Assignment operator.
        /// @param Stack Takes in the stack on the rhs
        /// @return Deep copy of stack to the lhs
        Stack<T>& operator=(const Stack<T>&);

        /// @brief Stack Destructor.
        ~Stack();

        /// @brief returns the size of the stack
        /// @return int
        int getSize();

        /// @brief Returns a boolean if stack empty?
        /// @return boolean
        bool isEmpty();

        /// @brief Pushes a value to the top of the stack.
        /// @param val Any type of value
        void push(T val);

        /// @brief Removes and returns the top value of
        ///        the stack.
        /// @return T The value at the top of stack.
        T pop();

        /// @brief Returns the top value of the stack
        ///        but does not remove it.
        /// @return T The value at the top of stack.
        T peek();

        /// @brief Clears the stack of all items.
        void clear();

};

#include "Stack.cpp"

#endif