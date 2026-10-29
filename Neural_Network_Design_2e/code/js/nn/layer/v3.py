import numpy as np

def layer(p,W,b,label,transfer,comment=False):
  # 1. Number of input elements (R = 3)
  R = b  
  # 3. Define a single 3-element input pattern p (e.g., the imperfect orange)
  p = np.expand_dims(p, axis=1)  
  # 4. Define the bias vector b1 where each element equals R (Eq. 3.16)
  b1 = np.array([R, R]) # Shape: (2,)
  b1 = np.expand_dims(b1, axis=1)  
  # 5. Calculate feedforward layer output (Eq. 3.17)
  z1 = W @ p + b1
  a1 =  transfer(z1)  
  print(f"{label} = {a1}")
  return a1 


def recurrent_layer(p,w,b, label, transfer, time_steps=2):
    # Initial condition: a(0) = p (p must have shape (output_neuron, 1))
    p = np.expand_dims(p, axis=1)  
    
    
    R = b
    # Initialize W (S x S) and b (S x 1) once outside the time loop
    
    W = w
    
    b1 = np.array([R, R]) # Shape: (2,)
    b1 = np.expand_dims(b1, axis=1)  

    eps = np.array([
    [1, -0.5],  # p1^T (orange)
    [-0.5,1]   # p2^T (apple)
    ])
    # Net input calculation: n(t+1) = W @ a(t) + b
    
    history_states = []
    
    
    a = (W @ p) + b1
                
    
    for t in range(time_steps):
        #print(f"--- {label} | Time Step t = {t} ---")
        #print(f"Output a(t) =\n{a}")

        tran = eps @ a.copy()
        print(f"{tran}")
        # Transfer function output: a(t+1) = transfer(n)
       
        a = transfer(tran)
        history_states.append(a.copy())
        
        print("====================================================")
    
    # Returns the final state output and the recurrent weight matrix W
    return a, W, history_states