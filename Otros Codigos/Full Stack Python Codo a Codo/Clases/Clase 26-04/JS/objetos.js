var persona = { //Los objetos son una variable
    nombre : "Juan",
    apellido : "Perez",
    dni: 1234,
    datosPersona: function(){  //Una forma de declarar funciones
         return this.nombre + " " + this.apellido;
    },
    datoDNI(){    //Otra forma de declarar funciones
        return "El DNI es: " + this.dni
    }

 }

 console.log(persona.nombre)
console.log(persona)
console.log(persona.toString())
texto  ="Hola mundo"
console.log(texto.toString())
console.log(persona.datosPersona())
console.log(persona.datoDNI())

class Perro{
    constructor(nombre,edad){
        this.nombre = nombre
        this.edad = edad
    }
}

var perro1 = new Perro("Popei",14)
var perro2 = new Perro("Popei",14) //Aunque perro 1 y perro2 tienen los mismos valores, son objetos distintos. 
//Los estados son las caracteristicas(valores) que tiene el objeto en un momento dado

perro1.nombre = "Feli";
perro2.edad= 16; //Forma 1 de modificar el valor de un atributo
perro2['edad'] = 16 //Forma 2, esta linea y la anterior hacen lo mismo 
console.log(perro1.nombre)
console.log(perro2.nombre)

//string
texto1 = "Hola mundo!";
var texto2 = new String("Hola Tomi"); //Otra forma de crear un string. Cuando se lo declara como variable me sugiere las funciones que puedo aplicarle
texto3 = new String(123); //Me devuelve "123" como string

//como está declarado como var, me sugiere las funciones que pueden realizar(Como length,charAt) si no lo pongo, no las sugiere

//Propiedades
console.log(texto2.length); //Largo

//Metodos
console.log(texto2.charAt(0))//Obtener caracter en posicion
console.log(texto2[1])//Otra forma de obtener el caracter en posicion
console.log(texto2.replace('Hola',"HOLA")) //Como no puedo modificar el original, ya que los objetos de tipo string no son mutables, creo un nuevo objeto con base del texto creado y reemplazo por la palabra que quiera. Es un objeto nuevo. El array es mutable.
console.log(texto2.split(" "))//Separa la cadena segun un caracter y me devuelve las separaciones contenidas en un array. Convierte de un tipo de objeto a otro

//Document Para verlo en el navegador 
document.write("Hola Mundo! <br>")
document.write(texto2.toUpperCase() + "<br>")
document.write(texto2.substring(1,4) + "<br>")//El valor 4 no es inclusivo, imprime del 1 al 3


