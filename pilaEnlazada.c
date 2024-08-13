#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

nodo_p* nuevo_nodo(void* elemento) {
    nodo_p* nodo = malloc(sizeof(nodo_p));
    nodo->valor = elemento;
    nodo->ant = NULL;
    return nodo;
}

Pila* CrearPila() {
    Pila* nuevaPila = malloc(sizeof(Pila));
    nuevaPila->cantidad = 0;
    nuevaPila->ultimo = NULL;
    return nuevaPila;
}

void Apilar(Pila* pila, void* elemento) {
    nodo_p* nodo = nuevo_nodo(elemento);
    nodo->ant = pila->ultimo;
    pila->ultimo = nodo;
    pila->cantidad++;
}

int EstaVacio(Pila* pila) {
    if (pila->ultimo == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void* Desapilar(Pila* pila) {
    if (EstaVacio(pila) == 1) {
        return NULL;
    }
    nodo_p* elementoDesapilado = pila->ultimo;
    nodo_p* nuevoUltimo = elementoDesapilado->ant;
    pila->ultimo = nuevoUltimo;
    pila->cantidad--;
    return elementoDesapilado->valor;
}

void DestruirPila(Pila* pila) {
    while (!EstaVacio(pila)) {
        nodo_p* nodoLiberar = pila->ultimo;
        pila->ultimo = nodoLiberar->ant;
        free(nodoLiberar);
    }
    free(pila);
}

void* VerTope(Pila* pila) {
    return pila->ultimo->valor;
}

int Cantidad(Pila* pila) {
    return pila->cantidad;
}

int main() {

    Pila* miPila = CrearPila();
    int a = 1, b = 2, c = 3;

    Apilar(miPila, &a);
    Apilar(miPila, &b);
    Apilar(miPila, &c);

    int* valorDesapilado = (int*) Desapilar(miPila);
    printf("Desapilado: %i\n", *valorDesapilado);

    int* valor = (int*) VerTope(miPila);
    printf("El último valor es: %i\n", *valor);

    DestruirPila(miPila);

    return 0;
}