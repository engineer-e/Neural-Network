# Neural Network Design

1. <details><summary>Introduction</summary>
   
   - Objectives
   - History
   - Application
   - Biological Inspiration
   - Further Reading</details>

2. <details><summary>Neuron Model and Network Architectures</summary>

    - Objectives
    - Theory and Examples
        - [Notation](Ch2/theory_and_examples/notation/readme.md)
        - Neuron Model
            - [Single-Input Neuron](Ch2/theory_and_examples/neuron_model/single_input_neuron.md)
            - [Transfer Functions](Ch2/theory_and_examples/neuron_model/transfer_functions.md)
            - Multiple-Input Neuron
        - Network Architectures
            - A Layer of Neurons
            - Multiple Layers of Neurons
            - Recurrent Networks
    - Summary of Results
    - [Solved Problems](solved_problem/2/readme.md)
    - Epilogue
    - Exercises

   </details>
3. <details><summary>An Illustrative Example</summary>
    
    - Objectives
    - Theory and Examples
        - Problem Statement
        - Perceptron
            - Two-Input Case
            - Pattern Recognition Example
        - Hamming Network
            - Feedforward Layer
            - Recurrent Layer
        - Hopfield Network
    - Epilogue
    - Exercises
    

    </details>
4. <details><summary>Perceptron Learning Rule</summary>
    
    - Objectives
    - Theory and Examples
        - Learning Rules
        - Perceptron Architecture
            - Single-Neuron Perceptron 
            - Multiple-Neuron Perceptron
        - Perceptron Learning Rule
            - Test Problem
            - Constructing Learning Rules
            - Unified Learning Rule
            - Training Multiple-Neuron Perceptrons
        - Proof of Convergence
            - Notation
            - Proof
            - Limitations
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Further Reading
    - Exercises
    
    </details>
5. <details><summary>Signal and Weight Vector Spaces</summary>
    
    - Objectives
    - Theory and Examples
        - Linear Vector Spaces
        - Linear Independence
        - Spanning a Space
        - Inner Product
        - Norm
        - Orthogonality
            - Gram-Schmidt Orthogonalization
        - Vector Expansions
            - Reciprocal Basis Vector
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Exercises
    
    </details>
6. <details><summary>Linear Transformations for Neural Networks</summary>
    
    - Objectives
    - Theory and Examples
        - Linear Transformations
        - Matrix Representations
        - Change of Basis
        - Eigenvalues and Eigenvectors
            - Diagonalization
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Exercises
    

    </details>
7. <details><summary>Supervised Hebbian Learning</summary>
    
    - Objectives
    - Theory and Examples
        - Linear Associator
        - The Hebb Rule
            - Performance Analysis
        - Pseudoinverse Rule
        - Application 
        - Variations of Hebbian Learning
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Further Reading
    - Exercises
    
    </details>
8. <details><summary>Performance Surfaces and Optimum Points</summary>

    - Objectives
    - Theory and Examples
        - Taylor Series 
            - Vector Case
        - Directional Derivatives 
        - Minima 
        - Necessary Conditions for Optimality
            - First-Order Conditions 
            - Second-Order Conditions
        - Quadratic Functions
            - Eigensystem of the Hessian
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Exercises
    
    </details>
9. <details><summary>Performance Optimization</summary>
    
    - Objectives
    - Theory and Examples
        - Steepest Descent
            - Stable Learning Rates
            - Minimizing Along a Line
        - Netwon's Method
        - Conjugate Gradient
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Exercises
    
    </details>
10. <details><summary>Widrow-Hoff Learning</summary>
    
    - Objectives
    - Theory and Examples
        - ADALINE Network
            - Single ADALINE
        - Mean Square Error
        - LMS Algorithm
        - Analysis of Convergence
        - Adaptive Filtering
            - Adaptive Noise Cancellation
            - Echo Cancellation
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Exercises
    
    </details>
11. <details><summary>Backpropagation</summary>
    
    - Objectives
    - Theory and Examples
        - Multiplayer Perceptrons
            - Pattern Classification
            - Function Approximation
        - The Backpropagation Algorithm
            - Performance Index
            - Chain Rule
            - Backpropagating the Sensitivities
            - Summary 
        - Example
        - Batch vs. Incremental Training
        - Using Backpropagation
            - Choice of Network Architecture 
            - Convergence
            - Generalization
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Further Reading
    - Exercises
    
    </details>
12. <details><summary>Variations on Backpropagation</summary>
    
    - Objectives
    - Theory and Examples
        - Drawbacks of Backpropagation
            - Performance Surface Example
            - Convergence Example 
        - Heuristic Modifications of Backpropagation
            - Momentum 
            - Variable Learning Rule
        - Numerical Optimization Techniques
            - Conjugate Gradient
            - Levenberg-Marquardt Algorithm
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Further Reading
    - Exercises
    
    </details>
13. <details><summary>Generalization</summary>
    
    - Objectives
    - Theory and Examples
        - Problem Statement
        - Methods for Improving Generalization
            - Estimating Generalization Error
            - Early Stopping
            - Regularization 
            - Bayesian Analysis
            - Bayesian Regularization
            - Relationship Between Early Stopping and Regularization
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Exercises
    
    </details>
14. <details><summary>Dynamic Networks</summary>
    
    - Objectives
    - Theory and Examples
        - Layered Digital Dynamic Networks
            - Example Dynamic Networks
        - Principles of Dynamic Learning
        - Dynamic Backpropagation
            - Preliminary Definitions
            - Real Time Recurrent Learning
            - Backpropagation-Through-Time
            - Summary and Comments on Dynamic Training
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Exercises
    
    </details>
15. <details><summary>Associative Learning</summary>
    
    - Objectives
    - Theory and Examples
        - Simple Associative Network
        - Unsupervised Hebb Rule
            - Hebb Rule with Decay
        - Simple Recognition Network
        - Instar Rule
            - Kohonen Rule
        - Simple Recall Network 
        - Outstar Rule
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Exercises
    
    </details>
16. <details><summary>Competitive Networks</summary>
    
    - Objectives
    - Theory and Examples
        - Hamming Network
            - Layer 1
            - Layer 2 
        - Competitive Layer
            - Competitive Learning
            - Problems with Competitive Layers
        - Competitive Layers in Biology
        - Self-Organizing Feature Maps
            - Improving Feature Maps
        - Learning Vector Quantization 
            - LVQ Learning
            - Improving LVQ Networks (LVQ2)
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Further Reading
    - Exercises
    
    </details>
17. <details><summary>Radial Basis Networks</summary>
    
    - Objectives
    - Theory and Examples
        - Radial Basis Network
            - Function Approximation 
            - Pattern Classification
            - Global vs. Local
        - Training RBF Networks
            - Linear Least Squares
            - Orthogonal Least Squares 
            - Clustering
            - Nonlinear Optimization 
            - Other Training Techniques
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Further Reading
    - Exercises
    
    </details>
18. <details><summary>Grossberg Network</summary>
    
    - Objectives
    - Theory and Examples
        - Biological Motivation: Vision
            - Illusions
            - Vision Normalization
        - Basic Nonlinear Model
        - Two-Layer Competitive Network
            - Layer 1
            - Layer 2
            - Choice of Transfer Function
            - Learning Law 
        - Relation to Kohonen Law
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Further Reading
    - Exercises
    
    </details>
19. <details><summary>Adaptive Resonance Theory</summary>
    
    - Objectives
    - Theory and Examples
        - Overview of Adaptive Resonance
        - Layer 1
            - Steady State Analysis
        - Layer 2 
        - Orienting Subsystem
        - Learning Law: L1-L2
            - Subset/Superset Dilemma
            - Learning Law
        - Learning Law: L2-L1
        - ART1 Algorithm Summary 
            - Initialization 
            - Algorithm
        - Other ART Architectures
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Further Reading
    - Exercises
    
    </details>
20. <details><summary>Stability</summary>
    
    - Objectives
    - Theory and Examples
        - Recurrent Networks
        - Stability Concepts
            - Definitions
        - Lyapunov Stability Theorem
        - Pendulum Example
        - LaSalle's Invariance Theorem
            - Definitions
            - Theorem
            - Example
            - Comments
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Further Reading
    - Exercises
    
    </details>
21. <details><summary>Hopfield Network</summary>
    
    - Objectives
    - Theory and Examples
        - Hopfield Model
        - Lyapunov Function 
            - Invariant Sets
            - Example
            - Hopfield Attractors
        - Effect of Gain
        - Hopfield Design
            - Content-Addressable Memory
            - Hebb Rule
            - Lyapunov Surface
    - Summary of Results
    - Solved Problems
    - Epilogue
    - Further Reading
    - Exercises
    
    </details>
22. <details><summary>Practical Training Issues</summary>
    
    - Objectives
    - Theory and Examples
        - Pre-Training Steps
            - Selection of Data
            - Data Preprocessing
            - Choice of Network Architecture
        - Training the Network
            - Weight Initialization 
            - Choice of Training Algorithm 
            - Stopping Criteria
            - Choice of Performance Function 
            - Committees of Networks
        - Post-Training Analysis
            - Fitting
            - Pattern Recognition 
            - Clustering
            - Prediction
             - Overfitting and Extrapolation 
             - Sensitivity Analysis
    - Epilogue
    - Further Reading
    
    </details>
23. <details>
    <summary>Case Study 1 - Function Approximation</summary>
   
    - Objectives
    - Theory and Examples
      - Description of the Magnetic Levitation System
      - Data Collection and Preprocessing
      - Selecting the Architecture
      - Training the Network
      - Validation
      - Data Sets
    - Epilogue
    - Further Reading

    </details>

24. <details>
    <summary>Case Study 2 - Probability Estimation</summary>
   
    - Objectives
    - Theory and Examples
      - Description of the Magnetic Levitation System
      - Data Collection and Preprocessing
      - Selecting the Architecture
      - Training the Network
      - Validation
      - Data Sets
    - Epilogue
    - Further Reading

    </details>

25. <details><summary>Case Study 3 - Pattern Recognition</summary>
   
    - Objectives
    - Theory and Examples
      - Description of the Magnetic Levitation System
      - Data Collection and Preprocessing
      - Selecting the Architecture
      - Training the Network
      - Validation
      - Data Sets
    - Epilogue
    - Further Reading

    </details>

26. <details>
    <summary>Case Study 4 - Clustering</summary>
   
    - Objectives
    - Theory and Examples
      - Description of the Magnetic Levitation System
      - Data Collection and Preprocessing
      - Selecting the Architecture
      - Training the Network
      - Validation
      - Data Sets
    - Epilogue
    - Further Reading

    </details>

27. <details>
    <summary>Case Study 5 - Prediction</summary>
   
    - Objectives
    - Theory and Examples
      - Description of the Magnetic Levitation System
      - Data Collection and Preprocessing
      - Selecting the Architecture
      - Training the Network
      - Validation
      - Data Sets
    - Epilogue
    - Further Reading

    </details>

---

![alt text](book_cover.png)

---


