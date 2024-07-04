#include "LinkedList.h"
using namespace std;

template<typename T>
LinkedList<T>::LinkedList() : dummyHead(new Node<T>()), size(0) {}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& originalLinkedList) {
    Node<T>* curr = originalLinkedList.dummyHead->next;

    while (curr) {
        append(curr -> val);
        curr = curr -> next;
    }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& originalLinkedList) {
    this->clear();

    this->size = 0;
    this->dummyHead = new Node<T>();
    Node<T>* curr = originalLinkedList->getHead();

    while (curr) {
        this->append(curr -> val);
        curr = curr -> next;
    }

    return *this;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    this->clear();
}

template<typename T>
Node<T>* LinkedList<T>::getHead() {
    return dummyHead->next;
}

template<typename T>
void LinkedList<T>::setHead(Node<T>* node) {
    this -> dummyHead -> next = node;
}

template<typename T>
void LinkedList<T>::clear() {
    Node<T>* curr = dummyHead -> next;

    while (curr) {
        Node<T>* temp = dummyHead;
        dummyHead = dummyHead -> next;
        delete temp;
    }

    dummyHead->next = nullptr;
    this->size = 0;
}

template<typename T>
void LinkedList<T>::prepend(T val) {
    Node<T>* newNode = new Node<T>(val);
    newNode->next = dummyHead->next;
    dummyHead->next = newNode;
    size++;
}

template<typename T>
void LinkedList<T>::append(T val) {
    Node<T>* newNode = new Node<T>(val);
    Node<T>* curr = dummyHead;

    while (curr -> next) {
        curr = curr -> next;
    }

    curr -> next = newNode;
    size++;

    // Below is the recursive defination of the append function
    // Uncomment below this line and comment above the line to 
    // access the recursive defination of append

    // auto recursiveAppend = [](Node<T>* node, T val) {
    //     if (node->next == nullptr) {
    //         node -> next = new Node<T>(val);
    //     } else {
    //         recursiveAppend(node -> next, val);
    //     }
    // };

    // // Calling recursive Head starting from dummyNode
    // recursiveAppend(dummyHead, val);
    // size++;
}

template<typename T>
void LinkedList<T>::insertAt(int pos, T val) {
    if (pos < 0 || pos > size) {
        throw out_of_range("Index out of bounds");
    }

    Node<T> newNode = new Node<T>(val);
    Node<T> curr = dummyHead;

    for (int i = 0; i < pos; i++) {
        curr = curr -> next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    size++;
}

template<typename T>
T LinkedList<T>::pop(int idx /* = -1 */) {
    if (isEmpty()) return T();

    if (idx < -1 || idx >= size) {
        throw out_of_range("Index out of bounds");
    }

    if (idx == -1){
        idx = size - 1;
    }

    Node<T>* curr = dummyHead;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }

    Node<T>* temp = curr -> next;
    curr -> next = temp -> next;
    size--;
    return temp->val;
}

template<typename T>
T LinkedList<T>::peekFront() {
    return dummyHead -> next -> val;
}

template<typename T>
bool LinkedList<T>::find(T val) {
    Node<T>* curr = dummyHead -> next;

    while (curr) {
        if (curr -> val == val) {
            return true;
        }
        curr = curr -> next;
    }
    return false;
}

template<typename T>
int LinkedList<T>::getSize() {
    return size;
}

template<typename T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}