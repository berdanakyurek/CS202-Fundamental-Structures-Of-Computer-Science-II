/*
* Title: Binary Search Trees
* Author: Berdan Akyurek
* ID: 21600904  
* Section: 2
* Assignment: 2
* Description: description of your code
*/

#include "BinaryNode.h"
#include <ios>
#include <iostream>
#include <sys/types.h>

BinaryNode::BinaryNode(int n)
{
    left = NULL;
    right = NULL;
    value = n;
}

BinaryNode::~BinaryNode()
{
}

int BinaryNode::getValue()
{
    return value;
}

BinaryNode* BinaryNode::getLeft()
{
    return left;
}

BinaryNode* BinaryNode::getRight()
{
    return right;
}

bool BinaryNode::add(int n)
{
    if(n == value)
        return false;
    else if(n > value )
    {
        if(right == NULL)
        {
            right = new BinaryNode(n);
            return true;
        }
        return right->add(n);
    }
    else
    {
        if(left == NULL)
        {
            left = new BinaryNode(n);
            return true;
        }
        return left->add(n);
    }
}

bool BinaryNode::remove(int n)
{
    if(value == n)
    {
        if( left == NULL || right == NULL)
            cout << "This should never happen." << endl;

        int ipd = inorderPredecessor();
        remove(ipd);
        value = ipd;
        return true;
    }
    else if(n > value)
    {
        if(right == NULL)
            return false;
        if(right->value == n)
        {
            if(right->left == NULL && right->right == NULL)
            {
                delete right;
                right = NULL;
                return true;
            }
            else if(right->left != NULL && right->right != NULL)
                return right->remove(n);
            else
            {
                BinaryNode* newR;// = right->right;
                if (right->right != NULL)
                    newR = right->right;
                else
                    newR = right->left;
                
                delete right;
                right = newR;
                newR = NULL;
                return true;
            }
                
        }
        return right->remove(n);
    }
    else
    {
        if(left == NULL)
            return false;
        if(left->value == n)
        {
            if(left->left == NULL && left->right == NULL)
            {
                delete left;
                left = NULL; /////////////////////
                return true;
            }
            else if(left->left != NULL && left->right != NULL)
                return left->remove(n);
            else
            {
                BinaryNode* newR;// = right->right;
                if (left->right != NULL)
                    newR = left->right;
                else
                    newR = left->left;
                delete left;
                left = newR;
                newR = NULL;
                return true;
            }
                
        }
        return left->remove(n);
    }

    return false;
}

int BinaryNode::inorderPredecessor()
{
    return left->maximum();
}

int BinaryNode::maximum()
{
    BinaryNode* current = this;
    while(current->right != NULL)
        current = current->right;
    return current->value;
}

bool BinaryNode::contains(int n )
{
    if(n == value)
        return true;
    if(n > value)
    {
        if(right == NULL)
            return false;
        return right->contains(n);
    }
    else 
    {
        if(left == NULL)
            return false;
        return left->contains(n);
    }
}

void BinaryNode::preorderTraverse()
{
    cout << value << " ";
    if(left != NULL)
        left->preorderTraverse();
    if(right != NULL)
        right->preorderTraverse();
}

void BinaryNode::inorderTraverse()
{
    if(left != NULL)
        left->inorderTraverse();

    cout << value << " ";

    if(right != NULL)
        right->inorderTraverse();
}

void BinaryNode::postorderTraverse()
{
    if(left != NULL)
        left->postorderTraverse();

    if(right != NULL)
        right->postorderTraverse();

    cout << value << " ";

}

int BinaryNode::span(int a,int b)
{
    int count = 0;
    if(value >= a && value <= b)
        count = 1;
    if(left != NULL && value > a)
        count += left->span(a,b);
    if(right != NULL && value < b)
        count += right->span(a,b);
    return count;
}

void BinaryNode::mirror()
{
    BinaryNode* temp = left;
    left = right;
    right = temp;

    if(left != NULL)
        left->mirror();
    if(right != NULL)
        right->mirror();
}

void BinaryNode::deleteEverythingBelow()
{
    if(left != NULL)
        left->deleteEverythingBelow();
    if(right != NULL)
        right->deleteEverythingBelow();

    delete left;
    delete right;
}

int BinaryNode::getHeight()
{
    int a = 0;
    int b = 0;

    if(left != NULL)
        a = left->getHeight();
    if(right != NULL)
        b = right->getHeight();
    return 1 + max(a,b);
}