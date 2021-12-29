/*
* Title: Heaps
* Author: Berdan Akyurek
* ID: 21600904
* Section: 2
* Assignment: 3
* Description: A single node of the heap
*/

#include "Node.h"

Node::Node(int idA, int priorityA, int comingTimeA, int processTimeA )
{
    p = Process(idA, priorityA, comingTimeA, processTimeA);
    left = NULL;
    right = NULL;
}

Node::Node(Process pp)
{
    p = pp;
    left = NULL;
    right = NULL;
}

Node::~Node()
{
    delete left;
    delete right;
}

int Node::getID()
{
    return p.getID();
}

int Node::getPriority()
{
    return p.getPriority();
}

int Node::getComingTime()
{
    return p.getComingTime();
}

int Node::getProcessTime()
{
    return p.getProcessTime();
}

Node* Node::getLeft()
{
    return left;
}

Node* Node::getRight()
{
    return right;
}

int Node::smallestInsertableLevel()
{
    if(left == NULL || right == NULL)
        return 2;
    return min(left->smallestInsertableLevel(), right->smallestInsertableLevel()) + 1;
}

void Node::insertEnd(int id, int priority, int comingTime, int processTime)
{
    
    if(left == NULL)
    {
        left = new Node(id, priority, comingTime, processTime);
        return;
    }
    if(right == NULL)
    {
        right = new Node(id, priority, comingTime, processTime);
        return;  
    }

    if(left->smallestInsertableLevel() > right->smallestInsertableLevel())
        right->insertEnd(id, priority, comingTime, processTime);
    else
        left->insertEnd(id, priority, comingTime, processTime);
}

void Node::insertEnd(Process p)
{
    if(left == NULL)
    {
        left = new Node(p);
        return;
    }
    if(right == NULL)
    {
        right = new Node(p);
        return;  
    }

    if(left->smallestInsertableLevel() > right->smallestInsertableLevel())
        right->insertEnd(p);
    else
        left->insertEnd(p);
}

void Node::add(int id, int priority, int comingTime, int processTime)
{
    insertEnd(id, priority, comingTime, processTime);
    heapify();
}

void Node::add(Process p)
{
    insertEnd(p);
    heapify();
}

int Node::height()
{
    if(left == NULL && right == NULL)
        return 1;

    if(left == NULL)
        return right->height() + 1;

    if(right == NULL)
        return left->height() + 1 ;

    return max(left->height(), right->height()) + 1;

}

Node* Node::getLast()
{
    if(left == NULL && right == NULL)
        return this;
    if(left != NULL and right == NULL)
        return left;
    
    int lh = left->height();
    int rh = right->height();

    if(lh == rh)
        return right->getLast();
    return left->getLast();

}

Node* Node::getParentOfLast()
{
    if(right == NULL)
        return this;
    int lh = 0;
    int rh = 0;

    if(left != NULL)
        lh = left->height();
    if(right != NULL)
        rh = right->height();

    if(lh == rh && right != NULL)
        return right->getParentOfLast();
    return left->getParentOfLast();
}

bool Node::deleteLast()
{
    if(left == NULL && right == NULL)
        return false;
    
    if(right == NULL)
    {
        delete left;
        left = NULL;
        return true;
    }

    if(left->height() == right->height())
    {
        if(left->left == NULL)
        {
            delete right;
            right = NULL;
            return true;
        }
        else
        {
            return right->deleteLast();
        }
    }
    return left->deleteLast();
        

    return true;
}

bool Node::remove()
{
    if(height() == 1)
        return false;

    Node* last = getLast();

    p = last->p;

    deleteLast();
    heapify();
    return true;
    
}

void Node::heapify()
{
    if(left != NULL)
        left->heapify();
    if(right != NULL)
        right->heapify();
    
    if(left == NULL)
        return;
    
    if(right == NULL)
    {
        if(p.getPriority() > left->p.getPriority())
            return;

        if(p.getPriority() == left->p.getPriority() && p.getComingTime() <= left->p.getComingTime() )
            return;

        Process temp = left->p;
        left->p = p;
        p = temp;
        left->heapify();

        return;
    }

    // left is more prior
    if(left->p.getPriority() > right->p.getPriority() || ((left->p.getPriority() == right->p.getPriority()) && left->p.getComingTime() <= right->p.getComingTime()) )
    {
        if(left->p.getPriority() > p.getPriority() || ((left->p.getPriority() == p.getPriority()) && left->p.getComingTime() <= p.getComingTime()) )
        {
            Process temp = left->p;
            left->p = p;
            p = temp;
            left->heapify();
        }
        else
            return;
    }
    else
    {
        if(right->p.getPriority() > p.getPriority() || ((right->p.getPriority() == p.getPriority()) && right->p.getComingTime() <= p.getComingTime()) )
        {
            Process temp = right->p;
            right->p = p;
            p = temp;
            right->heapify();
        }
        else
            return;
    }

}

Process Node::getP()
{
    return p;
}

void Node::preorderTraverse()
{
    cout << p.getPriority() << " ";
    if(left != NULL)
        left->preorderTraverse();
    if(right != NULL)
        right->preorderTraverse();
}