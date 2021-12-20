/*
* Title: Heaps
* Author: Berdan Akyurek
* ID: 21600904
* Section: 2
* Assignment: 3
* Description: header file of Simulator class
*/

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Heap.h"

class Simulator
{
private:
    string fileName;
    double avgWaitingTime;
    Process* logFile;
    Heap h;
    //Process* continuingProcesses;
    int logFileLength;
    string simstr;
public:
    Simulator(string f);
    ~Simulator();
    bool load();
    void simulate(int n);
    double getAvg();
    void print();

};

#endif