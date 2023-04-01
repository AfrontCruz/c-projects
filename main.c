#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main(){
    // el primer elemento
    Pila *pila = NULL;
    // el ultimo elemento
    Pila* ultimo = NULL;

    int opcion = 1;
    while(opcion != 0){
        printf("Que operacion realiza: \n1. Insertar\n2. Eliminar\n3. Leer\n4. Salir\n\n");
        scanf("%i", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Insertando...\n");
            insertar(pila, ultimo);
            break;
        case 2: 
            printf("Eliminando...\n");
            ultimo = removerItem(pila);
            break;
        case 3:
            leerProductos(pila);
            printf("Leer...\n");
            break;
        case 4:
            printf("Saliendo...\n");
            opcion = 0;
            break;
        default:
            opcion = 1;
            break;
        }
    }
    return 0;
}

void insertar(Pila* inicio, Pila* ultimo){
    // Pedir datos
    char nombre[100];
    float precio;
    float stock;
    int id;

    scanf("%s",nombre);
    scanf("%f",&precio);

    Producto nuevo;
    ultimo = agregarItem(ultimo, nuevo);
    if(inicio == NULL){
        inicio = ultimo;
    }
}

void leerProductos(Pila* pila){
    Pila* aux = pila;
    // Listar nuestros productos
    while(aux != NULL){
        Producto item = aux->item;
        // printf("Nombre: %s \nPrecio: %f, \nStock: %f, \nID: %i\n\n", item.nombre, item.precio, item.stock, item.id);
        printf("Nombre: %s ID: %i\n\n", item.nombre, item.id);
        aux = aux->siguiente;
    }
}

// Pop
// Regresa el ultimo elemento
Pila* removerItem(Pila* pila){
    Pila* aux = pila;
    // Si la pila no existe regresa NULL
    if(aux == NULL){
        return NULL;
    }
    // Si la pila solo tiene un elemento regreso NULL
    else if(aux->siguiente == NULL){
        return NULL;
    }
    else{
        // Comprobamos que el siguiente elemento sea el ultimo
        if(aux->siguiente->siguiente == NULL){
            printf("La pila ahora esta vacia\n");
            aux->siguiente = NULL;
            return aux;
        }
        removerItem(aux->siguiente);
    }
}


// Push
// Regresa el ultimo elemento
Pila* agregarItem(Pila* pila, Producto producto){
    Pila *aux = (Pila*)malloc(sizeof(Pila));
    aux->item = producto;
    aux->siguiente = NULL;
    if(pila == NULL){
        // este seria el primer elemento de la pila
        return aux;
    }
    else{
        // en el elemento actual le pongo el siguiente como este nuevo elemento
        pila->siguiente = aux;
    }
    return aux;
}