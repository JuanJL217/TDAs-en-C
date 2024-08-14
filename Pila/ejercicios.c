#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

void MandarAlInicio(Pila* pila, void* numero) {
    if (EstaVacio(pila)) {
        Apilar(pila, numero);
        return;
    }
    void* desapilado = (void*) Desapilar(pila);
    MandarAlInicio(pila, numero);
    Apilar(pila, desapilado);
}

int main() {
    printf("xd\n");
    Pila* miPila = CrearPila();
    printf("no\n");
    int a = 1, b = 2, c = 3, d = 4, alFondo = 5;
    Apilar(miPila, &a);
    Apilar(miPila, &b);
    Apilar(miPila, &c);
    Apilar(miPila, &d);
    MandarAlInicio(miPila, &alFondo);
    
    while (!EstaVacio(miPila)) {
        int* desapilado = (int*) Desapilar(miPila);
        printf("%i\n", *desapilado);
    }
    DestruirPila(miPila);
    return 0;
}

// Para compilar, en la termina debes hacer:
// gcc pilaEnlazada.c ejercicios.c -o programa (o el nombre que le quieras dar al programa)
// Si se te dara un .exe con el nombre programa.exe
// Abres el ejecutable excribiendo el ejecutable y tuki