/* *
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Berdan Akyurek
* ID : 21600904
* Section : 2
* Assignment : 4
* Description : Implementation of data
*/

#include "HashNode.h"

HashNode::HashNode( std::string s, int i)
{
    index = i;
    word = s;
}

string HashNode::getWord()
{
    return word;
}

int HashNode::getInd()
{
    return index;
}