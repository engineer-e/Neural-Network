import numpy as np
# 2. Recurrent Layer Function returning state output (a) and weight matrix (W)
def recurrent_layer(p, output_neuron, label, transfer, time_steps=2):
    # Initial condition: a(0) = p (p must have shape (output_neuron, 1))
    a = p.copy()
    
    # Initialize W (S x S) and b (S x 1) once outside the time loop
    W = np.random.rand(output_neuron, output_neuron) 
    b = np.random.rand(output_neuron, 1)            
    
    history_states = []
    
    for t in range(time_steps):
        print(f"--- {label} | Time Step t = {t} ---")
        print(f"Output a(t) =\n{a}")
        
        # Net input calculation: n(t+1) = W @ a(t) + b
        n = (W @ a) + b
        
        # Transfer function output: a(t+1) = transfer(n)
        a = transfer(n)
        history_states.append(a.copy())
        
        print("====================================================")
    
    # Returns the final state output and the recurrent weight matrix W
    return a, W, history_states