#include <fstream>
#ifdef HEAP1
#include "maxHeap1.h"
#endif
#ifdef HEAP2
#include "maxHeap2.h"
#endif

using namespace std;
int main(int argc, char** argv)
{
    const int maxWaiting = stoi(argv[2]);
    ifstream txt;
    txt.open(argv[1]);

    int numberOfPatients;
    txt >> numberOfPatients;
    

    int allPatients[numberOfPatients][4];

    for( int i = 0 ; i < numberOfPatients ; i ++ )
    {
        for( int j = 0; j < 4 ; j ++ )
            txt >> allPatients[i][j];
    }

    int currentTime;
    int nextPatient;
    maxHeap1 h1;
    bool docsAvailable;

    bool print = false;

    int noOfDoctors = 1;
    int* doctors;

    double totalWaitingTime;
    double avgWaitingTime;

    // this part runs a simulation of the hospital starting from 1 doctor.
    // if 1 doctor is not enough, increases doctor number by 1 and tries again until best doctor number is found.
    while(1) //one loop for each doctor number.
    {
        currentTime = 0;
        nextPatient = 0;

        totalWaitingTime = 0;

        // reset doctors
        doctors = new int[noOfDoctors];
        for( int i = 0; i < noOfDoctors ; i ++ )
        {
            doctors[i] = 0;
        }

        while(1) //one loop for each time value
        {            
            // if there are no newcomers to add and there are nobody waiting
            if( h1.getSize() == 0 && nextPatient >= numberOfPatients )
                break;
            
            //new comers are added to heap
            while( currentTime == allPatients[nextPatient][2] && nextPatient < numberOfPatients  ) 
            {
                h1.insert( allPatients[nextPatient][0], allPatients[nextPatient][1], allPatients[nextPatient][2], allPatients[nextPatient][3]);
                nextPatient ++; 
                
            }

            docsAvailable = true; //assumption.
            // while there are waiting people, 
            while( h1.getSize() != 0 && docsAvailable )
            {
                
                // check doctors for availability.
                for( int i = 0 ; i < noOfDoctors ; i ++ )
                {
                    // if doctor is available
                    if(doctors[i] <= currentTime )
                    {
                        //change doctor's availability and remove patient from heap.
                        doctors[i] = currentTime + h1.getFirstPatientsExamDuration();
                        
                        if( print )
                            cout << "Doctor " << i << " takes patient " << h1.getFirstPatientsId() << " at minute " << currentTime << " (wait: " << currentTime - h1.getFirstPatientsArrivalTime() << " mins)" << endl;
                        
                        totalWaitingTime += currentTime - h1.getFirstPatientsArrivalTime();
                        h1.shift();
                        break;
                    } 
                    //if program reaches here, there are no available doctors.
                    if( i == noOfDoctors - 1 )
                    {
                        docsAvailable = false;
                    }
                }
                
            }

            currentTime ++;
        }

        //calculate average waiting time
        avgWaitingTime = totalWaitingTime/numberOfPatients;

        
        if( print == true )
        {
            cout << "\nAverage Waiting Time: " << avgWaitingTime << " minutes."<< endl;
            delete[] doctors;
            h1.deleteHeap();
            return 0;
        }
        if( avgWaitingTime < maxWaiting && print == false )
        {
            cout << "\nMinimum number of doctors required: " << noOfDoctors << "\n" << endl;
            cout << "Simulation with " << noOfDoctors << " doctors:\n" <<endl;  
            print = true;
            //return 0;
            noOfDoctors --;
        }

        
        noOfDoctors ++;
        delete[] doctors;
    }

    return 0;
}
