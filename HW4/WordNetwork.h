/* *
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Berdan Akyurek
* ID : 21600904
* Section : 2
* Assignment : 4
* Description : Top class for necessary functions
*/

#ifndef WORDNETWORK_H
#define WORDNETWORK_H


//#include <string>

#include "Hash.h"

class WordNetwork 
{
public:
    WordNetwork(const string vertexFile, const string edgeFile);
    ~WordNetwork();
    void listNeighbors(const string word);
    void listNeighbors(const string word, const int distance);
    void listConnectedComponents();
    void findShortestPath(const string word1, const string word2);

private:
    Hash* hashTable;
    bool** adjMatrix;
    int wordCount; 
    int findWord(const string word);
    void listNeighborsHelper(const int index, const int goalDist, const int depth, bool* array);
    bool containsFalse(bool* array);
    void listAllReachable(const int index, bool* array);
};

#endif