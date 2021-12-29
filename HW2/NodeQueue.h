/*
* Title: Binary Search Trees
* Author: Berdan Akyurek
* ID: 21600904  
* Section: 2
* Assignment: 2
* Description: description of your code
*/

#ifndef NODEQUEUE_H
#define NODEQUEUE_H

#include "BinaryNode.h"
class NodeQueue
{
private:
    BinaryNode** q;
    int size;
    int noOfElements;
public:
    NodeQueue();
    ~NodeQueue();
    BinaryNode* dequeue();
    void enqueue(BinaryNode* n);
    bool isEmpty();

};

#endif