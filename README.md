Este repositorio contiene una serie de programas escritos en C que implementan paralelismo utilizando la biblioteca OpenMP. Los programas exploran diferentes técnicas y directivas de OpenMP, como descomposición de tareas, bucles paralelos, variables compartidas/privadas, y secciones paralelas.

# Programas Incluidos
### Ej_5_Paralela.c
Este programa cuenta cuántas veces aparece un valor específico (key) en un arreglo de números aleatorios utilizando descomposición de tareas recursiva y OpenMP.
*Características:*
- Implementación recursiva paralela con la directiva `#pragma omp task.`
- Optimización para dividir el trabajo entre los hilos.
- Utiliza `#pragma omp taskwait` para sincronizar tareas.
  
*Entrada:*
- Un arreglo de números aleatorios generado automáticamente.
- Un valor clave `(key)` a buscar.

*Salida:*
- Número de veces que el valor aparece en el arreglo.
  
### SumaForparalelo.c
Calcula la suma de los primeros N números naturales utilizando un bucle paralelo con OpenMP.
*Características:*
- Uso de la cláusula `reduction` para acumular los resultados de todos los hilos.
- Mide el tiempo de ejecución con `omp_get_wtime.`
*Entrada:*
- Tamaño N (predefinido como 1,000,000).
*Salida:*
- Suma total de los números.
- Tiempo de ejecución.

### dos_variables.c
Demuestra el uso de las cláusulas shared y private en OpenMP. Utiliza un bucle paralelo para modificar dos variables: una compartida y otra privada para cada hilo.
*Características:*
- Comparación entre variables compartidas y privadas.
- Ejemplo educativo para entender el alcance de las variables en OpenMP.
*Entrada:*
- Ninguna (valores definidos en el código).
*Salida:*
- Valores de las variables después de cada iteración del bucle.
- Valor final de la variable compartida.

### tres_funciones.c
Ejecuta tres funciones diferentes en paralelo utilizando la directiva `#pragma omp sections`.
*Funciones:*
- Calcular factorial de un número.
- Generar serie de Fibonacci hasta un número dado.
- Encontrar el máximo en un arreglo.
*Características:*
- Ejecución independiente de cada función en una sección paralela.
- Ejemplo de división de tareas en OpenMP.
*Entrada:*
- Número para calcular el factorial.
- Cantidad de términos de Fibonacci.
- Arreglo de enteros.
*Salida:*
- Factorial del número.
- Serie de Fibonacci.
- Máximo del arreglo.

## Compilación y Ejecución
### Compilación 
````
gcc Ej_5_Paralela.c -o Ej_5_Paralela -fopenmp
gcc SumaForparalelo.c -o SumaForparalelo -fopenmp
gcc dos_variables.c -o dos_variables -fopenmp
gcc tres_funciones.c -o tres_funciones -fopenmp
````
### Ejecución
````
./Ej_5_Paralela
./SumaForparalelo
./dos_variables
./tres_funciones
```
