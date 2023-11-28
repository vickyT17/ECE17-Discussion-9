//
// Created by vtang on 11/27/2023.
//

#ifndef DI9_BINARYSEARCHTREE_H
#define DI9_BINARYSEARCHTREE_H
#include <iostream>

class BinarySearchTree {
private:
    struct Node {
        int val;
        Node* left;
        Node* right;

        Node(int aVal, Node* aLeft = nullptr, Node* aRight = nullptr);
    };

    Node* root;

private:
    void insert(Node* &aNodePtr, Node* &aNewNodePtr);

    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);

public:
    BinarySearchTree();
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);

    void displayInOrder(Node* aNodePtr){
        if (aNodePtr) {
            displayInOrder(aNodePtr->left);
            std::cout << aNodePtr->val << " ";
            displayInOrder(aNodePtr->right);
        }
    }

    void printTree(){
        displayInOrder(root);
        std::cout << std::endl;
    };
};


#endif //DI9_BINARYSEARCHTREE_H
