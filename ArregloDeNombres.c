#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CantNombres 5

// Recibe el vector para mostrar todos los nombres alamcenados
void MostrarPersonas(char *Vector[]);

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