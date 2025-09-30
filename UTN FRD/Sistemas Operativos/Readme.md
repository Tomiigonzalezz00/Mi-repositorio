Trabajos Prácticos de Sistemas y Programación Concurrente

Este repositorio contiene los ejercicios prácticos realizados durante la carrera relacionados con procesos, hilos, sincronización y programación concurrente en C/C++ y sistemas Unix/Linux.

Contenido de los ejercicios
1. Shell con soporte de procesos foreground y background

  Implementación de un programa Shell completo que:

  Soporta ejecución de procesos en foreground y background.

  Utiliza la señal SIGCHLD para verificar la finalización de procesos en background.

  Evita la existencia de procesos zombies.

  El programa finaliza al ingresar el comando salir.

  Si el usuario presiona CTRL+C, el programa espera a que terminen todos los procesos antes de finalizar, sin dejar procesos huérfanos    o zombies.

2. Creación de procesos hermanos con retorno de valores

Programa que crea un número de procesos indicado por línea de comandos, todos hermanos.

Cada hijo retorna un valor entero único al padre.

Los procesos hijos permanecen en un loop eterno de espera no activa, hasta recibir las señales SIGUSR1 o SIGINT, momento en el cual terminan retornando su valor.

El proceso padre imprime la sumatoria de los retornos de los hijos.

No se permiten procesos huérfanos ni zombies.

3. Sincronización de hilos con mutex

Sincronización de los hilos A, B y C para ejecutar la secuencia ABAC....

El número de iteraciones completas N se ingresa por línea de comandos.

Se utiliza Mutex (librería pthread) para controlar el acceso a la sección crítica.

4. Sincronización de procesos con semáforos Posix con nombre

Sincronización de procesos independientes A, B y C para ejecutar la secuencia ABAC....

Se detiene luego de N iteraciones completas (ingresadas por línea de comandos).

Se utiliza semáforos Posix con nombre para la sincronización.

5. Sincronización de procesos con semáforos Posix sin nombre

Igual que el ejercicio anterior, pero usando semáforos Posix sin nombre.

6. Sincronización de procesos con semáforos SVR4

Igual que el ejercicio anterior, pero utilizando semáforos SVR4.

7. Sincronización de procesos emparentados

Procesos PadreA, HijoB y HijoC, donde HijoB e HijoC son hermanos.

Secuencia de ejecución: PadreAHijoBPadreAHijoC....

Se detiene luego de N iteraciones completas (ingresadas por línea de comandos).

La sincronización se implementa sin usar señales, con la técnica más adecuada según el criterio del desarrollador.

8. Sincronización de hilos para suma de columnas de matriz

Matriz M de 4 filas y 3 columnas y vector T[3] inicializado en -1.

Hilos:

hiloQueLlenaMatriz: llena la matriz con números aleatorios de dos cifras.

hiloQueSumaColumna1, hiloQueSumaColumna2, hiloQueSumaColumna3: cada uno suma su columna, espera que hiloQueLlenaMatriz termine y verifica disponibilidad de otros totales. Si todos están listos, señala variable de condición V.

hiloQueMuestraTotalGeneral: espera la variable de condición V y muestra la suma total de todas las columnas.

Se implementa sincronización con variables de condición y mutex.

9. Ejecución de comandos con pipe

Programa que recibe por línea de comandos un comando y sus argumentos.

Crea un proceso hijo que ejecuta el comando y un proceso padre que lee la salida del comando.

Se utiliza pipe y las funciones dup() o dup2() para redirigir la salida.

No se permite usar popen().

Se evita la creación de procesos huérfanos o zombies.

10. Sistema de Monitoreo Distribuido

Implementación de un monitor de sistema mediante una aplicación web sencilla.

La página index.html contiene links para ejecutar distintos comandos del sistema operativo (ls, ipcs, df, ps, free, etc.) y mostrar información relevante al operador.
