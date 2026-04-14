#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *Buff = (char *) malloc(sizeof(char) * 128); // Variable auxiliar
    char *V[5];
    int i;

    printf("Ingrese 5 nombres:\n");
    for (i = 0; i < 5; i++) {
        gets(Buff);
        V[i] = (char *) malloc(sizeof(char) * (strlen(Buff) + 1));
        strcpy(V[i], Buff);
    }

    // Liberar memoria
    free(Buff);
    for (i = 0; i < 5; i++) {
        free(V[i]);
    }

    return 0;
}