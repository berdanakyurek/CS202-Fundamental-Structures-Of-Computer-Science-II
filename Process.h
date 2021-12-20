/*
* Title: Heaps
* Author: Berdan Akyurek
* ID: 21600904
* Section: 2
* Assignment: 3
* Description: header file of Process class
*/

#ifndef PROCESS_H
#define PROCESS_H
#include <iostream>

using namespace std;

class Process
{
private:
    int id;
    int priority;
    int comingTime;
    int processTime;
    int waitTime;
    int startTime;
    int printerNo;

public:
    Process(int idA = 0, int priorityA = 0, int comingTimeA = 0, int processTimeA = 0);
    int getID();
    int getPriority();
    int getComingTime();
    int getProcessTime();
    int getWaitTime();
    int getStartTime();
    int getPrinterNo();

    void setWaitTime(int n);
    void setStartTime(int n);
    void setPrinterNo(int n);

};

#endif