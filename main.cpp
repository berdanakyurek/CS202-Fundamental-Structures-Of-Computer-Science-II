/*
* Title: Heaps
* Author: Berdan Akyurek
* ID: 21600904
* Section: 2
* Assignment: 3
* Description: driver file that contains main function
*/

#include "simulator.h"


int main(int argc, char** argv)
{
    if (argc != 3)
    {
        cout << "This program takes exactly 2 arguments" << endl;
        return -1;
    }

    string fileName = argv[1];
    double avg = stof(argv[2]);
    
    //string fileName = "print_jobs.txt";
    //sdouble avg = 10;

    Simulator s(fileName);

    s.load();

    int noOfPrinters = 0;

    do 
    {
        noOfPrinters ++;
        //noOfPrinters = 4;
        s.simulate(noOfPrinters);
        //break;
    }
    while (s.getAvg() > avg);

    cout << "Minimum number of printers required: " << noOfPrinters << endl <<endl;
    cout << "Simulation with " << noOfPrinters <<" printers:" << endl << endl;
    s.print();

    return 0;
}