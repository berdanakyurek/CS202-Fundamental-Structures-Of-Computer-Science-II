#ifndef DT
#define DT
#include <iostream>
#include <string>


using namespace std;

class DecisionTree
{

public:
    void train(const bool**, const int*, const int, const int);
    void train(const string, const int, const int);
    int predict(const bool*);
    double test(const bool**, const int*, const int);
    double test(const string, const int);
    void print();
private:
    
}

#endif