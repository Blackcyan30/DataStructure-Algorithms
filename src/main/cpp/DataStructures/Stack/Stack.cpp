# include "Stack.h"
template<typename T>
Stack<T>::Stack() : top(nullptr), size(0) {}

template<typename T>
Stack<T>::Stack(const Stack<T>& originalStack) {
    if (originalStack.size == 0) {
        this->size = 0;
        this->top = nullptr;
    } else {
        Node<T>* temp = originalStack.top;
        T* values = new T[originalStack.size];
        int idx = 0;

        while (temp != nullptr) {
            values[idx++] = temp->val;
            temp = temp->next;
        }

        for (int i = idx - 1; i >= 0; i--) {
            push(values[i]);
        }

        delete[] values;
    }
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& originalStack) {
    this->clear();

    if (originalStack.size == 0) {
        this->size = 0;
        this->top = nullptr;
    } else {
        Node<T>* temp = originalStack.top;
        T* values = new T[originalStack.size];
        int idx = 0;

        while (temp != nullptr) {
            values[idx++] = temp->val;
            temp = temp->next;
        }

        for (int i = idx - 1; i >= 0; i--) {
            this->push(values[i]);
        }

        delete[] values;
    }
    return *this;
}

template<typename T>
Stack<T>::~Stack() {
    this->clear();
}

template<typename T>
int Stack<T>::getSize() {
    return this->size;
}

template<typename T>
bool Stack<T>::isEmpty(){
    return this->size == 0;
}

template<typename T>
void Stack<T>::push(T val) {
    Node<T>* newNode = new Node<T>(val);
    newNode->next = top;
    top = newNode;
    size++;
}

template<typename T>
T Stack<T>::pop() {
    if (this->isEmpty()) {
        throw out_of_range("Stack is empty");
    } else {
        Node<T>* temp = top;
        T toRet = temp->val;
        top = top->next;
        delete temp;
        size--;
        return toRet;
    }
}

template<typename T>
T Stack<T>::peek() {
    if (this->isEmpty()) {
        throw out_of_range("Stack is empty");
    }

    return top->val;
}

template<typename T>
void Stack<T>::clear() {
    while(top != nullptr) {
        Node<T>* temp = top;
        top = top->next
        delete temp;
    }
    this->size = 0;
}

