# Neuron Model

## Transfer Functions

1. The transfer function in *Figure 2.1* way be a linear or a non linear function of *n*. 
2. A particular transfer function is chosen to satisfy some specification of the problem that the neuron is attempting to solve. 
3. A variety of transfer function have been included in this book. 
4. Three of the most commonly used functions are discussed below.
   - Hard Limit Transfer Function
   - Linear Transfer Function
   - Log-Sigmoid Transfer Function

### Hard Limit Transfer Function

1. The *hard limit transfer function*, shown on the left side of Figure 2.2, sets the output of the neuron to 0. If the function argument is less than 0, or 1 if its arguments is greater than or equal to 0.

$$ \displaystyle \mathbb{Hard\enspace Limit \enspace Transfer \enspace Function } = \begin{cases}
   0 &\text{if } n < 0 \\
   1 &\text{if } n ≥ 0
\end{cases}$$

2. We will use this function to create neurons that classify inputs into two distinct categories. 
3. It will be extensively in Chapter 4.