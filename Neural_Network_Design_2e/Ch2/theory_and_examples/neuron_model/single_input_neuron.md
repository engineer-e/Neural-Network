# Neuron Model

## Single-Input Neuron

> Weight, Bias, Net Input, Transfer Function

1. The scalar input _p_ is multiplied by the scalar weight _w_ to form _wp_, one of terms that is sent to the summar.
2. The other input, 1, is multiplied by a _bias b_ and then passed to the summer.
3. The Summer output _n_, often referred to as the _net input_, goes into a _transfer function f_, which produces the scalar neuron output _a_.
4. Some authors use the term
   - "activation function" rather than _transfer function_
   - "offset" rather than _bias_
5. This simple model back to the biological neuron that we discussed in _Chatper 1_
6. The weight _w_ corresponds to the strength of a synapse.
7. The Cell body is represented by the summation and the transfer function, and the neuron output _a_ represents the signal on the axon
8. The actual output depends on the particular transfer function that is chosen. 
9. We will discuss transfer function in the next section
10. The bias is much like a weight, except that it has a constant input of 1.
11. However, if you do not want to have a bias in a particular neuron, it can be omitted. We will see examples of this in Chapter 3, 7 and 16
12. **Note : ** *w* and *b* are both *adjustable* scalar parameters of the neurons.
13. Typically the *Transfer function* is chosen by the designer and then the parameters *w* and *b* will be adjusted by some learning rule
14. So that the neuron input/output relationship meets some specific goal (see Chapter 4 for an introduction to learning rules).
15. As described in the following section, we have different transfer functions for different purposes.

