""" Les presento la tarea: crear un sistema para una veterinaria. Acá están los pasos a seguir:

Primero, necesitan crear una mascota. Pidan al usuario que ingrese los datos necesarios, como el nombre, la raza, etc. ¡Asegúrate de capturar toda la información importante!
Una vez que hayan creado la mascota, deberán agregarla a nuestra lista de mascotas en el sistema. Esto nos permitirá realizar un seguimiento de todas las mascotas que atendemos en la veterinaria.
Por último, es momento de mostrar todas las mascotas que tenemos en nuestro sistema. De esta forma, podremos verificar que todas las mascotas han sido correctamente agregadas y visualizar la información de cada una.
Tienes dos opciones para realizar esta tarea:

a) Puedes escribir los métodos necesarios directamente en el programa principal. Es una forma sencilla de organizar tu código y realizar las acciones requeridas.

b) También puedes crear una clase llamada "Sistema" que contenga los métodos necesarios para crear, agregar y mostrar mascotas. Esta opción te permitirá estructurar mejor tu código y aprovechar los beneficios de la programación orientada a objetos. """



class Mascota: 
    # nombre = "VEte Codo"
    def __init__(self,nombre,raza):
        #atributo privado
        self.__nombre = nombre #Con el __ se protegen los atributos para que sean privados. Es encapsulamiento, se Protegen los datos sensibles del objeto
        self.__raza = raza
        self.__edad = 0
    
    @property #Decorador, puedo acceder al dato directamente(getter), el metodo pasa como propiedad
    def nombre(self):
        return self.__nombre
    
    @property #Decorador, puedo acceder al dato directamente(getter),el metodo pasa como propiedad
    def edad(self):
        return self.__edad
    
    @property #Decorador, puedo acceder al dato directamente(getter), el metodo pasa como propiedad
    def raza(self):
        return self.__raza

    @raza.setter #Permite modificar el dato, ya que al estar oculto si no lo tengo no podria
    def raza(self,raza):
        if raza != '':
            self.__raza = raza

    def cumplir_anios(self):
        self.__edad += 1

    def __str__(self):
        cadena = 'Nombre: ' +  self.__nombre + ', Raza: ' + self.raza + ', Edad: ' + str(self.__edad)
        return cadena
    
""" #Prog. ppal
m1 = Mascota("Firulais",'Mestizo')

print(m1.raza)
#print(m1.__nombre) #AttributeError: 'Mascota' object has no attribute '__nombre'
print(m1.nombre)
m1.raza = 'M'
print(m1.raza)
print(m1)
m1.cumplir_anios()
print(m1) """