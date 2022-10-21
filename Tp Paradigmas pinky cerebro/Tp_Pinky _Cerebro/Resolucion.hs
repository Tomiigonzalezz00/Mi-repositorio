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
    iq = 60,
    especie = Raton,
    capacidades = ["hablar" , "pensar"]
}

cerebro :: Animal
cerebro = Animal {
    iq = 110,
    especie = Raton,
    capacidades = ["destruir","crear","hacer asda","hacer hola","hacer pepe"]
}

elefante :: Animal
elefante = Animal {
    iq = 40,
    especie = Elefante,
    capacidades = ["beber" , "comer"]
}

raton :: Animal 
raton = Animal {
    iq = 17,
    especie = Raton,
    capacidades = ["destruenglonir el mundo","hacer planes desalmados"]

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
    | (especie animal == Raton) = animal {especie = Perro ("Chiuahua")}
    | raza (especie animal) == "Dogo" = animal { especie = Elefante}
    | otherwise = animal {especie = Raton}

--Ejercicio 3 

antropomorfico :: Animal -> Bool
antropomorfico animal = (tieneLaHabilidad "Hablar" animal) && (iq animal > 60 )

noTanCuerdo :: Animal -> Bool
noTanCuerdo = (>= 3).length.(filter pinkiesco).capacidades

tieneLaHabilidad :: String -> Animal -> Bool
tieneLaHabilidad capacidad animal = elem capacidad (capacidades animal)

empiezaConHacer :: String -> Bool
empiezaConHacer = (== "hacer ").take 6 

habilidadSinHacer :: [a] -> [a]
habilidadSinHacer = drop 6

vocal :: Char -> Bool
vocal letra = any (letra==) "aeiou"


sinHacer :: [a] -> [a]
sinHacer = drop 6 

contieneVocal ::  [Char] -> Bool
contieneVocal = any vocal 

esPinkiesca :: [a] -> Bool
esPinkiesca = (<= 4).length.sinHacer

pinkiesco :: String -> Bool
pinkiesco habilidad = empiezaConHacer habilidad && contieneVocal (sinHacer habilidad) && esPinkiesca habilidad 


--Ejercicio 4

experimentoExitoso :: (Animal -> Animal) -> (Animal -> Bool) -> Animal -> Bool
experimentoExitoso experimento criterio = criterio.experimento

experimento1 :: Animal -> Animal
experimento1 = superpoderes.inteligenciaSuperior 10.pinkificar

--Ejercicio 5 
