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

int main() 
{
    srand(time(NULL));

    int calificaciones[NumeroAlumnos][NumeroProgresos];

    // Generar aleatoriamente las notas
    GenerarNotasAleatorias(calificaciones);

    int opcion;
    do {
        // Mostrar menú
        printf("\nMENU:\n");
        printf("1. Mostrar notas de todos los alumnos.\n");
        printf("2. Mostrar nota promedio del grupo para cada progreso.\n");
        printf("3. Mostrar al alumno con mayor promedio durante el semestre.\n");
        printf("0. Salir.\n");
        printf("Ingrese la opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Mostrar notas de todos los alumnos
                MostrarNotasAlumnos(calificaciones);
                break;

            case 2:
                // Mostrar nota promedio del grupo para cada progreso
                CalcularPromedioGrupo(calificaciones);
                break;

            case 3:
                // Mostrar alumno con mayor promedio
                EncontrarMejorEstudiante(calificaciones);
                break;

            case 0:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}