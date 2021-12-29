/*
* Title: Heaps
* Author: Berdan Akyurek
* ID: 21600904
* Section: 2
* Assignment: 3
* Description: Class for a simulator
*/

#include "simulator.h"
#include <fstream> 
#include <string>

Simulator::Simulator(string f)
{
    fileName = f;
    avgWaitingTime = -1;
    logFile = NULL;
    //continuingProcesses = NULL;
    logFileLength = -1;
    simstr = "";
}

Simulator::~Simulator()
{
    if(logFile != NULL)
        delete[] logFile;
    //if(continuingProcesses != NULL)
    //    delete[] continuingProcesses;
}

bool Simulator::load()
{
    string line;
    ifstream file(fileName);

    getline (file, line);
    int noOfLines = stoi(line);

    logFile = new Process[noOfLines];

    int i = 0;
    while (getline (file, line)) 
    {
        int id;
        int priority;
        int comingTime;
        int processTime;



        
        string word = "";
        int j = 0;
        for (auto x : line) 
        {
            if (x == ' ')
            {
                if(j == 0)
                {
                    id = stoi(word);
                }
                else if(j == 1)
                {
                    priority = stoi(word);
                }
                else if(j == 2)
                {
                    comingTime = stoi(word);
                }
                
                word = "";
                j ++;
            }
            else {
                word = word + x;
            }
            
        }
        processTime = stoi(word);

        logFile[i] = Process(id, priority, comingTime, processTime);
        i ++;
    }
    logFileLength = noOfLines;
    return true;
}

double Simulator::getAvg()
{
    return avgWaitingTime;
}

void Simulator::simulate(int n)
{
    simstr = "";

    Process* notComeYet = new Process[logFileLength];
    
    bool* printerAvailabilities = new bool[n];

    Process* continuingProcesses = new Process[n];

    for(int i = 0; i < n; i ++)
        printerAvailabilities[i] = true;

    int notComeYetCursor = 0;
    int finishedCursor = 0;

    for(int i = 0; i < logFileLength; i++)
        notComeYet[i] = logFile[i];
    
    int time = 0;
    double sum = 0;
    while(finishedCursor < logFileLength )
    {
    
        while( notComeYetCursor < logFileLength && notComeYet[notComeYetCursor].getComingTime() == time)
        {
            
            h.add(notComeYet[notComeYetCursor]);
            notComeYetCursor ++;
        }
        //cout << h.getSize() << endl;
        for(int i = 0; i < n; i ++ )
        {
            if(printerAvailabilities[i] == false && time - continuingProcesses[i].getStartTime() == continuingProcesses[i].getProcessTime() )
            {
                printerAvailabilities[i] = true;
                finishedCursor ++;
            }
            
        }

        for(int i = 0; i < n ; i++)
        {
            if(printerAvailabilities[i] == true && !h.isEmpty())
            {
                
                printerAvailabilities[i] = false;
                continuingProcesses[i] = h.getHeadProcess();
                h.remove();
                continuingProcesses[i].setWaitTime(time - continuingProcesses[i].getComingTime());
                continuingProcesses[i].setStartTime(time);
                simstr += "Printer " + to_string(i) + " prints print request " + to_string(continuingProcesses[i].getID()) + " at minute " + to_string(time) + " (wait: " + to_string(continuingProcesses[i].getWaitTime()) + " mins)\n";
                sum += continuingProcesses[i].getWaitTime();

            }
        }
        time ++;
    }
    delete[] notComeYet;
    delete[] printerAvailabilities;
    delete[] continuingProcesses;
    //delete[] finishedProcesses;
    avgWaitingTime = sum/logFileLength;
    
}

void Simulator::print()
{
    cout << simstr << endl;

    cout << "Average waiting time: " << avgWaitingTime <<" minutes" << endl;
}

