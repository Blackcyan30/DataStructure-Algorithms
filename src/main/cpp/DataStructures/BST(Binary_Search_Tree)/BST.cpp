#include"BST.h"
/// @implements


template<typename T>
BinarySearchTree<T>::BinarySearchTree(function<bool(const T&, const T&)> comp) : root(nullptr), comparator(comp), size(0){}

template<typename T>
void BinarySearchTree<T>::insert(T val) {
    
    function<void(Node<T>*& node, T val)> insertNode = [&](Node<T>*& node, T val) -> void {
        // Reached end of tree and node is null therefore add node here.
        if (node == nullptr) {
            node = new Node<T>(val);
            this -> size++;

        // Value is smallr then current value therefore add to
        // the left subtree.
        } else if (comparator(val, node->val)) {
            insertNode(node->left, val);

        // Value is greater then current value therefore add to
        // the right subtree
        } else if (comparator(node->val, val)) {
            insertNode(node->right, val);
        
        // Case when value exists therefore do not add.
        } else {
            return;
        }
    };

    insertNode(this->root, val);
}

template<typename T>
T BinarySearchTree<T>::remove(T val) {

    function<T(Node<T>*& node, T val)> removeRecursive = [&](Node<T>* node, T val) -> T {
        if (node->val == val) {
            // Remove val and adjust according to the 3 cases of removal.

            this->size--;
        // Value to remove is less then current node value.
        } else if (this->comparator(val, node->val)) {
            removeRecursive(node->left, val);
        
        // Value to remove is greater then the current node value
        } else if (this->comparator(node->val, val)) {
            removeRecursive(node->right, val);
        }
        throw out_of_range("Value does not exist in tree.");
    };

    return removeRecursive(this->root, val);
}


template<typename T>
int BinarySearchTree<T>::getSize() {
    return this->size;
}

template<typename T>
bool BinarySearchTree<T>::isEmpty() {
    return this->size == 0;
}

template<typename T>
void BinarySearchTree<T>::printInorder() {
    
    function<void(Node<T>*)> printRecursive = [&](Node<T>* root) -> void {
        if (root == nullptr) {
            return;
        }

        printRecursive(root->left);
        cout << root->val << " ";
        printRecursive(root->right);
    };
    
    printRecursive(root);
    cout << endl;
}

template<typename T>
void BinarySearchTree<T>::printPostorder() {

    function<void(Node<T>*)> printRecursive = [&](Node<T>* root) -> void {
        if (root == nullptr) {
            return;
        }
        
        printRecursive(root->left);
        printRecursive(root->right);
        cout << root->val << " ";
    };

    printRecursive(root);
    cout << endl;
}

template<typename T>
void BinarySearchTree<T>::printPreorder() {
    
    function<void(Node<T>*)> printRecursive = [&](Node<T>* node) -> void {
        if (node == nullptr) {
            return;
        }

        cout << node->val << " ";
        printRecursive(node->left);
        printRecursive(node->right);
    };

    printRecursive(root);
    cout << endl;
}