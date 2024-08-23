/*
* ------------------------------------------------------------
* dos_variables.c
* Este código demuestra el uso de las cláusulas shared y private en OpenMP
* ------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* CC3086 - Programacion de Microprocesadores
*
* Description:
* El programa utiliza OpenMP para ejecutar un bucle for en paralelo, modificando
* dos variables: una compartida entre hilos y otra privada para cada hilo.
* ------------------------------------------------------------
*/

#include <stdio.h>
#include <omp.h>

int main() {
    int variable1 = 0; // Variable compartida
    int variable2 = 0; // Variable privada (inicializada en el bucle)

    // Establece el número de hilos
    omp_set_num_threads(4);

    // Inicia el ciclo for paralelo
    #pragma omp parallel for shared(variable1) private(variable2)
    for (int i = 0; i < 10; i++) {
        variable2 = i; // Asignar un valor a variable2
        variable1 += i; // Modificar variable1

        printf("Thread %d - i: %d, variable1: %d, variable2: %d\n",
               omp_get_thread_num(), i, variable1, variable2);
    }

    // Resultado final de variable1 después del bucle paralelo
    printf("Valor final de variable1: %d\n", variable1);

    return 0;
}
