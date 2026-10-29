import math

def hardlim(n):
   return (n>=0).astype(int)

def hardlims(x):
   return (x>=0)*1 + (x<0)*-1

def purelin(x):
    return x

def satlin(x):
    return ((x >= 0) & (x <= 1)) * x + (x < 0) * 0 + (x > 1) * 1

def satlins(x):
    return ((x >= -1) & (x <= 1)) * x + (x < -1) * -1 + (x > 1) * 1


def logsig(x):
    #return 1 / (1 + (math.e**(-x)))
    return 1 / (1 + np.exp(-x))

def tansig(x):
    #return ((math.e**x) - (math.e**(-x)))/((math.e**x) + (math.e**(-x)))
    #return (np.exp(x) - np.exp(-x)) / (np.exp(x) + np.exp(-x))
    return np.tanh(x)

def poslin(x):
    return (x >= 0) * x

def compet(n):
    y = np.zeros_like(n, dtype=int)
    y[np.argmax(x)] = 1
    return y