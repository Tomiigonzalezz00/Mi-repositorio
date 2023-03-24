import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) throws IOException {
        String ubicacion = "E:\\Github\\Github Desktop\\Mi-repositorio\\Otros Codigos\\Java Argentina Programa\\Actividades practicas\\Resolucion actividad 4\\Ejercicio 2\\numeros.txt";
        Scanner

        leerArchivo(ubicacion);

    }






    private static int[] leerArchivo(String ruta) throws IOException {

        int i = 0, lineas = Files.readAllLines(Paths.get(ruta)).size();
        int [] numeros = new int [lineas];
        for(String unaLinea : Files.readAllLines(Paths.get(ruta))) {
            i++;
            numeros[i] = Integer.valueOf(Files.readAllLines(Paths.get(ruta)).get(i));
        }
        return numeros;
    }

    private static int suma(int [] sumandos){
        int total=0;
        for(int i = 0;i< sumandos.length;i++){
            total = total + sumandos[i];
        }
        return total;
    }

    private static int multiplicacion(int [] factores){
        int total=1;
        for(int i = 0;i< factores.length;i++){
            total = total * factores[i];
        }
        return total;
    }
}

