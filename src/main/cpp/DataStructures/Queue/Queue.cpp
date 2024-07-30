#include "Queue.h"

template<typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
int Queue<T>::getSize() {
    return this -> size;
}

template<typename T>
void Queue<T>::enqueue(T val) {
    Node<T>* newNode = new Node<T>(val);
    
    // If queue is empty
    if (this->size == 0 && head == nullptr) {
        head = newNode;
        tail = newNode;
    // Queue is not empty
    } else {
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
    size++;
}

template<typename T>
T Queue<T>::dequeue() {
    T toRet = head->val;

    if (size == 1) {
        delete head;
        delete tail;
        return toRet;
    }

    Node<T>* toDel = head;

    head = head -> next;
    head -> prev = nullptr;

    delete toDel;
    return toRet;
}

template<typename T>
T Queue<T>::peek() {
    if (head != nullptr) {
        return head -> val;
    } else {
        throw out_of_range("Queue is empty!")
    }
}

template<typename T>
bool Queue<T>::isEmpty() {
    return this->size == 0;
}

template<typename T>
void Queue<T>::clear() {
    while (head != nullptr) {
        Node<T>* toDel = head;
        head = head -> next;
        delete toDel;
    }
    this -> head = nullptr;
    this -> tail = nullptr;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other) {
    Node<T>* curr = other.head;
    while (curr) {
        this -> enqueue(curr -> val);
        curr = curr -> next;
    }
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs) {
    this -> clear();
    Node<T>* curr = rhs.head;
    while (curr) {
        this -> enqueue(curr -> val);
        curr = curr -> val;
    }

    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    this -> clear();
}