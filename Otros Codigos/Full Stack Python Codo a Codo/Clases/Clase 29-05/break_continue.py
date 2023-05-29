#uso de break y continue
suma = 0
while True:
    num = int(input("Ingrese un numero: "))
    if num == 0:
        break
    elif num % 2 == 0:
        continue
    else: 
        suma += num
    print(suma)