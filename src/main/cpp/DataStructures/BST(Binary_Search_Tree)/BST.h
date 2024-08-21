/// @file @headerfile BST.h
/// @author M. Talha Adnan Khan
/// @date Aug 11, 2024
/// @include This file has the dependency of the Node class for the
/// BST, and also the .cpp file for the implementation of the functions.
/// @tableofcontents This file contains the blueprint/interface of a 
/// Binary Search Tree(BST).
/// @brief This is the header file for the BST and contains all the function
/// prototypes and details on how the function should work
/// @details This file is created to mimic a Binary Search Tree (BST) for any type of data.
/// When initializing the user needs to define the data type for the linked list,
/// the same way you do when initializing a vector. If the data type is complex/non-primitive
/// the user also needs to pass in a function from the to the constructor inorder to set the
/// method of comparison for the data type so the BST correctly knows how to insert
/// or do other operations on the data in the BST.
/// @note Implementation of this file is in a separate BST.cpp file.

#ifndef BST_H
#define BST_H
#include "Node.h"
#include<stdexcept>
#include<functional>
#include<iostream>
using namespace std;

template<typename T>
class BinarySearchTree {
private:
    Node<T>* root;
    function<bool(const T&, const T&)> comparator;
    int size;

public:

    /// @brief BinarySearchTree Constructor.
    /// @param comparator 
    BinarySearchTree(function<bool(const T&, const T&)> comparator = less<T>());

    /// @brief Copy Constructor.
    /// @param BinarySearchTree BST to copy.
    BinarySearchTree(const BinarySearchTree&);

    /// @brief Assignment operator
    /// @param BinarySearchTree Takes in the orginal BST on the rhs.
    /// @return Deep copy of the BST to the lhs.
    BinarySearchTree<T>& operator=(const BinarySearchTree&);

    /// @brief Destructor.
    // ~BinarySearchTree();

    /// @brief This function inserts a node
    /// at the correct place in the BST.
    /// @param val Generic type to be inserted.
    /// @details TODO: Explain how the function works. (Does not insert if elem already present.)
    /// @note TODO: Explain Time and space complexity.
    void insert(T val);

    /// @brief This function deletes the node corresponding
    /// with the value given by the user.
    /// @param val Generic type to be removed.
    /// @return Generic type that was removed
    /// @details TODO: Explain how the function works
    /// @note TODO: Explain the time and space complexity.
    T remove(T val);

    /// @brief Returns the size of the BST.
    /// @return Integer.
    int getSize();

    /// @brief Tell you if the BST is empty of not?
    /// @return Boolean.
    bool isEmpty();

    /// @brief Cleans the BST of all values.
    void clear();

    /// @brief Prints all the values traversing the
    /// BST inorder.
    void printInorder();

    /// @brief Prints all the values traversing the
    /// BST postorder.
    void printPostorder();

    /// @brief Prints all the values traversing the
    /// BST preorder.
    void printPreorder();

    /// @brief Returns the minimum value in the BST
    /// in accordance with the comparison.
    /// @param remove A boolean to specify if to remove
    /// the minimum value or just return it.
    /// @return Generic type.
    T getMinValue(bool remove);

    /// @brief Returns the maximum value in the BST
    /// inaccordance with the comaprison.
    /// @param remove A boolean to specify if to remove
    /// the maximum value or just return it.
    /// @return Generic type.
    T getMaxValue(bool remove);
};




#include "BST.cpp"
#endif