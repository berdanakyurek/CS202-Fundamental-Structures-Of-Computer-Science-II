/*
* Title: Binary Search Trees
* Author: Berdan Akyurek
* ID: 21600904  
* Section: 2
* Assignment: 2
* Description: description of your code
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryNode.h"

class BinarySearchTree 
{
private:
    BinaryNode* head;
    int numOfNodes;
public: 
    BinarySearchTree();
    ~BinarySearchTree();
    
    bool isEmpty();
    int getHeight();
    int getNumberOfNodes();
    
    bool add(const int newEntry);
    bool remove(const int anEntry);
    bool contains(const int anEntry);
    void preorderTraverse();
    void inorderTraverse();
    void postorderTraverse();
    void levelorderTraverse();
    int span(const int a, const int b);
    void mirror();
};

#endif