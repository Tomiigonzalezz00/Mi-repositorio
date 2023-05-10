import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad 


#Constantes
pi = np.pi
seno = np.sin
cos= np.cos
#Periodo y definicion de Wo
T= 5
Wo = 2*pi*(1/T)
#Numero maximo de coeficientes

#Variables 

t = np.arange(-T/2,T/2,0.001)

def funcion_1(t):
    A = 1 #Amplitud
    return np.piecewise(t,[abs(t)<1/2,abs(t)>1/2],[lambda t: A ,lambda t: 0])

def funcion_2(t):
    A= 1 #Amplitud
    T = (2*pi)/Wo
    return np.piecewise(t,[(0<=t) & (t<= (T/2)),((-T/2)<=t) & (t<=0)],[lambda t:A*seno(Wo*t), lambda t: 0])

def funcion_3(t):
    T = pi/Wo
    return abs(seno(Wo*t))

def funcion_4(t):
    A = 1
    return np.piecewise(t, [(0<=t) & (t<= (T/2)),((-T/2)<=t) & (t<=0)],[lambda t: (-4*A/T)*t+A, lambda t: (4*A/T)*t+A])


def serieDeFourier(funcion,maxcoeficientes):
    #Listas con coeficientes
    An = []
    Bn = []
    for n in range(maxcoeficientes+1):
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
            
    sum = 0 
    for n in range(1,maxcoeficientes):
            sum += (An[n]*cos(Wo*n*t) + Bn[n]*seno(Wo*n*t))
    return An[0]+2*sum 
    

while(1):
    print("Ejercicio 1 Trabajo practico de comunicaciones. Para salir ingrese 0 como coeficiente \n")
    maxcoeficientes = int(input("Ingrese la cantidad de coeficientes: "))
    if(maxcoeficientes==0):
        break

    muestreo= int(input("Ingrese el rango de muestreo de la funcion: "))   
    x = np.arange(-muestreo,muestreo,0.001)
    # Código para graficar
    # Definimos un cuadro de 2x2 gráficos
    fig, axs = plt.subplots(2, 2)

    # Calculamos la serie de Fourier de la función 1 desde -5 a 5 y graficamos
    axs[0, 0].plot(t,serieDeFourier(funcion_1,maxcoeficientes), 'r--',linewidth = 2)
    axs[0, 0].plot(x, funcion_1(x), 'g')
    axs[0, 0].title.set_text("Función 1")


    # Calculamos la serie de Fourier de la función 2 desde -5 a 5 y graficamos
    axs[0, 1].plot(t, serieDeFourier(funcion_2,maxcoeficientes), 'r--',linewidth = 2)
    axs[0, 1].plot(x, funcion_2(x),'g')
    axs[0, 1].title.set_text("Función 2")

    # Calculamos la serie de Fourier de la función 3 desde -5 a 5 y graficamos
    axs[1, 0].plot(t, serieDeFourier(funcion_3,maxcoeficientes), 'r--',linewidth = 2)
    axs[1, 0].plot(x, funcion_3(x),'g')
    axs[1, 0].title.set_text("Función 3")

    # Calculamos la serie de Fourier de la función 4 desde -5 a 5 y graficamos
    axs[1, 1].plot(t, serieDeFourier(funcion_4,maxcoeficientes), 'r--',linewidth = 2)
    axs[1, 1].plot(x, funcion_4(x),'g')
    axs[1, 1].title.set_text("Función 4")

    # Cambiamos el tamaño para mejorar la visualización
    fig.set_size_inches(10, 8)

    # Mostramos los gráficos
    plt.show()
