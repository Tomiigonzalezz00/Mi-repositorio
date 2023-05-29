#Categorizar calificaciones de estudiantes (1 a 10) y ver si aprueba o no

#nota = float(input("Ingrese una nota: "))
#print(nota)

#condiciones
"""
if 7 <= nota <= 101:
        print("PROMOCIONA") #Indentacion 
else:
        if nota >= 4 and nota < 7: 
                print("APRUEBA")
        else: 
                if 1 <= nota < 4: 
                    print("DESAPRUEBA")
                else:
                    print("Nota no valida") """
#elif


""" if 7 <= nota <= 101:
    print("PROMOCIONA") #Indentacion 
elif  nota >= 4 and nota < 7: 
    print("APRUEBA")
elif 1 <= nota < 4: 
    print("DESAPRUEBA")
else: 
     print("Nota no valida.") 

print("Fin del programa")
 """
#switch (desde la version 3.11)


#Ingresar calificaiones de estudiantes y calcular un promedio(hasta ingresar 0)
suma = 0
cont = 0
#Bucles: while
#Validacion
nota = float(input("Ingrese una nota: "))
while not(nota >= 0 and nota <= 10):
    nota = float(input("Error.Ingrese una nota valida: "))

while nota != 0:
    suma += nota
    cont += 1 
    if 7 <= nota <= 10:
        print("PROMOCIONA") #Indentacion 
    elif  nota >= 4 and nota < 7: 
        print("APRUEBA")
    elif 1 <= nota < 4: 
        print("DESAPRUEBA")
    nota = float(input("Ingrese una nota: "))
    while not(nota >= 0 and nota <= 10):
     nota = float(input("Error.Ingrese una nota valida: "))
if cont !=0:
    promedio = suma / cont
    print ("El promedio es: ",promedio)
else:
    print ("No ha ingresado valores.")
print("fin del programa")

