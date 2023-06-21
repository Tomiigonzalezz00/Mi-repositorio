try: #Aqui va todo el codigo que puede generar un error
    num1 = int(input("Ingrese un numero: "))
    num2 = int(input("Ingrese otro numero: "))
    resultado = num1/num2 #zeroDivisionError: division by 0
except ValueError: #si hay error se ejecuta el except
    print("Ingresar un valor numerico.")

except ZeroDivisionError:
    print("Debe ingresar un valor distinto de cero en el denominador.")

except:
    print("Ha ocurrido un error.")
else: #Si esta todo bien, llega al else, si esta todo bien se ejecuta siempre
    print(resultado)
finally: #se ejecuta siempre, haya o no error
    print("Gracias por utilizar el programa")

print("Fin del programa")