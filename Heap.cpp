/*
* Title: Heaps
* Author: Berdan Akyurek
* ID: 21600904
* Section: 2
* Assignment: 3
* Description: Priority heap for Process Objects
*/

#include "Heap.h"

Heap::Heap()
{
    head = NULL;
    size = 0;
}

Heap::~Heap()
{
    if(head != NULL)
        delete head;
}

Node* Heap::getHead()
{
    return head;
}

bool Heap::add(int idA, int priorityA, int comingTimeA, int processTimeA)
{
    size += 1;
    if(head == NULL)
    {
        head = new Node(idA, priorityA, comingTimeA, processTimeA);
        return true;
    }
    head->add(idA, priorityA, comingTimeA, processTimeA);
    return true;
}

bool Heap::add(Process p)
{
    size += 1;
    if(head == NULL)
    {
        head = new Node(p);
        return true;
    }
    head->add(p);
    return true;
}

bool Heap::remove()
{
    if(head == NULL)
        return false;
    
    size -= 1;
    if(head->remove())
        return true;
    delete head;
    head = NULL;
    return true;
        
}

bool Heap::isEmpty()
{
    if(size == 0)
        return true;
    return false;
}

Process Heap::getHeadProcess()
{
    if(head != NULL)
        return head->getP(); 
    return Process(-1,-1,-1,-1);
}

void Heap::preorderTraverse()
{
    if(head != NULL)
        head->preorderTraverse();
    
}

int Heap::getSize()
{
    return size;
}
