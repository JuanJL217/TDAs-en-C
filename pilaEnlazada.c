#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

// En primera, no manejo errores, lo cual deberia seria return NULL


// Función para crear un nodo
nodo_p* nuevo_nodo(void* elemento) {
    nodo_p* nodo = malloc(sizeof(nodo_p)); //crea un espacio en memoria del tipo nodo_p (la estructura del nodo)
    nodo->valor = elemento;
    nodo->ant = NULL;
    return nodo;
}

// Crear/inicializa la estructura de Pila, que está almacenado en 
//una dirección de memoria, de ahí porqué el puntero
Pila* CrearPila() {
    Pila* nuevaPila = malloc(sizeof(Pila));
    nuevaPila->cantidad = 0;
    nuevaPila->ultimo = NULL;
    return nuevaPila;
}

// Todas las funciones van a tener que tener como parametro el TDA puntero (Pila*)
void Apilar(Pila* pila, void* elemento) {
    nodo_p* nodo = nuevo_nodo(elemento);
    nodo->ant = pila->ultimo; //el nodo anterior va a ser igual al nodo ultimo que tiene la pila
    pila->ultimo = nodo; //y el nuevo ultimo va a ser el nodo
    pila->cantidad++;
}

// Cuando no haya elemento, el ultimo en la pila va a ser NULL
int EstaVacio(Pila* pila) {
    if (pila->ultimo == NULL) {
        return 1; // True
    } else {
        return 0; // False
    }
}

// Desapilamos el elemento que hallamos guardado con un void*
// El void* sirve como dato generico, asi que solo se maneja como un puntero sin importar qué tipo de dato tenga
// Cuando retornamos un elemento, retornamos un puntero a ese elemento
void* Desapilar(Pila* pila) {
    if (EstaVacio(pila) == 1) {
        return NULL; // Si esta vacio, no retorna nada, con eso solucionamos un problema
    }
    nodo_p* elementoDesapilado = pila->ultimo; //el elemento desapilado va a ser el nodo ultimo que Apilamos
    nodo_p* nuevoUltimo = elementoDesapilado->ant; // el nuevo ultimo va a ser el anterior del ultimo nodo que tuvimos
    pila->ultimo = nuevoUltimo; 
    pila->cantidad--;
    return elementoDesapilado->valor; // retornamos el valor, no la direccion de memoria, pero se reconoce que es un puntero, porque
                                      // la funciona retorna un void* (un generico)
}

// Esto es para que cuando cerremos el programa, destruyamos la Pila sin que haya fuga de memoria en el sistema
void DestruirPila(Pila* pila) {
    while (!EstaVacio(pila)) {
        nodo_p* nodoLiberar = pila->ultimo;
        pila->ultimo = nodoLiberar->ant;
        free(nodoLiberar);
    }
    free(pila);
}

// Así como usamos el void* para retornar el elemento que sacamos
// Con esta funcion solo mostramos el el puntero al valor, pero no eliminamos nada
void* VerTope(Pila* pila) {
    return pila->ultimo->valor;
}

// Muestra la variable cantidad que tenemos en la estructura
// Que es la cantidad de elementos en la pila
int Cantidad(Pila* pila) {
    return pila->cantidad;
}

int main() {

    // Se crea una variable con tipo de dato Pila*, es puntero porque la variable como tal no existe
    // Es una inicializacion de una estructura en memoria
    Pila* miPila = CrearPila();
    int a = 1, b = 2, c = 3;

    // Siempre pasamos la pila como parametro con la dirección de memoria de las variables
    // Pasamos la direccion de memoria de las variables, ya que en la función tenemos un void*
    // Que es un puntero generico
    Apilar(miPila, &a);
    Apilar(miPila, &b);
    Apilar(miPila, &c);

    // Desapilar retorna un puntero, así como pusimos ints, la funcion retorna un void* (generico)
    // En ese caso el void* es int*, ya que es una pila de int*
    // El (int*) es para despuntarlo y el puntero int* valorDesapilado tenga un valor
    int* valorDesapilado = (int*) Desapilar(miPila);
    printf("Desapilado: %i\n", *valorDesapilado); // Aca hacemos un *, porque apunta al valor, no a una direccion de memoria

    int* valor = (int*) VerTope(miPila);
    printf("El último valor es: %i\n", *valor);

    DestruirPila(miPila);

    return 0;
}