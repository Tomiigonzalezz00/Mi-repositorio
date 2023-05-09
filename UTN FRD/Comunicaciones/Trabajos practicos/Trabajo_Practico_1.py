import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad 


#Constantes
pi = np.pi  
seno = np.sin
cos= np.cos
#Periodo y definicion de Wo
T= 4*pi
Wo = 2*pi*(1/T) 
#Numero maximo de coeficientes
maxcoeficientes= 5
#Variables 
t = np.arange(-T/2,T/2,0.001)

#Listas con coeficientes
An = []
Bn = []



def funcion_1(t):
    A = 1 #Amplitud
    return np.piecewise(t,[abs(t)<1/2,abs(t)>1/2],[lambda t: A ,lambda t: 0])

def funcion_2(t):
    A= 1 #Amplitud
    T = (2*pi)/Wo
    return np.piecewise(t,[0<=t<= (T/2),(-T/2)<=t<=0],[lambda t:A*seno(Wo*t), lambda t: 0])

def funcion_3(t):
    Amplitud = 1
    T = pi/Wo
    return abs(seno(Wo*t))

def funcion_4(t):
    A = 1
    return np.piecewise(t,[0<=t<= (T/2),(-T/2)<=t<=0],[lambda t: (-4A/T)*t+A, lambda t: (4A/T)*t+A])
    
def coeficientes(funcion):
    for n in range(1,maxcoeficientes+1):
        if (n==0): #Componente continua
            An.append((1/T)*quad(funcion(t),-T/2,T/2)[0]) #Calculo de A0, fuera del calculo principal de coeficientes
            Bn.append(0) #Se agrega un cero en la primer posicion para que en el calculo principal de los coeficientes, ambos empiecen cargando los valores desde la posicion "1"
        else:
            def funcionA(t):
                return funcion(t)*cos(Wo*n*t)
            def funcionB(t):
                return funcion(t)*seno(Wo*n*t)
            An.append((1/T)*quad(funcionA,-T/2,T/2)[0])
            Bn.append((1/T)*quad(funcionB,-T/2,T/2)[0])

def sumatoria(funcion):
    sum = 0 
    for n in range(1,maxcoeficientes+1):
        sum += (An[n]*cos(Wo*n*t) + Bn[n]*seno(Wo*n*t))
    return sum
    
def fourierTrigonometrica(funcion):
    return An[0] + (2 * sumatoria(funcion))

#def imprimirFuncion(funcion) : plt.plot(t,funcion(t))

#def imprimirFourier(funcion) : plt.plot(t,fourierTrgonometrica(funcion(t)))

#imprimirFuncion(funcion_1(t))
#imprimirFourier(funcion_1(t))
coeficientes(funcion_1(t))
plt.plot(t,fourierTrigonometrica(funcion_1(t)))
plt.plot(t,funcion_1(t))
plt.show()
o4545l6