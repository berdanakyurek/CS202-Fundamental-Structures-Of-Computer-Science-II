/* *
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Berdan Akyurek
* ID : 21600904
* Section : 2
* Assignment : 4
* Description : Implementation of each hash index
*/

#include "HashEntry.h"
#include "HashNode.h"

HashEntry::HashEntry()
{
    noOfElems = 0;
    arraySize = coef;
    
    array = new HashNode[arraySize];
}

HashEntry::~HashEntry()
{
    //delete [] array;
}

void HashEntry::add(const string s, const int ind)
{
    HashNode nw(s, ind);
    if(noOfElems < arraySize)
    {
        
        array[noOfElems] = nw;
        noOfElems ++;
    }
    else 
    {
        HashNode* temp = new HashNode[arraySize+coef];
        for(int i = 0; i < arraySize; i ++)
            temp[i] = array[i];
        delete[] array;
        
        temp[arraySize] = nw;
        noOfElems ++;
        arraySize += coef;
        array = temp;
    }
}

HashNode HashEntry::get(const int index)
{
    return array[index];
}

int HashEntry::getNoOfElems()
{
    return noOfElems;
}