#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CLIENTES 5
#define MAX_PRODUCTOS 10

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // Entre 1 y 10
    char *TipoProducto; // AlgUn valor del arreglo TiposProductos
    float PrecioUnitario; // Entre 10 - 100
};

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (Aleatorio entre 1 y 5)
    struct Producto *Productos; // El tamaño de este arreglo depende de la variable
};

// Ejercicio 3 / Apartado IV
float CalcularCostoTotal(struct Producto P) {
    return (float) P.Cantidad * P.PrecioUnitario;
}

int main() {
    int i, j;
    int CantidadCleintes;
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    srand(time(NULL));

    printf("Cuantos clientes (1 - %d): ", MAX_CLIENTES);
    fflush(stdin);
    scanf("%d", &CantidadCleintes);

    if (CantidadCleintes >= 1 && CantidadCleintes <= MAX_CLIENTES) {
        struct Cliente *Clientes = (struct Cliente *) malloc(sizeof(struct Cliente) * CantidadCleintes);
        char *Buffer = (char *) malloc(sizeof(char) * 128);

        for (i = 0; i < CantidadCleintes; i++) {
            Clientes[i].ClienteID = i + 1;

            printf("Inserte nombre para el Cliente %d: ", i + 1);
            fflush(stdin);
            gets(Buffer);

            Clientes[i].NombreCliente = (char *) malloc(sizeof(char) * (strlen(Buffer) + 1));
            strcpy(Clientes[i].NombreCliente, Buffer);

            Clientes[i].CantidadProductosAPedir = rand() % 10 + 1;
            Clientes[i].Productos = (struct Producto *) malloc(sizeof(struct Producto) * Clientes[i].CantidadProductosAPedir);

            for (j = 0; j < Clientes[i].CantidadProductosAPedir; j++) { // Carga de productos
                struct Producto *P = &(Clientes[i].Productos[j]);
                P->ProductoID = j + 1;
                P->Cantidad = rand() % 10 + 1;
                P->TipoProducto = TiposProductos[rand() % 5];
                P->PrecioUnitario = 10 + rand() % (100 - 10 + 1); // MIN + rand() % (MAX - MIN + 1)

                printf("- Producto cargado N.%d\n", j + 1);
                printf("- Cantidad: %d\n", P->Cantidad);
                printf("- Tipo: %s\n", P->TipoProducto);
                printf("- Precio Unitario: $%.2f\n\n", P->PrecioUnitario);
            }
        }


        // Ejercicio 3 / Apartado V
        printf("\n\n----------------------------------------------\n");
        for (i = 0; i < CantidadCleintes; i++) {
            float TotalPagar = 0;

            printf("- ID del Cliente: %d\n", Clientes[i].ClienteID);
            printf("- Nombre: %s\n", Clientes[i].NombreCliente);
            printf("- Productos pedidos: %d\n", Clientes[i].CantidadProductosAPedir);
            printf("- Prodctos:\n");
            for (j = 0; j < Clientes[i].CantidadProductosAPedir; j++) {
                struct Producto P = Clientes[i].Productos[j];
                printf("    - Producto N.%d\n", j + 1);
                printf("    - Cantidad: %d\n", P.Cantidad);
                printf("    - Tipo: %s\n", P.TipoProducto);
                printf("    - Precio Unitario: $%.2f\n\n", P.PrecioUnitario);
                TotalPagar += CalcularCostoTotal(P);
            }

            printf("- Total a pagar: $%.2f\n", TotalPagar);
            printf("----------------------------------------------\n");
        }


        // Liberar Memoria
        for (i = 0; i < CantidadCleintes; i++) {
            free(Clientes[i].Productos);
        }
        free(Buffer);
        free(Clientes);
    } else {
        printf("Clientes fuera de rango");
    }

    return 0;
}