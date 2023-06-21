from Mascota import Mascota # Pongo * si quiero traer todo


class Veterinaria:
    def __init__(self,nombre):
        self.nombre = nombre
        self.__mascotas = []

    def agregar_mascota(self,m): #recibe el objeto mascota
        self.__mascotas.append(m)

    def __str__(self):
        cadena = ''
        cadena += f'Nombre:{self.nombre}\n'
        cadena += 'Listado de mascotas de la Vete:' + '\n'
        for m in self.__mascotas:
            cadena += str(m) + '\n'
        cadena += '\n'
        return cadena
    
""" #Prog. Ppal
v1 = Veterinaria('Vete Codo')
m1 = Mascota('Firulais','M')
#m1.nombre = 'sada' #AttributeError: can't set attribute 'nombre'
print(m1)
m1.__nombre = 'sada' #Como no tiene setter no modifica, por estar protegido
m1.raza = 'Mestizo' #Como tiene el Setter,  lo modifica
print(m1)
m1.cumplir_anios() #Modifico a travez de un metodo 
print(m1) """