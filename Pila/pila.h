#ifndef _PILA_H
#define _PILA_H

typedef struct nodo nodo_p;

struct nodo {
    void* valor;
    nodo_p* ant;
};

typedef struct pila {
    nodo_p* ultimo;
    int cantidad;
} Pila;

Pila* CrearPila();

void Apilar(Pila* pila, void* elemento);

void* Desapilar(Pila* pila);

int EstaVacio(Pila* pila);

void* VerTope(Pila* pila);

int Cantidad(Pila* pila);

void DestruirPila(Pila* pila);

#endif