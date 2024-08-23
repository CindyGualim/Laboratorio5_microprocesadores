/*
* ------------------------------------------------------------
* SumaForparalelo.c
* ------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* CC3086 - Programacion de Microprocesadores
*
* Description:
* Este programa utiliza un bucle paralelo para calcular la suma de los primeros
* N números naturales. La cláusula reduction se usa para asegurar que la suma
* sea acumulada correctamente por todos los threads.
* ------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

const int N = 1000000; // Definición de N

int main(int argc, char* argv[])
{
    // Variables para medir el tiempo de ejecución
    double start_time, end_time;
    long long suma_total = 0;

    // Inicio de la región paralela
    #pragma omp parallel
    {
        // Medir tiempo solo una vez usando directiva single
        #pragma omp single
        {
            start_time = omp_get_wtime();
        }

        // Calcular la suma en paralelo
        #pragma omp for reduction(+:suma_total)
        for (int i = 1; i <= N; i++) {
            suma_total += i;
        }

        // Medir tiempo de finalización
        #pragma omp single
        {
            end_time = omp_get_wtime();
        }

    }

    // Imprimir el resultado y el tiempo de ejecución
    printf("La suma de los primeros %d números naturales es: %lld\n", N, suma_total);
    printf("Tiempo de ejecución: %f segundos\n", end_time - start_time);

    return 0;
}
