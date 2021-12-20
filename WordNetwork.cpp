/* *
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Berdan Akyurek
* ID : 21600904
* Section : 2
* Assignment : 4
* Description : Header file for top class
*/

#include "WordNetwork.h"
#include "Hash.h"
#include <fstream>

WordNetwork::WordNetwork(const string vertexFile, const string edgeFile)
{
    // Count words
    wordCount = 0;
    string line;
    ifstream file(vertexFile);
    

    while (getline(file, line))
        wordCount ++;

    hashTable = new Hash(wordCount);

    ifstream file2(vertexFile);

    // Get words to dictionary
    for(int i = 0; i < wordCount; i ++)
    {
        getline(file2, line);
        hashTable->add(line, i);
    }

    // Create and initialize adjecency matrix
    adjMatrix = new bool*[wordCount];
    for(int i = 0; i < wordCount; i ++)
    {
        adjMatrix[i] = new bool[wordCount];

        for(int j = 0; j < wordCount; j ++ )
            adjMatrix[i][j] = false;
    }

    // Read data and construct adjecency matrix
    
    ifstream edges(edgeFile);
    while(getline(edges, line))
    {
        string word1 = "";
        string word2 = "";

        bool flag = false;

        for(unsigned int i = 0; i < line.length(); i++)
        {
            if(line.at(i) == ',')
            {
                flag = true;
                continue;
            }

            if(!flag)
                word1 += line.at(i);
            else
                word2 += line.at(i);
        }

        int index1 = findWord(word1);
        int index2 = findWord(word2);

        if(index1 == -1 || index2 == -1)
        {
            cout << "Invalid data" << endl;
        }
        else
        {
            adjMatrix[index1][index2] = true;
            adjMatrix[index2][index1] = true; 
        }
    }
    
}

WordNetwork::~WordNetwork()
{

    for(int i = 0; i < wordCount; i ++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
    delete hashTable;
}

void WordNetwork::listNeighbors(const string word)
{
    listNeighbors(word, 1);
}

void WordNetwork::listNeighbors(const string word, const int distance)
{
    if(distance == 1)
        cout << "Neighbors of " << word <<":" << endl;
    else
        cout << "Neighbors of " << word << " with distance " << distance <<":" << endl;
    int index = findWord(word);
    if(index == -1)
    {
        cout << "Word does not exist!" << endl;
        return;
    }
    bool* array = new bool[wordCount];
    for(int i = 0; i < wordCount; i ++)
        array[i] = false;

    listNeighborsHelper(index, distance, 0, array );
    delete[] array;
        
}

void WordNetwork::listConnectedComponents()
{
    bool* array = new bool[wordCount];
    int componentNo = 1;
    for(int i = 0; i < wordCount; i ++)
        array[i] = false;
    
    while(containsFalse(array))
    {
        for(int i = 0; i < wordCount; i ++)
            if(array[i] == false)
            {
                cout << "Connected component " << componentNo << ":" << endl;
                componentNo ++;
                listAllReachable(i, array);
            }
                
    }

    delete[] array;
}

void WordNetwork::findShortestPath(const string word1, const string word2)
{
    int index1 = findWord(word1);
    int index2 = findWord(word2);

    bool isVisited[wordCount];
    
    for(int i = 0; i < wordCount; i ++)
        isVisited[i] = false;
    
    int distances[wordCount];

    for(int i = 0; i < wordCount; i ++)
        distances[i] = 99999;
    
    distances[index1] = 0;
    int currentNode = index1;

    do 
    {
        for(int i = 0; i < wordCount; i ++)
        {
            if(currentNode != i && isVisited[i] == false && adjMatrix[currentNode][i] == true)
            {
                if(distances[currentNode] + 1 < distances[i])
                    distances[i] = distances[currentNode] + 1;
            }
                
        }
        isVisited[currentNode] = true;

        bool hasUnvisited = false;
        for(int i = 0; i < wordCount; i ++)
            if(isVisited[i] == false)
                hasUnvisited = true;
        
        //for(int i = 0; i < 30; i ++)
        //    cout << isVisited[i] << " ";
        //cout << endl;
        if(!hasUnvisited)
        {
            break;
        }
        
        int min;
        int minIndex;
        bool flag = false;
        for(int i = 0; i < wordCount; i ++)
        {
            if(isVisited[i] == false && (distances[i] <= min || flag == false))
            {
                min = distances[i];
                minIndex = i;
                flag = true;
            }
                
        }

        currentNode = minIndex;
        //cout << "stuck" << endl;
    }
    while (true);
    //cout << "out" << endl;

    int distanceToGoal = distances[index2];

    int path[distanceToGoal + 1];

    for(int i  = distanceToGoal; i >= 0; i --)
    {
        if(i == distanceToGoal)
            path[i] = index2;
        
        else if(i == 0)
            path[i] = index1;
        else
        {
            for(int aa = 0; aa < wordCount; aa ++)
            {
                if(adjMatrix[aa][path[i+1]] && distances[aa] == i)
                {
                    path[i] = aa;
                    break;
                }
                    
            }       
        }
    }

    cout << "Shortest path from " << word1 << " to " << word2 << ":" << endl;
    for(int i = 0; i < distanceToGoal + 1; i ++)
        cout << hashTable->getWord(path[i]) << endl;

}

int WordNetwork::findWord(const string word)
{
    return hashTable->getIndex(word);
}

void WordNetwork::listNeighborsHelper(const int index, const int goalDist, const int depth, bool* array)
{
    //array[index] = true;
    if(depth == goalDist)
    {
        cout << hashTable->getWord(index) << endl;
        return;
    }

    for(int i = 0; i < wordCount; i ++)
        if(adjMatrix[index][i] == true && array[i] == false)
        {
            array[index] = true;
            listNeighborsHelper(i, goalDist, depth + 1, array);
        }
            
}

bool WordNetwork::containsFalse(bool* array)
{
    for(int i = 0; i < wordCount; i ++)
        if(array[i] == false)
            return true;
    return false;
}

void WordNetwork::listAllReachable(const int index, bool* array)
{
    if(array[index] == true)
        return;
    cout << hashTable->getWord(index) << endl;
    array[index] = true;
    for(int i = 0; i < wordCount; i ++)
        if(array[i] == false && adjMatrix[index][i] == true)
            listAllReachable(i, array);
}