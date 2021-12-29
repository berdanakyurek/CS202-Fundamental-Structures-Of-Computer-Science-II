#include <cmath>
#include <iostream>
using namespace std;
double calculateEntropy(const int* classCounts, const int numClasses)
{

    double pi = 0;
    double total = 0;
    double totalOfAllCC = 0;

    for(int i = 0 ; i < numClasses ; i++)
    {
        totalOfAllCC += classCounts[i];
    }
    
    if( totalOfAllCC == 0 )
    {
        return 0; // To prevent division by zero error.
    }

    for( int i = 0; i < numClasses ; i++ )
    {
        pi = classCounts[i]/totalOfAllCC;
        if( pi != 0 )
            total += pi* log2(pi);
    }

    return -total;
}

double calculateInformationGain(const bool** data, const int* labels, const int numSamples, const int numFeatures, 
const bool* usedSamples, const int featureId)
{
    int hp = 0;
    int** dataToInt = new int*[numSamples];
    for( int i = 0; i < numSamples ; i ++ )
    {
        dataToInt[i] = new int[numFeatures];
    }


    for( int i = 0; i < numSamples; i ++ )
    {
        for (int j = 0; j < numFeatures; j ++)
        {
            dataToInt[i][j] = int(data[i][j]);
        }
    }
    
    for( int i = 0; i < numSamples ; i++ )
    {   
        hp += calculateEntropy( dataToInt[i], numFeatures );
    }

    // IG(P, S) = H(P) − H(S)
    //
}

int main()
{
    //Test calculateEntropy

    int* cc = new int[3];
    cc[0] = 32;
    cc[1] = 0;
    cc[2] = 7;
    cout << calculateEntropy(cc, 3)<< endl;

    //Test calculateInformationGain

    bool** data = new bool*[5];

    for(int i = 0 ; i < 5; i++ )
        data[i] = new bool[5];

    


    // END MAIN
    return 0;
}