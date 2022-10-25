data Persona = UnaPersona {
    nombre :: String,
    cuenta:: [(Float,String)],
    nivelDeSatisfaccion :: Int
}  deriving (Show,Eq)

data Producto = UnProducto {descripcion::String, 
precio::Float, 
moneda::String
} deriving (Show,Eq)  

cacho:: Persona
cacho = UnaPersona {
    nombre = "pedro",
     cuenta = [(100, "peso"), (400, "real"), (1, "dolar")],
     nivelDeSatisfaccion = 4
    } 

tita :: Persona
tita = UnaPersona{
    nombre = "juana",
    cuenta = [(1000, "euro"), ((-5), "peso")],
    nivelDeSatisfaccion= 2
    }


cotizaciones :: [(Float,String)]
cotizaciones = [(1, "peso"), (9, "dolar"), (4, "real"), (8,"euro")]

--1) 
--a)
tipoCambio moneda = map (fst) (filter ((moneda==).snd) cotizaciones) !!0

--b) 
convertirA :: String -> (Float, String) -> Float
convertirA obtengo recibo = fst recibo * tipoCambio obtengo 

--c) 
cantidadDe moneda persona =  map (fst) (filter ((moneda==).snd) (cuenta persona))

--d) 
pasarAPeso = convertirA "peso" 
totalAhorro persona = map (pasarAPeso) (cuenta persona)

--Ejercicio 2 
