import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad 
plt.style.use('seaborn')


#Constantes
pi = np.pi  
seno = np.sin
cos= np.cos
#Periodo 
T= 2*pi
#Numero maximo de coeficientes
maxcoeficientes=3
#Variables 
t = np.arange(0,T,0.001)

#Listas con coeficientes
An = []
Bn = []


def funcion_1(t):
    Amplitud = 1
    return np.piecewise(t,[abs(t)<1/2,abs(t)>1/2],[lambda t: Amplitud ,lambda t: 0])

def funcion_2(t):
    return

def funcion_3(t):
    return

def funcion_4(t):
    return 

def funcion(t) : funcion_1(t)

#Componente continua
An.append((1/T)*quad(funcion,-T/2,T/2)[0])
Bn.append(0)

    
def coeficientes():
    for n in range(1,maxcoeficientes+1):
        def funcionA(t):
            return funcion(t)*cos(2*pi*(1/T)*n)
        def funcionB(t):
            return funcion(t)*seno(2*pi*(1/T)*n)
        An.append((1/T)*quad(funcionA,-T/2,T/2)[0])
        Bn.append((1/T)*quad(funcionB,-T/2,T/2)[0])

def sumatoria():
    coeficientes()
    sum = 0 
    for n in range(1,maxcoeficientes+1):
        sum += (An[n]*cos(2*pi*(1/T)*n*t) + Bn[n]*seno(2*pi*(1/T)*n*t))
    return sum
    
def fourierTrigonometrica():
    return An[0] + (2 * sumatoria())

print(sumatoria())
plt.plot(t,funcion(t))
plt.plot(t,fourierTrigonometrica())
plt.show()