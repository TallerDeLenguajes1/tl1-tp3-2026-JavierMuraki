#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CantNombres 5

// Recibe el vector para mostrar todos los nombres alamcenados
void MostrarPersonas(char *Vector[]);

// Busca el nombre mediante ID
void BuscarNombre(char *Vector[], int id);

int main() {
    char *Buff = (char *) malloc(sizeof(char) * 128); // Variable auxiliar
    char *V[CantNombres];
    int i;

    printf("\nIngrese %d nombres:\n", CantNombres);
    for (i = 0; i < CantNombres; i++) {
        gets(Buff);
        V[i] = (char *) malloc(sizeof(char) * (strlen(Buff) + 1));
        strcpy(V[i], Buff);
    }

    // Ej 2 / Parte 1 / Apartado 2
    MostrarPersonas(V);

    // Ej 2 / Parte 2 / Apartado 1
    int id;

    fflush(stdin); // Limpia el buffer del input de la consola
    printf("\nIngrese una ID para buscar (1 - %d): ", CantNombres);
    scanf("%d", &id);

    BuscarNombre(V, id);

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

void BuscarNombre(char *Vector[], int id) {
    if (id >= 1 && id <= CantNombres ) {
        printf("Nombre encontrado: %s\n", Vector[id - 1]);
    } else {
        printf("No se encontro el valor buscado\n");
    }
}