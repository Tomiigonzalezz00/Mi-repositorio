import Data.ByteString (elemIndex)
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

    
importe = fst 
nombreM = snd




cotizaciones :: [(Float,String)]
cotizaciones = [(1, "peso"), (9, "dolar"), (4, "real"), (8,"euro")]

--1) 
--a)
tipoCambio moneda = (fst.head.filter ((moneda==).nombreM)) cotizaciones

--b) 
convertirA :: String -> (Float, String) -> Float
convertirA obtengo (importe,tengo) = importe * tipoCambio tengo / tipoCambio obtengo 

--c) 

tieneMoneda moneda persona = any ((moneda==).nombreM) (cuenta persona)



cantidadDe :: String -> Persona -> [(Float, String)]
cantidadDe moneda persona
    | tieneMoneda moneda persona = filter ((moneda==).nombreM) (cuenta persona)
    | otherwise = 0


--d) 
pasarAPeso = convertirA "peso" 
totalAhorro persona = sum (map (pasarAPeso) (cuenta persona))

--Ejercicio 2 
