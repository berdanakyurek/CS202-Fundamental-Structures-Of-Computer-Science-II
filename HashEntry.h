/* *
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Berdan Akyurek
* ID : 21600904
* Section : 2
* Assignment : 4
* Description : Header file of each hash index
*/

#ifndef HASHENTRY_H
#define HASHENTRY_H

#include "HashNode.h"

class HashEntry
{
public:
    HashEntry();
    ~HashEntry();
    void add(const string s, const int ind);
    HashNode get(const int index);
    int getNoOfElems();
private:
    HashNode* array;
    int arraySize;
    int noOfElems;
    int coef = 10;

};

#endif