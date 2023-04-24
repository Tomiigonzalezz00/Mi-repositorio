function sumar(num1,num2){
    let suma = num1 + num2 /* Ambito de aplicacion es el bloque de codigo donde fue definida, si fuera dentro de un for, la variable vive dentro del for */
    return suma;
    console.log(suma) /* Toda linea luego del return no se ejecuta */
}

/* resultado = sumar(10,2)
console.log(resultado)
console.log(sumar(10,3)) */

//parametros por defecto
function sumar3(num1,num2,num=0){
    let suma = num1 + num2+num
    resultado = sumar3(10,2,5)
    console.log(resultado)
    return suma
}

//let vs var
b = 2
function procesar(){ 
if(true){
    let a = 4;
    b = 2;  
}
    return a
}
//console.log(a) //da error de variable no declarada
console.log(b)

//Funciones flecha, se utiliza para funciones simples o breves, si solo tiene una linea puedo quitar las llaves
var sumar = (num1,num2) =>{
    let suma = num1+num2
    return suma
}
var sumarCorto = (num1,num2) => num1+num2

//Funcion anonima: la ventaja es uqe no ocupa espacio en memoria mas que el espacio de la variable, vive el tiempo que vive la variable, mas adelante en el codigo, podria reemplazar el valor de la variable  
var sumar = function(num1,num2){ //La funcion no recibe nombre, esta asociada a una variable
    return num1 + num2
}

var mostrar = function(texto){
    console.log(texto)
}


c = 100;
console.clear()
mostrar(sumar(10,5))
mostrar(sumar) //Muestra la definicion de la funcion

//Callbacks: Funcion que recibe como parametro otra funcion
function procesarEntrada(callback){
    let nombre = prompt("Ingrese su nombre: ")
    callback(nombre)
}

console.clear()

procesarEntrada(mostrar)

//clousures: Posibilidad de hacer referencia  aun valor que no esta definido dentro de la misma funcion
function crearFuncion(valorASumar){
    return function(num){
        return num + valorASumar;
    }
}

let sumar5 = crearFuncion(5)
const sumar10 = crearFuncion(10)

console.clear()
mostrar(sumar5)
mostrar(sumar10)
/* ƒ (num){
        return num + valorASumar;
    } */

    mostrar(sumar5(10))
    mostrar(sumar10(10)) 