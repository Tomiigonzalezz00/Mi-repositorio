#Defrinir nuestra clase 
class Perro:
    #Atributo de clase, se comparten entre todos los objetos del tipo perro
    genero = 'Canis'
    id = 0 #Contador de objetos de tipo perro 
    #Comportamiento (metodos de la clase)
    #Metodos especiales
    def __init__(self, nombre, edad ): #Inicializa el objeto, debe estar siempre 
        #Atributos de instancia, para el objeto creado
        self.nombre = nombre
        self.edad = edad 
        Perro.id += 1
        self.id=Perro.id

    def cumplir_anios(self):
        self.edad +=1
    
    def ladrar(self):
        return f'{self.nombre} dice guau guau.' #no va un print porque solo imprimiria por consola, de esta forma es mas general
    
    def __str__(self):
        return f'ID: {self.id} - {self.nombre} tiene {self.edad} años y su genero es {self.genero}'


#Programa Principal        
perro1= Perro('Paka', 15)
print(type(perro1))

perro2=Perro('Paka',15)
print(type(perro2))


perro2.nombre = 'Firulais'
perro1.edad = 17


perro1.cumplir_anios()
print(perro1.edad)
print(perro2.edad)

print(perro1) #Imprime el area de memoria donde esta el objeto, si no lo hubiera cambiado con el def __str__
print(perro2) #Aunque tienen los mismos datos, el area de memoria es distinta y por lo tanto son objetos distintos

print(perro2.ladrar())