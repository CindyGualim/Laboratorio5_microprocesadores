/*
* ------------------------------------------------------------
* tres_funciones.c
* Este código ejecuta tres funciones diferentes en paralelo usando OpenMP
* ------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* CC3086 - Programacion de Microprocesadores
*
* Description:
* El programa utiliza la directiva #pragma omp sections para ejecutar tres
* funciones distintas en paralelo. Cada sección ejecuta una tarea independiente:
* calcular factorial, generar serie de Fibonacci y encontrar el máximo en un arreglo.
* ------------------------------------------------------------
*/

#include <stdio.h>
#include <omp.h>

// Función para calcular el factorial de un número
void calcular_factorial(int n) {
    long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    printf("Factorial de %d es: %lld\n", n, factorial);
}

// Función para generar la serie de Fibonacci hasta un número dado
void generar_fibonacci(int n) {
    long long a = 0, b = 1, c;
    printf("Serie de Fibonacci hasta %d términos: %lld %lld ", n, a, b);
    for (int i = 3; i <= n; i++) {
        c = a + b;
        printf("%lld ", c);
        a = b;
        b = c;
    }
    printf("\n");
}

// Función para encontrar el máximo en un arreglo
void encontrar_maximo(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("El máximo en el arreglo es: %d\n", max);
}

int main() {
    int n_factorial = 10; // Número para calcular el factorial
    int n_fibonacci = 10; // Número de términos de la serie de Fibonacci
    int arreglo[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3}; // Arreglo para encontrar el máximo
    int size_arreglo = sizeof(arreglo) / sizeof(arreglo[0]); // Tamaño del arreglo

    // Inicio de la región paralela con secciones
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            calcular_factorial(n_factorial);
        }

        #pragma omp section
        {
            generar_fibonacci(n_fibonacci);
        }

        #pragma omp section
        {
            encontrar_maximo(arreglo, size_arreglo);
        }
    }

    return 0;
}
