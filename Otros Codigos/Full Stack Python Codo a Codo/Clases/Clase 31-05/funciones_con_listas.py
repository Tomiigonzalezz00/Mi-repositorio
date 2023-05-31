import random

def mostrar_lista(lista):
    """ 
    Muestra el contenido de una lista.
    Param.: 
        Lista: Contenido a mostrar
    
    """
    for valor in lista: 
        print(valor,end=' ')
    print()#salto de linea

numeros = [1,2,3,100,-10]
mostrar_lista(numeros) 
print(mostrar_lista(numeros)) #Todo devuelve None si no tengo un return(si devuelve none no tiene return)

def duplicar(lista):
   # for valor in lista: #De esta forma no duplica la lista original, guarda lo duplicado en la variable valor pero no modifica la lista original
    #    valor *= 2 
    for i in range(len(lista)):
        lista[i]*=2

print("Lista sin duplicar: ",numeros)
duplicar(numeros)
print("Lista duplicada: ",numeros)

#listas vs cadenas: Las listas(y diccionarios) se pueden modificar porque son mutables, las cadenas(y tuplas) no son mutables
nombre = "Tomas"
print(nombre*2) #Duplica el espacio en memoria de la cadena (Tengo 2 cadenas)
#nombre[0] ="J" #no puedo modificar una posicion de la cadena porque no es mutable
nombre = nombre *2
print(nombre)

#Tuplas 
def  calcular_suma_prom(lista):
    suma = sum(lista)
    n =len (lista)
    prom = suma/n

    return suma,prom #tupla: (192,38.4)

print(calcular_suma_prom(numeros))
sumatoria, promedio = calcular_suma_prom(numeros) #desempaquetar la tupla, es con todos los elementos, no puedo solo desempaquetar algunos


#Modulos import
def crear_lista(n):
    lista = []
    for _ in range(n): #Cuando pongo _ es que no importa la variable, es cuando necesito que algo se haga tantas cantidad de veces sin importar algo mas
        lista.append(random.randint(1,10))
    return lista

numeros2 = crear_lista(10)
mostrar_lista(numeros2)



#funciones lambda/anonimas/callbacks
def fx_cuadrado(num): #funcion definida de  forma normal 
    return num**2

cuadrado = lambda num:num**2 #definida como funcion lambda, hace la asginacion de la funcion en una variable


print(fx_cuadrado(2))
print(cuadrado(2))
#help(cuadrado)

print(numeros2)
cuadrados = list(map(cuadrado,numeros2)) #Primer parametro funcion y segundo parametro lista a usar(iterable)
print(cuadrados)