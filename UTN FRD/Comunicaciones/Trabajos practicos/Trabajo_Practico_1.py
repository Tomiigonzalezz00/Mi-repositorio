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

#Lista de funciones
funcion_elegida = 1

def funcion_1(t):
    return seno(t)


def seleccionar_funcion(funcion_elegida,t):
    switcher = {
        1: funcion_1(t)
    }
    # obtener la función correspondiente a la opción seleccionada
    funcion = switcher.get(funcion_elegida, lambda: "Opción inválida")
    # llamar a la función correspondiente
    return funcion()

def funcion(t):
    return seleccionar_funcion(funcion_elegida,t)

#Componente continua
An.append((1/T)*quad(funcion(t),-T/2,T/2)[0]) #Calculo de A0, fuera del calculo principal de coeficientes
Bn.append(0) #Se agrega un cero en la primer posicion para que en el calculo principal de los coeficientes, ambos empiecen cargando los valores desde la posicion "1"

    
def coeficientes():
    for n in range(1,maxcoeficientes+1):
        def funcionA(t):
            return funcion(t)*cos(Wo*n*t)
        def funcionB(t):
            return funcion(t)*seno(Wo*n*t)
        An.append((1/T)*quad(funcionA,-T/2,T/2)[0])
        Bn.append((1/T)*quad(funcionB,-T/2,T/2)[0])

def sumatoria():
    coeficientes()
    sum = 0 
    for n in range(1,maxcoeficientes+1):
        sum += (An[n]*cos(Wo*n*t) + Bn[n]*seno(Wo*n*t))
    return sum
    
def fourierTrigonometrica():
    return An[0] + (2 * sumatoria())


plt.plot(t,funcion(t))
plt.plot(t,fourierTrigonometrica())
plt.show()