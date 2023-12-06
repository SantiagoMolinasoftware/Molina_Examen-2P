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

void GenerarNotasAleatorias(int calificaciones[][NumeroProgresos]) {
    for (int i = 0; i < NumeroAlumnos; i++) {
        for (int j = 0; j < NumeroProgresos; j++) {
            calificaciones[i][j] = rand() % 10 + 1; // Notas aleatorias de 1 a 10
        }
    }
}

void MostrarNotasAlumnos(int calificaciones[][NumeroProgresos]) {
    char* nombres[NumeroAlumnos] = {"Mario", "Juan", "Ana", "Carlos", "Laura", "Diego", "Luis", "Sofia", "Pedro", "Elena",
                                     "Gabriel", "Isabel", "Mateo", "Valeria", "Fernando", "Lucia", "Alejandro", "Camila",
                                     "Javier", "Mariana", "Daniel", "Monica", "Ricardo"};

    // Mostrar notas de todos los alumnos
    for (int i = 0; i < NumeroAlumnos; i++) {
        printf("\n%d. %s\n", i + 1, nombres[i]);
        float promedioFinal = 0.0;

        for (int j = 0; j < NumeroProgresos; j++) {
            printf("P%d: %d/10\n", j + 1, calificaciones[i][j]);
            promedioFinal += calificaciones[i][j];
        }

        promedioFinal /= NumeroProgresos;
        printf("PF: %.2f\n", promedioFinal);
    }
}

void CalcularPromedioGrupo(int calificaciones[][NumeroProgresos]) {
    // Mostrar nota promedio del grupo para cada progreso
    for (int j = 0; j < NumeroProgresos; j++) {
        int suma = 0;
        for (int i = 0; i < NumeroAlumnos; i++) {
            suma += calificaciones[i][j];
        }
        float promedio = (float)suma / NumeroAlumnos;
        printf("Promedio del Grupo para el Progreso %d: %.2f\n", j + 1, promedio);
    }
}

void EncontrarMejorEstudiante(int calificaciones[][NumeroProgresos]) {
    char* nombres[NumeroAlumnos] = {"Mario", "Juan", "Ana", "Carlos", "Laura", "Diego", "Luis", "Sofia", "Pedro", "Elena",
                                     "Gabriel", "Isabel", "Mateo", "Valeria", "Fernando", "Lucia", "Alejandro", "Camila",
                                     "Javier", "Mariana", "Daniel", "Monica", "Ricardo"};

    float promedios[NumeroAlumnos];

    // Calcular promedio final de cada estudiante
    for (int i = 0; i < NumeroAlumnos; i++) {
        promedios[i] = 0.0;
        for (int j = 0; j < NumeroProgresos; j++) {
            promedios[i] += calificaciones[i][j];
        }
        promedios[i] /= NumeroProgresos;
    }

    // Encontrar al mejor estudiante
    int mejorEstudiante = 0;
    for (int i = 1; i < NumeroAlumnos; i++) {
        if (promedios[i] > promedios[mejorEstudiante]) {
            mejorEstudiante = i;
        }
    }

    printf("Mejor Estudiante: %s (PF: %.2f)\n", nombres[mejorEstudiante], promedios[mejorEstudiante]);
}
