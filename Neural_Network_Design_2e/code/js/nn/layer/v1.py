import numpy as np

def layer(p,output_neuron, label,transfer,comment=False):
 w = np.random.rand(output_neuron,p.shape[0]) # Weight
 Wp = w @ p
 b = 1 
 n = Wp + b
 a = transfer(np.array(n))

 if(comment):
   print(f"Input (p) = {p}")
   print(f"Input (p) - Dimentsion = {p.shape}")   
   print(f"{label} - Weight (W) = {w}")
   print(f"{label} - Weight (W) - Dimentsion = {w.shape}")
   print(f"{label} - Wp = {Wp}")
   print(f"{label} - a = f(Wp + 1) = {n}")
   print(f"{label} - a = tansig(Wp + 1) = {a}")
   print("====================================================")
 return a , w 
