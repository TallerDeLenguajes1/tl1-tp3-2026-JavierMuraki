#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CantNombres 5

// Recibe el vector para mostrar todos los nombres alamcenados
void MostrarPersonas(char *Vector[]);

// Buscar nombre por string
int BuscarNombre(char *Vector[], char str[]);

int main() {
    char *Buff = (char *) malloc(sizeof(char) * 128); // Variable auxiliar
    char *V[CantNombres];
    int i;

    printf("Ingrese %d nombres:\n", CantNombres);
    for (i = 0; i < CantNombres; i++) {
        gets(Buff);
        V[i] = (char *) malloc(sizeof(char) * (strlen(Buff) + 1));
        strcpy(V[i], Buff);
    }

    // Ej 2 / Parte 1 / Apartado 2
    MostrarPersonas(V);

    // Ej 2 / Parte 2 / Apartado 2
    printf("\nIngrese nombre a buscar: ");
    gets(Buff);

    int resultado = BuscarNombre(V, Buff);

    if (resultado != -1) {
        printf("Se encontro el nombre: %s\n", V[resultado]);
    } else {
        printf("No se encontro el valor buscado\n");
    }

    // Liberar memoria
    free(Buff);
    for (i = 0; i < CantNombres; i++) {
        free(V[i]);
    }

    return 0;
}

void MostrarPersonas(char *Vector[]) {
    int i;

    printf("\nNombres almacenados:\n");
    for (i = 0; i < CantNombres; i++) {
        printf("%d - %s\n", i + 1, Vector[i]);
    }
}

int BuscarNombre(char *Vector[], char str[]) {
    int i;

    for (i = 0; i < CantNombres; i++) {
        if (strstr(Vector[i], str)) {
            return i; // Toda la funcion se detiene al retornar
        }
    }

    return -1; // Si no encontro nada entonces retornara -1
}