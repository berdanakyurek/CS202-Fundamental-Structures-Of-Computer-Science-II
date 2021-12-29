/* *
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Berdan Akyurek
* ID : 21600904
* Section : 2
* Assignment : 4
* Description : Header file for data stored in hash table
*/

#ifndef HASHNODE_H
#define HASHNODE_H

#include <iostream>
#include <fstream>
using namespace std;

class HashNode
{
    public:
        HashNode(string s= "", int i= -1);
        string getWord();
        int getInd();
    private:
        int index;
        string word;

};

#endif