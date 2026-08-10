#include <iostream>
#include <string>
#include <sstream>


using namespace std;


// ============================================================
//                  SINGLE INPUT NEURON
// ============================================================

class SingleInputNeuron
{
private:
    double p = 0.5;
    double w = 1.0;
    double b = 1.0;
    double n = 0.0;
    double a = 0.0;

public:

    void setInput(double input)
    {
        this->p = input;
    }

    void setWeight(double weight)
    {
        this->w = weight;
    }

    void setBias(double bias)
    {
        this->b = bias;
    }

    double getInput()
    {
        return this->p;
    }

    double getWeight()
    {
        return this->w;
    }

    double getBias()
    {
        return this->b;
    }

    double getNetInput()
    {
        return this->n;
    }

    double getOutput()
    {
        return this->a;
    }


    // --------------------------------------------------------
    // Format negative values with parentheses
    //
    //  5  -> 5
    // -5  -> (-5)
    // --------------------------------------------------------

    string formatValue(double value)
    {
        ostringstream out;

        if (value < 0)
            out << "(" << value << ")";
        else
            out << value;

        return out.str();
    }


    // --------------------------------------------------------
    // Net input
    //
    // n = wp + b
    // --------------------------------------------------------

    double net_output()
    {
        this->n = this->p * this->w + this->b;

        return this->n;
    }


    // --------------------------------------------------------
    // Process neuron
    // --------------------------------------------------------

    void process()
    {
        cout << "\n";
        cout << "============================================================\n";
        cout << "                    SINGLE-INPUT NEURON\n";
        cout << "============================================================\n";

        cout << "\nEnter the Input  = ";
        cin >> this->p;

        cout << "Enter the Weight = ";
        cin >> this->w;

        cout << "Enter the Bias   = ";
        cin >> this->b;


        // Calculate net input
        net_output();


        cout << "\n------------------------------------------------------------\n";

        cout << "Input  (p) = " << this->p << endl;
        cout << "Weight (w) = " << this->w << endl;
        cout << "Bias   (b) = " << this->b << endl;
        cout << "Net   (n)  = " << this->n << endl;


        cout << "\n";
        cout << "a = f(n) = f(wp + b) = f("
             << formatValue(this->w)
             << "*"
             << formatValue(this->p)
             << "+"
             << formatValue(this->b)
             << ") = f("
             << this->n
             << ")"
             << endl;

        cout << "------------------------------------------------------------\n";


        cout << "\nPress ENTER to continue...";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
};

