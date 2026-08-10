
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <limits>
#include <functional>
#include "single_input_neuron.h"


using namespace std;



// ============================================================
//                     MENU NODE
// ============================================================
//
// Every node contains:
//   - A title
//   - Child nodes
//   - Optional function to execute
//
// The map key is the menu number.
//
// ============================================================

struct MenuNode
{
    string title;

    map<int, MenuNode> children;

    function<void()> action;
};


// ============================================================
//                 HELPER: LEAF NODE
// ============================================================

MenuNode item(const string& title)
{
    MenuNode node;

    node.title = title;

    return node;
}


// ============================================================
//              HELPER: ACTION MENU NODE
// ============================================================

MenuNode actionItem(
    const string& title,
    function<void()> action
)
{
    MenuNode node;

    node.title = title;
    node.action = action;

    return node;
}


// ============================================================
//                     CHAPTER 1
// ============================================================

MenuNode createChapter1()
{
    MenuNode chapter;

    chapter.title = "Chapter 1";

    chapter.children[1] = item("Objectives");
    chapter.children[2] = item("History");
    chapter.children[3] = item("Application");
    chapter.children[4] = item("Biological Inspiration");
    chapter.children[5] = item("Further Reading");

    return chapter;
}


// ============================================================
//                     CHAPTER 2
// ============================================================

MenuNode createChapter2()
{
    MenuNode chapter;

    chapter.title = "Chapter 2";

    chapter.children[1] = item("Objectives");


    // --------------------------------------------------------
    // Theory and Examples
    // --------------------------------------------------------

    MenuNode theory;

    theory.title = "Theory and Examples";


    theory.children[1] =
        item("Notation");


    // --------------------------------------------------------
    // Neuron Model
    // --------------------------------------------------------

    MenuNode neuronModel;

    neuronModel.title = "Neuron Model";


    neuronModel.children[1] =
        actionItem(
            "Single-Input Neuron",
            []()
            {
                SingleInputNeuron neuron;
                neuron.process();
            }
        );


    neuronModel.children[2] =
        item("Transfer Functions");


    neuronModel.children[3] =
        item("Multiple-Input Neuron");


    theory.children[2] = neuronModel;


    // --------------------------------------------------------
    // Network Architectures
    // --------------------------------------------------------

    MenuNode architecture;

    architecture.title = "Network Architectures";

    architecture.children[1] =
        item("A Layer of Neurons");

    architecture.children[2] =
        item("Multiple Layers of Neurons");

    architecture.children[3] =
        item("Recurrent Networks");


    theory.children[3] = architecture;


    chapter.children[2] = theory;


    chapter.children[3] =
        item("Summary of Results");

    chapter.children[4] =
        item("Solved Problems");

    chapter.children[5] =
        item("Epilogue");

    chapter.children[6] =
        item("Exercises");


    return chapter;
}


// ============================================================
//                     CHAPTER 3
// ============================================================

MenuNode createChapter3()
{
    MenuNode chapter;

    chapter.title = "Chapter 3";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";

    theory.children[1] =
        item("Problem Statement");


    MenuNode perceptron;
    perceptron.title = "Perceptron";

    perceptron.children[1] =
        item("Two-Input Case");

    perceptron.children[2] =
        item("Pattern Recognition Example");

    theory.children[2] = perceptron;


    MenuNode hamming;
    hamming.title = "Hamming Network";

    hamming.children[1] =
        item("Feedforward Layer");

    hamming.children[2] =
        item("Recurrent Layer");

    theory.children[3] = hamming;


    theory.children[4] =
        item("Hopfield Network");


    chapter.children[2] = theory;

    chapter.children[3] = item("Epilogue");
    chapter.children[4] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 4
// ============================================================

MenuNode createChapter4()
{
    MenuNode chapter;

    chapter.title = "Chapter 4";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    theory.children[1] =
        item("Learning Rules");


    MenuNode architecture;
    architecture.title = "Perceptron Architecture";

    architecture.children[1] =
        item("Single-Neuron Perceptron");

    architecture.children[2] =
        item("Multiple-Neuron Perceptron");

    theory.children[2] = architecture;


    MenuNode learning;
    learning.title = "Perceptron Learning Rule";

    learning.children[1] =
        item("Test Problem");

    learning.children[2] =
        item("Constructing Learning Rules");

    learning.children[3] =
        item("Unified Learning Rule");

    learning.children[4] =
        item("Training Multiple-Neuron Perceptrons");

    theory.children[3] = learning;


    MenuNode convergence;
    convergence.title = "Proof of Convergence";

    convergence.children[1] = item("Notation");
    convergence.children[2] = item("Proof");
    convergence.children[3] = item("Limitations");

    theory.children[4] = convergence;


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Further Reading");
    chapter.children[7] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 5
// ============================================================

MenuNode createChapter5()
{
    MenuNode chapter;

    chapter.title = "Chapter 5";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";

    theory.children[1] =
        item("Linear Vector Spaces");

    theory.children[2] =
        item("Linear Independence");

    theory.children[3] =
        item("Spanning a Space");

    theory.children[4] =
        item("Inner Product");

    theory.children[5] =
        item("Norm");


    MenuNode orthogonality;
    orthogonality.title = "Orthogonality";

    orthogonality.children[1] =
        item("Gram-Schmidt Orthogonalization");

    theory.children[6] = orthogonality;


    MenuNode expansions;
    expansions.title = "Vector Expansions";

    expansions.children[1] =
        item("Reciprocal Basis Vector");

    theory.children[7] = expansions;


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 6
// ============================================================

MenuNode createChapter6()
{
    MenuNode chapter;

    chapter.title = "Chapter 6";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";

    theory.children[1] =
        item("Linear Transformations");

    theory.children[2] =
        item("Matrix Representations");

    theory.children[3] =
        item("Change of Basis");


    MenuNode eigen;
    eigen.title = "Eigenvalues and Eigenvectors";

    eigen.children[1] =
        item("Diagonalization");

    theory.children[4] = eigen;


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 7
// ============================================================

MenuNode createChapter7()
{
    MenuNode chapter;

    chapter.title = "Chapter 7";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";

    theory.children[1] =
        item("Linear Associator");


    MenuNode hebb;
    hebb.title = "The Hebb Rule";

    hebb.children[1] =
        item("Performance Analysis");

    theory.children[2] = hebb;


    theory.children[3] =
        item("Pseudoinverse Rule");

    theory.children[4] =
        item("Application");

    theory.children[5] =
        item("Variations of Hebbian Learning");


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Further Reading");
    chapter.children[7] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 8
// ============================================================

MenuNode createChapter8()
{
    MenuNode chapter;

    chapter.title = "Chapter 8";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    MenuNode taylor;
    taylor.title = "Taylor Series";

    taylor.children[1] =
        item("Vector Case");

    theory.children[1] = taylor;


    theory.children[2] =
        item("Directional Derivatives");

    theory.children[3] =
        item("Minima");


    MenuNode optimality;
    optimality.title =
        "Necessary Conditions for Optimality";

    optimality.children[1] =
        item("First-Order Conditions");

    optimality.children[2] =
        item("Second-Order Conditions");

    theory.children[4] = optimality;


    MenuNode quadratic;
    quadratic.title = "Quadratic Functions";

    quadratic.children[1] =
        item("Eigensystem of the Hessian");

    theory.children[5] = quadratic;


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 9
// ============================================================

MenuNode createChapter9()
{
    MenuNode chapter;

    chapter.title = "Chapter 9";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    MenuNode steepest;
    steepest.title = "Steepest Descent";

    steepest.children[1] =
        item("Stable Learning Rates");

    steepest.children[2] =
        item("Minimizing Along a Line");

    theory.children[1] = steepest;


    theory.children[2] =
        item("Newton's Method");

    theory.children[3] =
        item("Conjugate Gradient");


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 10
// ============================================================

MenuNode createChapter10()
{
    MenuNode chapter;

    chapter.title = "Chapter 10";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    MenuNode adaline;
    adaline.title = "ADALINE Network";

    adaline.children[1] =
        item("Single ADALINE");

    theory.children[1] = adaline;


    theory.children[2] =
        item("Mean Square Error");

    theory.children[3] =
        item("LMS Algorithm");

    theory.children[4] =
        item("Analysis of Convergence");


    MenuNode filtering;
    filtering.title = "Adaptive Filtering";

    filtering.children[1] =
        item("Adaptive Noise Cancellation");

    filtering.children[2] =
        item("Echo Cancellation");

    theory.children[5] = filtering;


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 11
// ============================================================

MenuNode createChapter11()
{
    MenuNode chapter;

    chapter.title = "Chapter 11";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    MenuNode mlp;
    mlp.title = "Multilayer Perceptrons";

    mlp.children[1] =
        item("Pattern Classification");

    mlp.children[2] =
        item("Function Approximation");

    theory.children[1] = mlp;


    MenuNode backprop;
    backprop.title =
        "The Backpropagation Algorithm";

    backprop.children[1] =
        item("Performance Index");

    backprop.children[2] =
        item("Chain Rule");

    backprop.children[3] =
        item("Backpropagating the Sensitivities");

    backprop.children[4] =
        item("Summary");

    theory.children[2] = backprop;


    theory.children[3] =
        item("Example");

    theory.children[4] =
        item("Batch vs. Incremental Training");


    MenuNode usingBackprop;
    usingBackprop.title =
        "Using Backpropagation";

    usingBackprop.children[1] =
        item("Choice of Network Architecture");

    usingBackprop.children[2] =
        item("Convergence");

    usingBackprop.children[3] =
        item("Generalization");

    theory.children[5] = usingBackprop;


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Further Reading");
    chapter.children[7] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 12
// ============================================================

MenuNode createChapter12()
{
    MenuNode chapter;

    chapter.title = "Chapter 12";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    MenuNode drawbacks;
    drawbacks.title =
        "Drawbacks of Backpropagation";

    drawbacks.children[1] =
        item("Performance Surface Example");

    drawbacks.children[2] =
        item("Convergence Example");

    theory.children[1] = drawbacks;


    MenuNode modifications;
    modifications.title =
        "Heuristic Modifications of Backpropagation";

    modifications.children[1] =
        item("Momentum");

    modifications.children[2] =
        item("Variable Learning Rule");

    theory.children[2] = modifications;


    MenuNode numerical;
    numerical.title =
        "Numerical Optimization Techniques";

    numerical.children[1] =
        item("Conjugate Gradient");

    numerical.children[2] =
        item("Levenberg-Marquardt Algorithm");

    theory.children[3] = numerical;


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Further Reading");
    chapter.children[7] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 13
// ============================================================

MenuNode createChapter13()
{
    MenuNode chapter;

    chapter.title = "Chapter 13";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";

    theory.children[1] =
        item("Problem Statement");


    MenuNode generalization;
    generalization.title =
        "Methods for Improving Generalization";

    generalization.children[1] =
        item("Estimating Generalization Error");

    generalization.children[2] =
        item("Early Stopping");

    generalization.children[3] =
        item("Regularization");

    generalization.children[4] =
        item("Bayesian Analysis");

    generalization.children[5] =
        item("Bayesian Regularization");

    generalization.children[6] =
        item("Relationship Between Early Stopping and Regularization");

    theory.children[2] = generalization;


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 14
// ============================================================

MenuNode createChapter14()
{
    MenuNode chapter;

    chapter.title = "Chapter 14";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    MenuNode dynamicNetworks;
    dynamicNetworks.title =
        "Layered Digital Dynamic Networks";

    dynamicNetworks.children[1] =
        item("Example Dynamic Networks");

    theory.children[1] = dynamicNetworks;


    theory.children[2] =
        item("Principles of Dynamic Learning");


    MenuNode dynamicBackprop;
    dynamicBackprop.title =
        "Dynamic Backpropagation";

    dynamicBackprop.children[1] =
        item("Preliminary Definitions");

    dynamicBackprop.children[2] =
        item("Real Time Recurrent Learning");

    dynamicBackprop.children[3] =
        item("Backpropagation-Through-Time");

    dynamicBackprop.children[4] =
        item("Summary and Comments on Dynamic Training");

    theory.children[3] = dynamicBackprop;


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 15
// ============================================================

MenuNode createChapter15()
{
    MenuNode chapter;

    chapter.title = "Chapter 15";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    theory.children[1] =
        item("Simple Associative Network");


    MenuNode hebb;
    hebb.title = "Unsupervised Hebb Rule";

    hebb.children[1] =
        item("Hebb Rule with Decay");

    theory.children[2] = hebb;


    theory.children[3] =
        item("Simple Recognition Network");


    MenuNode instar;
    instar.title = "Instar Rule";

    instar.children[1] =
        item("Kohonen Rule");

    theory.children[4] = instar;


    theory.children[5] =
        item("Simple Recall Network");

    theory.children[6] =
        item("Outstar Rule");


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 16
// ============================================================

MenuNode createChapter16()
{
    MenuNode chapter;

    chapter.title = "Chapter 16";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    MenuNode hamming;
    hamming.title = "Hamming Network";

    hamming.children[1] =
        item("Layer 1");

    hamming.children[2] =
        item("Layer 2");

    theory.children[1] = hamming;


    MenuNode competitive;
    competitive.title = "Competitive Layer";

    competitive.children[1] =
        item("Competitive Learning");

    competitive.children[2] =
        item("Problems with Competitive Layers");

    theory.children[2] = competitive;


    theory.children[3] =
        item("Competitive Layers in Biology");


    MenuNode som;
    som.title =
        "Self-Organizing Feature Maps";

    som.children[1] =
        item("Improving Feature Maps");

    theory.children[4] = som;


    MenuNode lvq;
    lvq.title =
        "Learning Vector Quantization";

    lvq.children[1] =
        item("LVQ Learning");

    lvq.children[2] =
        item("Improving LVQ Networks (LVQ2)");

    theory.children[5] = lvq;


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Further Reading");
    chapter.children[7] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 17
// ============================================================

MenuNode createChapter17()
{
    MenuNode chapter;

    chapter.title = "Chapter 17";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    MenuNode rbf;
    rbf.title = "Radial Basis Network";

    rbf.children[1] =
        item("Function Approximation");

    rbf.children[2] =
        item("Pattern Classification");

    rbf.children[3] =
        item("Global vs. Local");

    theory.children[1] = rbf;


    MenuNode training;
    training.title = "Training RBF Networks";

    training.children[1] =
        item("Linear Least Squares");

    training.children[2] =
        item("Orthogonal Least Squares");

    training.children[3] =
        item("Clustering");

    training.children[4] =
        item("Nonlinear Optimization");

    training.children[5] =
        item("Other Training Techniques");

    theory.children[2] = training;


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Further Reading");
    chapter.children[7] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 18
// ============================================================

MenuNode createChapter18()
{
    MenuNode chapter;

    chapter.title = "Chapter 18";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    MenuNode vision;
    vision.title =
        "Biological Motivation: Vision";

    vision.children[1] =
        item("Illusions");

    vision.children[2] =
        item("Vision Normalization");

    theory.children[1] = vision;


    theory.children[2] =
        item("Basic Nonlinear Model");


    MenuNode competitive;
    competitive.title =
        "Two-Layer Competitive Network";

    competitive.children[1] =
        item("Layer 1");

    competitive.children[2] =
        item("Layer 2");

    competitive.children[3] =
        item("Choice of Transfer Function");

    competitive.children[4] =
        item("Learning Law");

    theory.children[3] = competitive;


    theory.children[4] =
        item("Relation to Kohonen Law");


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Further Reading");
    chapter.children[7] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 19
// ============================================================

MenuNode createChapter19()
{
    MenuNode chapter;

    chapter.title = "Chapter 19";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    theory.children[1] =
        item("Overview of Adaptive Resonance");


    MenuNode layer1;
    layer1.title = "Layer 1";

    layer1.children[1] =
        item("Steady State Analysis");

    theory.children[2] = layer1;


    theory.children[3] =
        item("Layer 2");

    theory.children[4] =
        item("Orienting Subsystem");


    MenuNode l1l2;
    l1l2.title = "Learning Law: L1-L2";

    l1l2.children[1] =
        item("Subset/Superset Dilemma");

    l1l2.children[2] =
        item("Learning Law");

    theory.children[5] = l1l2;


    theory.children[6] =
        item("Learning Law: L2-L1");


    MenuNode art;
    art.title = "ART1 Algorithm Summary";

    art.children[1] =
        item("Initialization");

    art.children[2] =
        item("Algorithm");

    theory.children[7] = art;


    theory.children[8] =
        item("Other ART Architectures");


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Further Reading");
    chapter.children[7] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 20
// ============================================================

MenuNode createChapter20()
{
    MenuNode chapter;

    chapter.title = "Chapter 20";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    theory.children[1] =
        item("Recurrent Networks");


    MenuNode stability;
    stability.title = "Stability Concepts";

    stability.children[1] =
        item("Definitions");

    theory.children[2] = stability;


    theory.children[3] =
        item("Lyapunov Stability Theorem");

    theory.children[4] =
        item("Pendulum Example");


    MenuNode lasalle;
    lasalle.title =
        "LaSalle's Invariance Theorem";

    lasalle.children[1] =
        item("Definitions");

    lasalle.children[2] =
        item("Theorem");

    lasalle.children[3] =
        item("Example");

    lasalle.children[4] =
        item("Comments");

    theory.children[5] = lasalle;


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Further Reading");
    chapter.children[7] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 21
// ============================================================

MenuNode createChapter21()
{
    MenuNode chapter;

    chapter.title = "Chapter 21";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    theory.children[1] =
        item("Hopfield Model");


    MenuNode lyapunov;
    lyapunov.title = "Lyapunov Function";

    lyapunov.children[1] =
        item("Invariant Sets");

    lyapunov.children[2] =
        item("Example");

    lyapunov.children[3] =
        item("Hopfield Attractors");

    theory.children[2] = lyapunov;


    theory.children[3] =
        item("Effect of Gain");


    MenuNode design;
    design.title = "Hopfield Design";

    design.children[1] =
        item("Content-Addressable Memory");

    design.children[2] =
        item("Hebb Rule");

    design.children[3] =
        item("Lyapunov Surface");

    theory.children[4] = design;


    chapter.children[2] = theory;

    chapter.children[3] = item("Summary of Results");
    chapter.children[4] = item("Solved Problems");
    chapter.children[5] = item("Epilogue");
    chapter.children[6] = item("Further Reading");
    chapter.children[7] = item("Exercises");

    return chapter;
}


// ============================================================
//                     CHAPTER 22
// ============================================================

MenuNode createChapter22()
{
    MenuNode chapter;

    chapter.title = "Chapter 22";

    chapter.children[1] = item("Objectives");


    MenuNode theory;
    theory.title = "Theory and Examples";


    MenuNode pretraining;
    pretraining.title = "Pre-Training Steps";

    pretraining.children[1] =
        item("Selection of Data");

    pretraining.children[2] =
        item("Data Preprocessing");

    pretraining.children[3] =
        item("Choice of Network Architecture");

    theory.children[1] = pretraining;


    MenuNode training;
    training.title = "Training the Network";

    training.children[1] =
        item("Weight Initialization");

    training.children[2] =
        item("Choice of Training Algorithm");

    training.children[3] =
        item("Stopping Criteria");

    training.children[4] =
        item("Choice of Performance Function");

    training.children[5] =
        item("Committees of Networks");

    theory.children[2] = training;


    MenuNode post;
    post.title = "Post-Training Analysis";

    post.children[1] =
        item("Fitting");

    post.children[2] =
        item("Pattern Recognition");

    post.children[3] =
        item("Clustering");

    post.children[4] =
        item("Prediction");

    post.children[5] =
        item("Overfitting and Extrapolation");

    post.children[6] =
        item("Sensitivity Analysis");

    theory.children[3] = post;


    chapter.children[2] = theory;

    chapter.children[3] = item("Epilogue");
    chapter.children[4] = item("Further Reading");

    return chapter;
}


// ============================================================
//        CHAPTERS 23 - 27 : MAGNETIC LEVITATION SYSTEM
// ============================================================

MenuNode createMagneticLevitationChapter(int number)
{
    MenuNode chapter;

    chapter.title =
        "Chapter " + to_string(number);


    chapter.children[1] =
        item("Objectives");


    MenuNode theory;
    theory.title =
        "Theory and Examples";


    theory.children[1] =
        item("Description of the Magnetic Levitation System");

    theory.children[2] =
        item("Data Collection and Preprocessing");

    theory.children[3] =
        item("Selecting the Architecture");

    theory.children[4] =
        item("Training the Network");

    theory.children[5] =
        item("Validation");

    theory.children[6] =
        item("Data Sets");


    chapter.children[2] = theory;

    chapter.children[3] =
        item("Epilogue");

    chapter.children[4] =
        item("Further Reading");


    return chapter;
}


// ============================================================
//                    CREATE MAIN MENU
// ============================================================

MenuNode createMainMenu()
{
    MenuNode main;

    main.title = "Neural Network Design";


    main.children[1] =
        createChapter1();

    main.children[2] =
        createChapter2();

    main.children[3] =
        createChapter3();

    main.children[4] =
        createChapter4();

    main.children[5] =
        createChapter5();

    main.children[6] =
        createChapter6();

    main.children[7] =
        createChapter7();

    main.children[8] =
        createChapter8();

    main.children[9] =
        createChapter9();

    main.children[10] =
        createChapter10();

    main.children[11] =
        createChapter11();

    main.children[12] =
        createChapter12();

    main.children[13] =
        createChapter13();

    main.children[14] =
        createChapter14();

    main.children[15] =
        createChapter15();

    main.children[16] =
        createChapter16();

    main.children[17] =
        createChapter17();

    main.children[18] =
        createChapter18();

    main.children[19] =
        createChapter19();

    main.children[20] =
        createChapter20();

    main.children[21] =
        createChapter21();

    main.children[22] =
        createChapter22();


    // Chapters 23 - 27

    main.children[23] =
        createMagneticLevitationChapter(23);

    main.children[24] =
        createMagneticLevitationChapter(24);

    main.children[25] =
        createMagneticLevitationChapter(25);

    main.children[26] =
        createMagneticLevitationChapter(26);

    main.children[27] =
        createMagneticLevitationChapter(27);


    return main;
}


// ============================================================
//                     DISPLAY MENU
// ============================================================

void displayMenu(const MenuNode& node)
{
    cout << "\n";
    cout << "============================================================\n";
    cout << "  " << node.title << "\n";
    cout << "============================================================\n";


    for (const auto& [number, child] : node.children)
    {
        cout << "  "
             << number
             << ". "
             << child.title
             << endl;
    }


    cout << "  0. Back\n";

    cout << "============================================================\n";
}


// ============================================================
//                  RECURSIVE MENU FUNCTION
// ============================================================

void runMenu(const MenuNode& node)
{
    while (true)
    {
        displayMenu(node);


        int choice;

        cout << "Enter your choice: ";
        cin >> choice;


        // ----------------------------------------------------
        // Invalid input
        // ----------------------------------------------------

        if (cin.fail())
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "\nInvalid input. Please enter a number.\n";

            continue;
        }


        // ----------------------------------------------------
        // Back
        // ----------------------------------------------------

        if (choice == 0)
        {
            return;
        }


        // ----------------------------------------------------
        // Find menu item in map
        // ----------------------------------------------------

        auto found = node.children.find(choice);


        if (found == node.children.end())
        {
            cout << "\nInvalid choice. Please try again.\n";

            continue;
        }


        const MenuNode& selected =
            found->second;


        // ----------------------------------------------------
        // If action exists, execute it
        // ----------------------------------------------------

        if (selected.action)
        {
            selected.action();
        }


        // ----------------------------------------------------
        // Otherwise recursively open submenu
        // ----------------------------------------------------

        else if (!selected.children.empty())
        {
            runMenu(selected);
        }


        // ----------------------------------------------------
        // Leaf node without action
        // ----------------------------------------------------

        else
        {
            cout << "\n";
            cout << "------------------------------------------------------------\n";
            cout << "Selected: " << selected.title << endl;
            cout << "------------------------------------------------------------\n";

            cout << "This topic has not been implemented yet.\n";


            cout << "\nPress ENTER to continue...";

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cin.get();
        }
    }
}




