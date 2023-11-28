//
// Created by vtang on 11/27/2023.
//

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

void BinarySearchTree::insertNode(int aVal) {
    Node* newNode = new Node(aVal);
    insert(root, newNode);
}

BinarySearchTree::Node::Node(int aVal, BinarySearchTree::Node *aLeft, BinarySearchTree::Node *aRight) {
    val = aVal;
    left = aLeft;
    right = aRight;
}

void BinarySearchTree::insert(Node* &aNodePtr, Node* &aNewNodePtr) {
    //1 check if nothing in tree, initialize root
    //2 check if val is bigger or less than, then place
    if (aNodePtr == nullptr) {
        aNodePtr = aNewNodePtr;
    }
    else if (aNodePtr->val < aNewNodePtr->val) {
        insert(aNodePtr->left, aNewNodePtr);
    }
    else {
        insert(aNodePtr->right, aNewNodePtr);
    }
}

void BinarySearchTree::deleteNode(int aVal, BinarySearchTree::Node *&aNodePtr) {
    //remove node without affecting the rest of the tree, like the root node
    //no next pointers; should be able to remove
    //finding aVal before deleting
    if (aNodePtr == nullptr) {
        std::cout << "Cannot remove empty Node" << std::endl;
    }

    else if(aVal < aNodePtr->val) {
        deleteNode(aVal, aNodePtr->left);
    }
    else if (aVal > aNodePtr->val){
        deleteNode(aVal, aNodePtr->right);
    }
    else { //else condition once we've found the value
        makeDeletion(aNodePtr);
    }
}

void BinarySearchTree::makeDeletion(Node* &aNodePtr) { //passing pointers by reference
    //1 node doesn't exist if value is null
    //copy ptr value
    Node* tempNodePtr = nullptr;

    if (aNodePtr == nullptr) {
        std::cout << "Cannot remove empty Node" << std::endl;
    }
    else if (aNodePtr->right == nullptr) {
        tempNodePtr = aNodePtr; //copy address, without reference to anything else (separate arrow pointing to node)
        //aNodePtr, is a pointer in the tree; updating aNodePtr changes the connections in the tree
        aNodePtr = aNodePtr->left; //updating the reference to the right, connects parent node to right value
        delete tempNodePtr; //delete temp copy of address, cannot delete aNodePtr, will unlink everything in tree
    }
    else if (aNodePtr->left == nullptr) { //if left side is nullptr, then take right side of tree
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    }
    else { //joining tree if node is a parent
        tempNodePtr = aNodePtr->right;
        //find left most part of tree (at node before nullptr)
        while (tempNodePtr->left) {
            tempNodePtr = tempNodePtr->left;
        }

        tempNodePtr->left = aNodePtr->left;
        tempNodePtr = aNodePtr;
        aNodePtr = tempNodePtr->right;
        makeDeletion(tempNodePtr);
        delete tempNodePtr;

    }
}

bool BinarySearchTree::searchNode(int aVal) {
    Node* currentNode = root; //start search

    while(currentNode) { //while currentNode is not null
        if (currentNode->val == aVal) {
            return true;
        }
        else if (aVal < currentNode->val) {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
    }
    return false;
}

void BinarySearchTree::remove(int aVal) {
    deleteNode(aVal, root);
}