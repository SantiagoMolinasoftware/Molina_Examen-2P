#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NumeroAlumnos 23
#define NumeroProgresos 3

// Funciones declaradas
void GenerarNotasAleatorias(int calificaciones[][NumeroProgresos]);
void MostrarNotasAlumnos(int calificaciones[][NumeroProgresos]);
void CalcularPromedioGrupo(int calificaciones[][NumeroProgresos]);
void EncontrarMejorEstudiante(int calificaciones[][NumeroProgresos]);