/*
 * Archivo: Ej_5_Paralela.c
 * Descripción: Versión paralela del programa para contar cuántas veces 
 * aparece un valor específico ('key') en un arreglo de números aleatorios 
 * utilizando OpenMP y descomposición de tareas recursiva.
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 131072

// Función recursiva paralela para contar apariciones de 'key'
long count_key_parallel(long *a, long key, long start, long end) {
    long count = 0;

    // Si la sección es pequeña, realizar la cuenta secuencialmente
    if (end - start < 1000) {
        for (long i = start; i < end; i++) {
            if (a[i] == key) count++;
        }
    } else {
        long mid = start + (end - start) / 2;
        long left_count = 0, right_count = 0;

        // Crear tareas para la mitad izquierda y derecha
        #pragma omp task shared(left_count)
        left_count = count_key_parallel(a, key, start, mid);

        #pragma omp task shared(right_count)
        right_count = count_key_parallel(a, key, mid, end);

        // Esperar a que ambas tareas terminen
        #pragma omp taskwait
        count = left_count + right_count;
    }

    return count;
}

int main() {
    long a[N], key = 42, nkey = 0;

    // Inicializar el arreglo con valores aleatorios
    for (long i = 0; i < N; i++) a[i] = rand() % N;

    // Insertar 'key' manualmente en posiciones específicas
    a[N % 43] = key;
    a[N % 73] = key;
    a[N % 3] = key;

    // Establecer número de hilos
    omp_set_num_threads(4);

    // Iniciar la región paralela y contar las apariciones de 'key' usando tareas
    #pragma omp parallel
    {
        #pragma omp single
        {
            nkey = count_key_parallel(a, key, 0, N);
        }
    }

    // Imprimir el número de apariciones de 'key'
    printf("Numero de veces que 'key' aparece en paralelo: %ld\n", nkey);

    return 0;
}
