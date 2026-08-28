#include <iostream>
#include <string>
#include <sstream>
#include <vector> // Required for multi-dimensional inputs/weights
#include <cmath>  // For mathematical functions (though not strictly needed here)
#include <numeric> // Useful for potential summation operations
#include <limits>  // For cin.ignore

using namespace std;

// ============================================================
//                 MULTIPLE INPUT NEURON
// ============================================================


class MultipleInputNeuron
{
private:
    // Use vectors to store multiple inputs and weights
    std::vector<double> p; // Inputs (p1, p2, ...)
    std::vector<double> w; // Weights (w1, w2, ...)
    double b = 0.0;        // Bias (b)
    double n = 0.0;        // Net Input (n)
    double a = 0.0;        // Output (a)


public:

    // Use const reference for efficiency when setting vectors
    void setInput(const std::vector<double>& input)
    {
        this->p = input;
    }

    void setWeight(const std::vector<double>& weight)
    {
        this->w = weight;
    }

    void setBias(double bias)
    {
        this->b = bias;
    }


    // Getters are updated to reflect vector/single access
    const std::vector<double>& getInputs() const { return this->p; }
    const std::vector<double>& getWeights() const { return this->w; }
    double getBias() const { return this->b; }

    double getNetInput() const { return this->n; }
    double getOutput() const { return this->a; }


    // --------------------------------------------------------
    // Helper: Format negative values with parentheses
    // 5   -> 5
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
    // Net input calculation (Dot Product + Bias)
    // n = Σ(p_i * w_i) + b
    // --------------------------------------------------------

    double net_output()
    {
        // CRITICAL CHECK: Inputs and Weights MUST have the same size for dot product
        if (this->p.size() != this->w.size()) {
            cerr << "Error: Input vector size must match weight vector size." << endl;
            return 0.0; // Return safe value or throw exception
        }

        double sum = 0.0;
        
        // Calculate the dot product (Σ p_i * w_i)
        for (size_t i = 0; i < this->p.size(); ++i) {
            sum += this->p[i] * this->w[i];
        }

        // Add the bias: n = sum + b
        this->n = sum + this->b;

        return this->n;
    }


    // --------------------------------------------------------
    // Process neuron (Handles dynamic input gathering)
    // --------------------------------------------------------


    void process()
    {
        cout << "\n";
        cout << "============================================================\n";
        cout << "          MULTIPLE-INPUT NEURON CALCULATION           \n";
        cout << "============================================================\n";

        // --- Input Gathering for Multiple Inputs/Weights ---
        int k; // Number of inputs/weights
        cout << "Enter the number of inputs (k): ";
        cin >> k;

        if (k <= 0) {
            cerr << "Invalid input count. Exiting calculation." << endl;
            return;
        }

        vector<double> current_inputs(k);
        vector<double> current_weights(k);
        
        // Get inputs
        cout << "\nEnter the " << k << " Inputs (p1 p2 ... pk): ";
        for (int i = 0; i < k; ++i) {
            cin >> current_inputs[i];
        }

        // Get weights
        cout << "Enter the " << k << " Weights (w1 w2 ... wk): ";
        for (int i = 0; i < k; ++i) {
            cin >> current_weights[i];
        }
        
        // Get bias
        double bias_input;
        cout << "\nEnter the Bias (b) : ";
        cin >> bias_input;

        // Set internal state
        this->setInput(current_inputs);
        this->setWeight(current_weights);
        this->setBias(bias_input);

        // Calculate net input
        double calculated_n = net_output();


        cout << "\n------------------------------------------------------------\n";

        // Display inputs and weights in vector format
        cout << "Inputs (p)   = [ ";
        for (size_t i = 0; i < p.size(); ++i) {
            cout << this->formatValue(p[i]) << (i < p.size() - 1 ? ", " : "");
        }
        cout << " ]" << endl;

        cout << "Weights (w)  = [ ";
        for (size_t i = 0; i < w.size(); ++i) {
            cout << this->formatValue(w[i]) << (i < w.size() - 1 ? ", " : "");
        }
        cout << " ]" << endl;

        cout << "Bias (b)     = " << this->b << endl;
        cout << "------------------------------------------------------------\n";


        // Display the calculation process: n = Σ(p_i * w_i) + b
        cout << "Calculation Steps:\n";
        cout << "  Sum of (p * w): ";
        double sum_pw = 0.0;
        for (size_t i = 0; i < p.size(); ++i) {
            sum_pw += p[i] * w[i];
            cout << formatValue(p[i]) << "*" << formatValue(w[i]);
            if (i < p.size() - 1) {
                cout << " + ";
            }
        }
        cout << " = " << this->formatValue(sum_pw) << endl;

        // Final net input and output

        cout << "\nNet (n)       = sum(p * w) + b\n";
        cout << "               = " << this->formatValue(sum_pw) 
             << " + " << this->formatValue(this->b) << " = " << this->formatValue(calculated_n) << endl;


        cout << "\n------------------------------------------------------------\n";

    }

    void menu_function(){
        cout << "\nPress ENTER to continue...";
        // Consume remaining input buffer (important if mixed with cin >>)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get(); 
    }
};


