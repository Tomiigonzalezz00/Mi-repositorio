import Data.List(delete)
import Data.ByteString (elemIndex)
type Dinero = (Float,String)
type Moneda = String 
type Importe = Float

data Persona = UnaPersona {
    nombre :: String,
    cuenta:: [Dinero],
    nivelDeSatisfaccion :: Int
}  deriving (Show,Eq)

data Producto = UnProducto {
descripcion::String, 
precio::Importe, 
moneda::Moneda
} deriving (Show,Eq)  

cacho:: Persona
cacho = UnaPersona {
    nombre = "pedro",
     cuenta = [(100, "peso"), (1, "dolar"), (400, "real")],
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




cotizaciones :: [Dinero]
cotizaciones = [(1, "peso"), (9, "dolar"), (4, "real"), (8,"euro")]

--1) 
--a)
tipoCambio :: String -> Float
tipoCambio divisa = (importe.head.filter (\moneda -> nombreM moneda == divisa )) cotizaciones


--Sin Expresion lamda: 
--tipoCambio moneda = (fst.head.filter ((moneda==).nombreM)) cotizaciones

--b) 
convertirA :: String -> (Float, String) -> Float
convertirA obtengo (importe,tengo) = importe * tipoCambio tengo / tipoCambio obtengo 

--c) 

tieneMoneda moneda persona = any ((moneda==).nombreM) (cuenta persona)


cantidadDe moneda persona
    | tieneMoneda moneda persona = (importe.head.filter ((moneda==).nombreM)) (cuenta persona)
    | otherwise = 0

--d) 
pasarAPeso = convertirA "peso" 
totalAhorro persona = sum (map (pasarAPeso) (cuenta persona))

--Ejercicio 2 
expresadoEn producto = moneda producto


alfajor = UnProducto {
    descripcion = "poderoso el chiquitin",
    precio = 10,
    moneda = "real"
}  

gaseosa = UnProducto {
    descripcion = "refrescante",
    precio = 15,
    moneda = "dolar"
}  


valorProducto = precio


descuentoValorDelProducto producto (importe,moneda)= (importe - precio producto, moneda)

sumaValorDelProducto producto (importe,moneda)= (importe + precio producto, moneda)

tieneDivisaDeProducto producto persona = head (filter ((moneda producto==).nombreM) (cuenta persona))

cantidadMoneda divisa = importe.head.filter (\moneda -> nombreM moneda == divisa)


comprar producto persona = persona {cuenta = delete (cantidadMoneda (moneda producto) (cuenta persona),moneda producto) (cuenta persona ++ map (descuentoValorDelProducto producto) (filter ((moneda producto==).nombreM) (cuenta persona)))}

vender producto persona = persona {cuenta = delete (cantidadMoneda (moneda producto) (cuenta persona),moneda producto) (cuenta persona ++ map (sumaValorDelProducto producto) (filter ((moneda producto==).nombreM) (cuenta persona)))}