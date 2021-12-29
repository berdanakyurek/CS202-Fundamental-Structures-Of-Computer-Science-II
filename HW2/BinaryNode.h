/*
* Title: Binary Search Trees
* Author: Berdan Akyurek
* ID: 21600904  
* Section: 2
* Assignment: 2
* Description: description of your code
*/
#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <iostream>

using namespace std;
class BinaryNode 
{
private:
    int value;
    BinaryNode* left;
    BinaryNode* right;

public:
    BinaryNode(int n = 0);
    ~BinaryNode();
    int getValue();
    BinaryNode* getLeft();
    BinaryNode* getRight();
    bool add(int n);
    bool remove(int n);
    int inorderPredecessor();
    int maximum();
    bool contains(int n);

    void preorderTraverse();
    void inorderTraverse();
    void postorderTraverse();
    int span(int a,int b);
    void mirror();
    void deleteEverythingBelow();
    int getHeight();
};

#endif