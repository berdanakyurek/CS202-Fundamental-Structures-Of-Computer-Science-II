/* *
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Berdan Akyurek
* ID : 21600904
* Section : 2
* Assignment : 4
* Description : Header file for hash table representation
*/

#ifndef HASH_H
#define HASH_H
#include "HashEntry.h"

class Hash
{
public:
    Hash(int cnt);
    ~Hash();
    int getIndex(string word);
    string getWord(int index);
    void add(string word, int line);
    int hashFunction(string s);


private:
    HashEntry* entries;
    string* words;
    int count;
    int size;
};
#endif