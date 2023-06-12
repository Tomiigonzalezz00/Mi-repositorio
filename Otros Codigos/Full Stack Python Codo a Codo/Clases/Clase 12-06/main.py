from class_veterinaria import Veterinaria
from Mascota import Mascota

v1 = Veterinaria("Vete Codo")
nombre = input("Ingrese el nombre de su mascota(ENTER para salir): ")

while nombre != '':
    raza = input("Ingrese la raza de su mascota: ")
    m = Mascota(nombre,raza)
    v1.agregar_mascota(m)
    nombre = input("Ingrese el nombre de su mascota(ENTER para salir): ")

print(v1)