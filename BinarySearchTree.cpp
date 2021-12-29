/*
* Title: Binary Search Trees
* Author: Berdan Akyurek
* ID: 21600904  
* Section: 2
* Assignment: 2
* Description: description of your code
*/

#include "BinarySearchTree.h"
#include "BinaryNode.h"
#include "NodeQueue.h"


BinarySearchTree::BinarySearchTree()
{
    head = NULL;
    numOfNodes = 0;
}

BinarySearchTree::~BinarySearchTree()
{
    head->deleteEverythingBelow();
    delete head;
}

bool BinarySearchTree::isEmpty()
{
    if(numOfNodes > 0 )
        return false;
    return true;
}

int BinarySearchTree::getHeight()
{
    if(head == NULL)
        return 0;
    cout << "here" << endl;
    return head->getHeight();
}

int BinarySearchTree::getNumberOfNodes()
{
    return numOfNodes;
}

bool BinarySearchTree::add(const int newEntry)
{
    if(head == NULL)
    {
        head = new BinaryNode(newEntry);
        numOfNodes ++;
        return true;
    }
    bool result = head->add(newEntry);
    if(result)
        numOfNodes ++;
    return result;
}

bool BinarySearchTree::remove(const int anEntry)
{
    if(head == NULL)
        return false;

    if(head->getValue() == anEntry && (head->getLeft() == NULL || head->getRight() == NULL))
    {
        if(head->getLeft() == NULL && head->getRight() == NULL )
        {
            numOfNodes = 0;
            delete head;
            head = NULL;
            return true;
        }
        else if (head->getLeft() == NULL)
        {
            BinaryNode* newHead = head->getRight();
            delete head;
            head = newHead;
            numOfNodes --;
            return true;
        }
        else if (head->getRight() == NULL)
        {
            BinaryNode* newHead = head->getLeft();
            delete head;
            head = newHead;
            numOfNodes --;
            return true;
        }
    }
    
    bool result = head->remove(anEntry);
    if(result)
        numOfNodes --;
    return result;
}

bool BinarySearchTree::contains(const int anEntry)
{
    if(head == NULL)
        return false;
    return head->contains(anEntry);
}

void BinarySearchTree::preorderTraverse()
{
    if(!isEmpty())
    {
        head->preorderTraverse();
        cout << endl;
    }
}

void BinarySearchTree::inorderTraverse()
{
    if(!isEmpty())
    {
        head->inorderTraverse();
        cout << endl;
    }
}

void BinarySearchTree::postorderTraverse()
{
    if(!isEmpty())
    {
        head->postorderTraverse();
        cout << endl;
    }
}

void BinarySearchTree::levelorderTraverse()
{
    if(isEmpty())
        return;

    NodeQueue q1;
    q1.enqueue(head);

    while(!q1.isEmpty())
    {
        BinaryNode* elem = q1.dequeue();
        cout << elem->getValue() << " ";
        if(elem->getLeft() != NULL)
            q1.enqueue(elem->getLeft());
        if(elem->getRight() != NULL)
            q1.enqueue(elem->getRight());
    }
    cout << endl;
}

int BinarySearchTree::span(const int a, const int b)
{
    if(isEmpty())
        return 0;
    return head->span(a,b);
}

void BinarySearchTree::mirror()
{
    if(!isEmpty())
        head->mirror();
}