def sumar(num1,num2,num3=0):
    #docstring
    """ 
    pre: recibe 2 numeros
    pos: devuelve la suma de ambos numeros

    """
    resultado = num1 + num2 + num3 #+ num #mala practica, que tome como referencia una variable global que no recibe como parametro
    return resultado #buena practica: solo un return al final

#num = int(input("Ingrese un numero: "))

#Prog ppal
#help(sumar) #Devuelve una ayuda sobre que hace la funcion, lo que esta en pre y pos

print(sumar(1,3)) #Deja el 0 como default por lo declarado en la funcion

print(sumar(1,3,10)) #reemplaza el valor de num3 con 10
print(sumar(1,3,num3=10))
print(sumar(num2=1,num1=3,num3=10))#Cambio el orden de los parametros

