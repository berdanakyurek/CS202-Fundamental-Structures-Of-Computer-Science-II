/* *
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Berdan Akyurek
* ID : 21600904
* Section : 2
* Assignment : 4
* Description : Implementation of hash table
*/

#include "Hash.h"
//#include "HashEntry.h"

Hash::Hash(int cnt)
{
    size = 10;
    entries = new HashEntry[size];
    words = new string[cnt];
    count = 0;
}

Hash::~Hash()
{
    delete[] entries;
    delete[] words;
}

int Hash::getIndex(string word)
{
    HashEntry ent = entries[hashFunction(word)];

    for(int i = 0; i < ent.getNoOfElems(); i ++)
    {
        if(ent.get(i).getWord() == word)
            return ent.get(i).getInd();
    }
    return -1;
}

string Hash::getWord(int index)
{
    return words[index];
}

void Hash::add(string word, int line)
{
    entries[hashFunction(word)].add(word, line);
    words[count] = word;
    count ++;
}

int Hash::hashFunction(string s)
{
    int hashVal = 0; 
    for (unsigned int i = 0; i < s.length(); i++)
	    hashVal = 37 * hashVal + s[i];
 
    hashVal %=size; 
    if (hashVal < 0)
	    hashVal += size; 

    return hashVal; 	
}