#for 
#for i in range (10) : 0 .. 9
#for i in range(1, 10): #1 .. 9

for i in range (1,11,2): #El tercer argumento es el paso, va de 2 en 2 
    print(i, end=" ") #Cada impresion la separa con un espacio en blanco 
print() #Salto de linea

#operador in
cadena = "Tomi"
print ("T" in cadena) #Devuelve True porque T esta en cadena
print ("E" not in cadena) ## Deuelve True porque E no esta en cadena

#Listas y for 
numeros = [1,2,3,0,-1,100]

for i in range(len(numeros)):
        print(str(i) + ":", numeros[i]) 
print()

