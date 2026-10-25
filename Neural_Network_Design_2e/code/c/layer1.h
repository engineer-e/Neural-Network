#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
#include <cmath>   
#include <numeric> 
#include <limits>  
#include "matrix.h"


using namespace std;


// ============================================================
//                 Layer of NEURON CALCULATION
// ============================================================


class Layer
{
private:
    // Use vectors to store multiple inputs and weights
    std::vector<double> p; // Inputs (p1, p2, ...)
    std::vector<double> w; // Weights (w1, w2, ...)
    std::vector<double> b; // Bias (b) - Note: Stored as single double
    std::vector<double> n; // Net Input 
    std::vector<double> a; // Output

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


    void setBias(const std::vector<double>& bias)
    {
        this->b_val = bias;
    }



    // Getters are updated to reflect vector/single access
    const std::vector<double>& getInputs() const { return this->p; }
    const std::vector<double>& getWeights() const { return this->w; }
    const std::vector<double>& getBias() const { return this->b_val; }
    const std::vector<double>& getNetInput() const { return this->n; }
    const std::vector<double>& getOutput() const { return this->a; }
    


    // --------------------------------------------------------
    // Helper: Format negative values with parentheses
    // 5     -> 5
    // -5    -> (-5)
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
    // Returns the calculated net input 'n'.
    // --------------------------------------------------------


    const std::vector<double>& net_output()
    {
       
        Matrix mat;
        mat.mul()
          
        return final_n;
    }



    // --------------------------------------------------------
    // Process neuron (Handles dynamic input gathering and display)
    // Returns true if calculation was successful, false otherwise.
    // --------------------------------------------------------


    bool process()
    {
        cout << "\n\n============================================================\n";
        cout << "          Layer of NEURON CALCULATION (Dot Product)     \n";
        cout << "============================================================\n";

        // --- Input Gathering for Multiple Inputs/Weights ---
        int k; // Number of inputs/weights
        cout << "Enter the number of inputs (k): ";
        if (!(cin >> k)) {
             cout << "\nInvalid input for count. Exiting calculation.\n";
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
             return false; 
        }


        if (k <= 0) {
            cerr << "Invalid input count. Must be positive." << endl;
            return false;
        }

        vector<double> current_inputs(k);
        vector<double> current_weights(k);
        
        // Get inputs
        cout << "\nEnter the " << k << " Inputs (p1 p2 ... pk): ";
        for (int i = 0; i < k; ++i) {
            if (!(cin >> current_inputs[i])) {
                cerr << "\nError: Failed to read all inputs. Please enter only numbers." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return false;
            }
        }

        // Get weights
        cout << "Enter the " << k << " Weights (w1 w2 ... wk): ";
        for (int i = 0; i < k; ++i) {
             if (!(cin >> current_weights[i])) {
                cerr << "\nError: Failed to read all weights. Please enter only numbers." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return false;
            }
        }
        
        // Get bias
        double bias_input;
        cout << "\nEnter the Bias (b) : ";
         if (!(cin >> bias_input)) {
             cerr << "\nError: Failed to read bias. Please enter a single number." << endl;
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
             return false;
        }


        // Set internal state
        this->setInput(current_inputs);
        this->setWeight(current_weights);
        this->setBias(bias_input);


        // Calculate net input
        double calculated_n = net_output();


        cout << "\n------------------------------------------------------------\n";

        // Display inputs and weights in vector format
        cout << "Inputs (p)     = [ ";
        for (size_t i = 0; i < p.size(); ++i) {
            cout << this->formatValue(p[i]) << (i < p.size() - 1 ? ", " : "");
        }
        cout << " ]" << endl;


        cout << "Weights (w)    = [ ";
        for (size_t i = 0; i < w.size(); ++i) {
            cout << this->formatValue(w[i]) << (i < w.size() - 1 ? ", " : "");
        }
        cout << " ]" << endl;


        cout << "Bias (b)       = " << this->formatValue(this->b_val) << endl;
        cout << "------------------------------------------------------------\n";



        // Display the calculation process: n = Σ(p_i * w_i) + b
        cout << "Calculation Steps:\n";
        double sum_pw = 0.0;
        for (size_t i = 0; i < p.size(); ++i) {
            sum_pw += p[i] * w[i];
            // Print the individual multiplication terms
            cout << formatValue(p[i]) << " * " << formatValue(w[i]);
            if (i < p.size() - 1) {
                cout << " + ";
            }
        }
        cout << "\nSum of (p * w): = " << this->formatValue(sum_pw) << endl;


        // Final net input and output

        double final_result = sum_pw + this->b_val; // Recalculate for display clarity

        cout << "\nNet (n)       = Sum of (p * w) + b\n";
        cout << "               = " << this->formatValue(sum_pw) 
             << " + " << this->formatValue(this->b_val) 
             << " = " << this->formatValue(final_result) << endl;

        return true; // Successful calculation
    }


    void menu_function(){
        cout << "\nPress ENTER to continue...";
        // Consume remaining input buffer (important after mixed cin operations)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cin.get(); 
    }
};

