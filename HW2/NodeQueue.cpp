/*
* Title: Binary Search Trees
* Author: Berdan Akyurek
* ID: 21600904  
* Section: 2
* Assignment: 2
* Description: description of your code
*/

#include "NodeQueue.h"
#include "BinaryNode.h"

NodeQueue::NodeQueue()
{
    size = 100;
    noOfElements = 0;
    q = new BinaryNode*[size];
}

NodeQueue::~NodeQueue()
{
    delete[]q;
}

BinaryNode* NodeQueue::dequeue()
{
    BinaryNode* first = q[0];

    for(int i = 0; i < noOfElements-1; i ++)
        q[i] = q[i+1];
    q[noOfElements-1] = NULL;
    noOfElements --;
    return first;
}

void NodeQueue::enqueue(BinaryNode* n)
{
    if(noOfElements == size)
    {
        BinaryNode** newArr = new BinaryNode*[size+100];
        for(int i = 0; i < noOfElements; i ++)
            newArr[i] = q[i];
        delete[] q;
        q = newArr;
        size += 100;
    }
    q[noOfElements] = n;
    noOfElements ++; 

}

bool NodeQueue::isEmpty()
{
    if(noOfElements == 0)
        return true;
    return false;
}