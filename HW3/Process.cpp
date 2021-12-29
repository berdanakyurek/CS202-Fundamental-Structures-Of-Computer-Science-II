/*
* Title: Heaps
* Author: Berdan Akyurek
* ID: 21600904
* Section: 2
* Assignment: 3
* Description: Class that holds information on the text file
*/

#include "Process.h"

Process::Process(int idA, int priorityA, int comingTimeA, int processTimeA)
{
    id = idA;
    priority = priorityA;
    comingTime = comingTimeA;
    processTime = processTimeA;
    waitTime = -1;
    startTime = -1;
    printerNo = -1;
}

int Process::getID()
{
    return id;
}

int Process::getPrinterNo()
{
    return printerNo;
}

int Process::getPriority()
{
    return priority;
}

int Process::getComingTime()
{
    return comingTime;
}

int Process::getProcessTime()
{
    return processTime;
}

int Process::getWaitTime()
{
    return waitTime;
}

void Process::setWaitTime(int n)
{
    waitTime = n;
}

void Process::setStartTime(int n)
{
    startTime = n;
}

int Process::getStartTime()
{
    return startTime;
}

void Process::setPrinterNo(int n)
{
    printerNo = n;
}
