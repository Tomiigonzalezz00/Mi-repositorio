class NumeroNegativoError(Exception):
    pass

num = int(input("Ingrese un numero positivo: "))
if num <= 0:
    raise Exception("El numero no puede ser menor o igual a cero.")

print(num)