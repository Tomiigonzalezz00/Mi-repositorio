--Ejercicio 1
-- Modelo los Animales 
data Animal = NuevoAnimal 
    { iq :: Int,
      especie :: Especie,
      capacidades :: [String]
    } 

data Especie = Elefante
    | Raton 
    | Perro {raza :: String}

--Declaro algunos animales 
pinky :: Animal
pinky = Animal 
{
    iq = 100,
    especie = Raton,
    capacidades = ["destruir","crear","hablar"]
}

cerebro :: Animal
cerebro = Animal 
{
    iq = 60,
    especie = Raton,
    capacidades = ["hablar" , "pensar"]
}

elefante :: Animal
elefante = Animal 
{
    iq = 40,
    especie = Elefante,
    capacidades = ["beber" , "comer"]
}

perro :: Animal
perro = Animal 
{
    iq = 10,
    especie = Perro "Pitbull",
    capacidades = ["ladrar"]
}

--Ejercicio 2 

inteligenciaSuperior animal incremento = animal { iq = (iq + incremento)}