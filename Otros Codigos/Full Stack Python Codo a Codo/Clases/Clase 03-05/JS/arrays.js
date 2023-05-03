//El array son objetos mutables

const nombres = ["Tomi","juan","Laura"]; //Lo constante es la referencia hacia el objeto, no el objeto en si 
var numeros = [1,2,3,4,50,-3,0];
let a1 = new Array(1,2,true,[1,1,12,33],"Hola mundo")
console.log(nombres);
console.log(numeros);

nombres.push("Sofia");
console.log(nombres);
console.log(a1[3]);
listNumeros = a1[3];

console.log(listNumeros[0]);

//Metodos
console.log(numeros.length);
numeros.push(1000,1001);
console.log(numeros.length);

const fruits  = ["Banana","Orange","Apple","Mango"]
console.log(fruits.slice(1,3)) //El segundo parametro no es inclusivo, va de 1 a 2

//Insertar
fruits.splice(0,1,"Pera")//Agregar insertando, desplazando los demas elementos, desde la posicion 0, inserta 1 elemento que es "Pera"
console.log(fruits);
//Eliminar
fruits.splice(0,1); //Elimina el elemento de la posicion 0, desde la posicion 0, elimina un elemento
console.log(fruits);
fruits.pop(); //Elimina el ultimo 

console.log(a1[a1.length-2][0])//Antepenultima posicion de Array, que contiene otro array

console.clear();
delete fruits[0];
console.log(fruits); //Pone el valor de la posicion 0 en "vacio"

//[1, 2, 3, 4, 50, -3, 0, 1000, 1001]
for(let i = 0; i<numeros,length; i++){
    let element = numeros[i];
    //element *= 2;
    numeros[i] *=2;
    //console.log(element);
}

console.log(numeros);

console.clear()

persona= {
    nombre : "Tomi",
    apellido : "Gonzalez"
}

//No todos los objetos son iterables
for (const key in numeros){ //En caso de numero, su key es la posiscion, por lo cual va a iterar las posciones del array
    numeros[key] *= 2;
}
console.log(numeros)

//For in se utiliza y me devuelve las posiciones(indices) del objeto evaluado
for (const key in persona){ 
    console.log(key)
}

//For of devuelve los valores dentro del indice del objeto evaluado
texto = "Hola mundo!"
for (const valor of texto){   //Voy guardando un valor, sirve para los objetos iterables, que se puede recorrer accediendo al valor de sus valores
    console.log(valor)
}

listaValores = new Array(numeros.values());
console.log(numeros.values());

//Ordenamiento de arrays
fruits.reverse()
console.log(fruits)


fruits.sort() //Predefinidamente ordena de menor a mayor
console.log(fruits)

fruits.sort(function(a,b){return b-a}) //A sort se le puse pasar una funcion en base a la cual ordenara es un CALLBACKS
console.log(numeros)

function mult(elem,i,arr){
    arr[i] = elem*10
}

numeros.forEach(mult); //Le paso la funcion multiplicar a cada elemento 
console.log(numeros);

nuevoNumeros = numeros.map((num) => num*10);
console.log(nuevoNumeros);


//Ejemplo
console.clear()
function esMayor(e){
    return e >= 18;
}

//Detecto menores de edad en el evento
edades = [17,18,20,16];
console.log(edades.some(esMayor)) //Devuelve true ya que uno cumple
console.log(edades.every(esMayor)) //Devuelve false ya que no todos cumplen

//Local storage
localStorage.setItem("nombre","Tomas "); //Guarda de forma local este valor, me permite compartir datos entre distintos javascript, se mantiene a pesar que se cierre la ventana del navegador, aunque se comente esta linea
nom = localStorage.getItem("nombre"); 
document.write(nom);

sessionStorage.setItem("Apellido", "Gonzalez")//Guarda el dato pero dura lo que dura la sesion, si cierro el navegaodr se pierde, si comenta esta linea ya no esta
apel = sessionStorage.getItem("Apellido")
document.write(apel)

//document.getElementById("miDiv").innerText = nom; //Puedo modificar el html desde el javascript, hay que corregir
