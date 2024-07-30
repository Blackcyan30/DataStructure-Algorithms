#include "DoublyLinkedList.h"

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(NULL), tail(NULL), size(0) {}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& originalList) {
    Node<T>* curr = originalList.head;

    while (curr) {
        append(curr.val);
        curr = curr -> next;
    }
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() {
    return size == 0 && head == nullptr;
}

template<typename T>
int DoublyLinkedList<T>::getSize() {
    return this -> size;
}

template<typename T>
void DoublyLinkedList<T>::append(T val) {
    Node<T>* newNode = new Node<T>(val);

      // Case where head is null and inserting
      // the first element in the linked list.
    if (head == nullptr) {
        this -> head = newNode;
        this -> tail = newNode;

      // Case where head is not null and inserting
      // at the end of the linked list.
    } else {
        this -> tail -> next = newNode;
        newNode -> prev = tail;
        this -> tail = newNode;
    }
    this->size++;
}

template<typename T>
void DoublyLinkedList<T>::prepend(T val) {
    Node<T>* newNode = new Node<T>(val);

    newNode -> next = this -> head;
    this -> head = newNode;
    if (tail == NULL) {
        tail = newNode;
    }
    size++;
}

template<typename T>
void DoublyLinkedList<T>::insertAt(int idx, T val) {
    if (idx > 0 || idx <= this->size) {
        throw out_of_range("Index is out of bounds");
    }

    Node<T>* newNode = new Node<T>(val);

    // Case 1: If index to insert is 0.
    if (idx == 0) {
           // If Inserting into an empty list.
        if (head == nullptr) {
            this -> head = newNode;
            this -> tail = newNode;
        } else {
            this -> head -> prev = newNode;
            newNode -> next = head;
            this -> head = newNode;
        }

    // Insertion at the head.
    } else if (idx == this -> size) {
        this -> tail -> next = newNode;
        newNode -> prev = this -> tail;
        this -> tail = newNode;

    } else {
        Node<T>* curr = this -> head;

        for (int i = 0; i < idx - 1; i++) {
            curr = curr -> next;
        }

        newNode -> next = curr -> next;
        curr -> next -> prev = newNode;
        newNode -> prev = curr;
        curr -> next = newNode;
    }

    this->size++;
}

template<typename T>
T DoublyLinkedList<T>::pop(int idx = -1) {
    if (idx >= size || idx < -1) {
        throw out_of_range("Index out of range. Please enter a valid index.");
    }

    if (idx == 0) {

        // Case when there is only one node in the list.
        if (size == 1) {
            Node<T>* temp = this->head;
            head = nullptr;
            tail = nullptr;
            delete temp;
        
        // Case when there is more than one node in the list.
        } else {
            Node<T>* temp = head;
            head = head -> next;
            head -> prev = nullptr;
            delete temp;
        }

    } else if (idx == size - 1) {
        Node<T>* temp = tail;
        tail = tail -> prev;
        tail -> next = nullptr;
        delete temp;

    } else {
        Node<T>* curr = head;
        for (int i = 0; i < size - 1; i++) {
            curr = curr -> next;
        }

        Node<T>* temp = curr -> next;
        curr -> next -> next -> prev = curr;
        curr -> next = curr -> next -> next;
        delete temp;
    }

    size--;
}

template<typename T>
bool DoublyLinkedList<T>::find(T val) {
    Node<T>* curr = head;
    while (curr) {
        if (curr -> val == val) {
            return true;
        }
        curr = curr -> next;
    }
    return false;
}

template<typename T>
T DoublyLinkedList<T>::peekFront() {
    if (size == 0 && head == nullptr) {
        throw range_error("List is empty.")
    }
    return this->head -> val;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head -> next;
        delete temp;
    }
    this -> head = nullptr;
    this -> tail = nullptr;
}

template<typename T>
void DoublyLinkedList<T>::printList() {
    function<void(Node<T>*)> printRecursively = [&](Node<T>* node) -> void {
        if (node == nullptr) {
            return;
        }

        cout << node -> val << " ";
        printRecursively(node -> next);
    };
    printRecursively(head);
    cout << endl;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    this -> clear();
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& originalList) {
    this -> clear();

    Node<T>* curr = originalList.head;
    while (curr) {
        this -> append(curr -> val);
        curr = curr -> next;
    }

    return *this;
}