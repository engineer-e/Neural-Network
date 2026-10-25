#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class TransferFunction{
private: 
    double n = 0.0;

public:
    void setNetOutput(double value);
    double getNetOutput();
    double hardlim();
    double hardlims();
    double purelin();
    double satlin();
    double satlins();
    double logsig();
    double tansig();
    double poslin();
    double compet();
};

void TransferFunction :: setNetOutput(double value){
    this->n = value;
}

double TransferFunction :: getNetOutput(){
    return this->n;
}



double TransferFunction :: hardlim(){return (this->n >= 0) ? 1 : 0;}
double TransferFunction :: hardlims(){return (this->n >= 0) ? 1 : -1;}
double TransferFunction :: purelin(){return this->n;}
double TransferFunction :: satlin(){return ((this->n >= 0) && (this->n <= 1))?this->n:(this->n > 1)?1:0;}
double TransferFunction :: satlins(){return ((this->n >= -1) && (this->n <= 1))?this->n:(this->n > 1)?1:-1;}
double TransferFunction :: logsig(){return 1.0 / (1.0 + std::exp(-this->n));}
double TransferFunction :: tansig(){return (std::exp(this->n) - std::exp(-this->n)) / (std::exp(this->n) + std::exp(-this->n));}
double TransferFunction :: poslin(){return (this->n >= 0) ? this->n : 0;}
double TransferFunction :: compet(){return 1;}



