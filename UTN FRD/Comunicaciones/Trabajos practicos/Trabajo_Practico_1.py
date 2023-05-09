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
maxcoeficientes= 15
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
    return np.piecewise(t,[(0<=t) & (t<= (T/2)),((-T/2)<=t) & (t<=0)],[lambda t:A*seno(Wo*t), lambda t: 0])

def funcion_3(t):
    A = 1
    T = pi/Wo
    return abs(seno(Wo*t))

def funcion_4(t):
    A = 1
    return np.piecewise(t, [(0<=t) & (t<= (T/2)),((-T/2)<=t) & (t<=0)],[lambda t: (-4*A/T)*t+A, lambda t: (4*A/T)*t+A])

    
def coeficientes(funcion):
    for n in range(1,maxcoeficientes+1):
        if (n==0): #Componente continua
            An.append((1/T)*quad(funcion,-T/2,T/2)[0]) #Calculo de A0, fuera del calculo principal de coeficientes
            Bn.append(0) #Se agrega un cero en la primer posicion para que en el calculo principal de los coeficientes, ambos empiecen cargando los valores desde la posicion "1"
        else:
            def funcionA(t):
                return funcion(t) * np.cos(Wo*n*t)
            def funcionB(t):
                return funcion(t)*seno(Wo*n*t)
            An.append((1/T)*quad(funcionA,-T/2,T/2)[0])
            Bn.append((1/T)*quad(funcionB,-T/2,T/2)[0])

def sumatoria(funcion):
    coeficientes(funcion)
    sum = 0 
    for n in range(1,maxcoeficientes+1):
        sum += (An[n]*cos(Wo*n*t) + Bn[n]*seno(Wo*n*t))
    return An[0]+(2 * sum)
    
#def fourierTrigonometrica(funcion):
    #return An[0] + (2 * sumatoria(funcion))




# Código para graficar
# Definimos un cuadro de 2x2 gráficos
fig, axs = plt.subplots(2, 2)

# Calculamos la serie de Fourier de la función 1 desde -5 a 5 y graficamos
#axs[0, 0].plot(t,fourierTrigonometrica(funcion_1), 'r--')
#axs[0, 0].plot(t, funcion_1(t))
#axs[0, 0].title.set_text("Función 1")


# Calculamos la serie de Fourier de la función 2 desde -5 a 5 y graficamos
axs[0, 1].plot(t, sumatoria(funcion_2), 'r--')
axs[0, 1].plot(t, funcion_2(t))
axs[0, 1].title.set_text("Función 2")

# Calculamos la serie de Fourier de la función 3 desde -5 a 5 y graficamos
#axs[0, 1].plot(t, fourierTrigonometrica(funcion_3), 'r--')
#axs[1, 0].plot(t, funcion_3(t))
#axs[1, 0].title.set_text("Función 3")

# Calculamos la serie de Fourier de la función 4 desde -5 a 5 y graficamos
#axs[0, 1].plot(t, fourierTrigonometrica(funcion_4), 'r--')
#axs[1, 1].plot(t, funcion_4(t))
#axs[1, 1].title.set_text("Función 4")

# Cambiamos el tamaño para mejorar la visualización
fig.set_size_inches(10, 8)

# Mostramos los gráficos
plt.show()
