Este repositorio contiene una serie de programas escritos en C que implementan paralelismo utilizando la biblioteca OpenMP. Los programas exploran diferentes técnicas y directivas de OpenMP, como descomposición de tareas, bucles paralelos, variables compartidas/privadas, y secciones paralelas.

# Programas Incluidos
### Ej_5_Paralela.c
Este programa cuenta cuántas veces aparece un valor específico (key) en un arreglo de números aleatorios utilizando descomposición de tareas recursiva y OpenMP.
*Características:*
- Implementación recursiva paralela con la directiva `#pragma omp task.`
- Optimización para dividir el trabajo entre los hilos.
- Utiliza ´#pragma omp taskwait´ para sincronizar tareas.
