--Ejercicio 1
-- Modelo los Animales 
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Redundant bracket" #-}
{-# HLINT ignore "Use infix" #-}
{-# HLINT ignore "Use elem" #-}
data Animal = Animal
    { iq :: Int,
      especie :: Especie,
      capacidades :: [String]
    } deriving(Show,Eq)

data Especie = Elefante
    | Raton 
    | Perro {raza :: String}
        deriving(Show,Eq)

--Declaro algunos animales 
pinky :: Animal
pinky = Animal {
    iq = 100,
    especie = Raton,
    capacidades = ["destruir","crear","hablar"]
}

cerebro :: Animal
cerebro = Animal {
    iq = 60,
    especie = Raton,
    capacidades = ["hablar" , "pensar"]
}

elefante :: Animal
elefante = Animal {
    iq = 40,
    especie = Elefante,
    capacidades = ["beber" , "comer"]
}

perro :: Animal
perro = Animal {
    iq = 10,
    especie = Perro "Pitbull",
    capacidades = ["ladrar"]
}

--Ejercicio 2 

inteligenciaSuperior :: Int-> Animal -> Animal
inteligenciaSuperior incremento animal  = animal { iq = iq animal + incremento}

pinkificar :: Animal -> Animal
pinkificar animal = animal {capacidades = []} 

darCapacidad :: Animal -> Animal
darCapacidad animal = animal{capacidades = "aprendizaje Rapido" : capacidades animal}

nuevoComienzo :: Animal -> Animal
nuevoComienzo = darCapacidad.pinkificar.inteligenciaSuperior 20

superpoderes :: Animal -> Animal
superpoderes animal 
    | (especie animal == Elefante) = animal{ capacidades = "No tiene miedo a ratones" : capacidades animal}
    | (especie animal == Raton) && (iq animal > 100) = animal{ capacidades = "Hablar" : capacidades animal}
    | razaPar animal = animal { capacidades = "Cazador de ratones" : capacidades animal}
    | otherwise = animal
 
razaPar :: Animal -> Bool
razaPar animal = (especie animal == Perro (raza (especie animal)) ) && (even.length)(raza (especie animal))


cambiarEspecie :: Animal -> Animal
cambiarEspecie animal 
    | (especie animal == Elefante) = animal{ especie = Raton}
    | (especie animal == Raton) = animal {especie = Perro ("Chiuaua")}
    | raza (especie animal) == "Dogo" = animal { especie = Elefante}
    | otherwise = animal {especie = Raton}

--Ejercicio 3 


anotropomorfico :: Animal -> Bool
anotropomorfico animal = (tieneLaHabilidad "hablar" animal) && (iq animal > 60 )

tieneLaHabilidad :: String -> Animal -> Bool
tieneLaHabilidad capacidad animal = elem capacidad (capacidades animal)

empiezaConHacer :: String -> Bool
empiezaConHacer = (== "hacer").take 6 

vocales = "aeiou"

vocal :: Char -> Bool
vocal letra = any (letra==) vocales


contieneVocal palabra = any (vocal) palabra