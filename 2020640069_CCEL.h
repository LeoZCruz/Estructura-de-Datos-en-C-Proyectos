#ifndef _PILAS_H_
#define _PILAS_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{

    int dato;
    struct nodo *siguiente;

}NODO;

NODO* CrearNodo(int dato);
NODO* Apilar(NODO* top,int dato);
NODO* DesApilar(NODO* top);
void MostrarPila(NODO* top);

NODO* CrearNodo(int dato){

    NODO *nuevo = NULL;
    nuevo = (NODO*)malloc(sizeof(NODO));
    if(nuevo != NULL){

        nuevo->dato = dato;
        nuevo->siguiente = NULL;
    }
    return nuevo;

}

NODO* Apilar(NODO* top,int dato){

    NODO* nuevo = NULL;
    nuevo = CrearNodo(dato);
    if(nuevo != NULL){

        nuevo->siguiente=top;
        return nuevo;

    }
    return nuevo;
}

NODO* DesApilar(NODO* top){

    NODO* nAux = NULL;
    nAux = top;
    if(top != NULL){
        top=top->siguiente;
        free(nAux);
        return top;
    }
    return top;
}

void MostrarPila(NODO* top){

    if(top == NULL){
        printf("La PILA esta vacia...\n");
    }else{
        while(top!= NULL){
            printf("La PILA contiene:... %d\n",top->dato);
            top = top->siguiente;
        }
    }
}

int ContarElemento(NODO *top){

    int cont = 0;
    if(top == NULL){
        cont = 0;
    }else{
        while(top!= NULL){
            cont++;
            top = top->siguiente;
        }
    }
    return cont;
}

int CalcularSuma(NODO *top){

    int suma;
    if(top->siguiente == NULL){
        suma = 0;
    }else{
       int suma= top->siguiente->dato + top->dato;
       return suma;
    }
    return suma;
}

int CalcularResta(NODO *top){

    int resta;
    if(top->siguiente == NULL){
        resta = 0;
    }else{
       int resta= top->siguiente->dato - top->dato;
       return resta;
    }
    return resta;
}

int CalcularProducto(NODO *top){

    int producto;
    if(top->siguiente == NULL){
        producto = 0;
    }else{
       int producto = top->siguiente->dato * top->dato;
       return producto;
    }
    return producto;
}

int CalcularCociente(NODO *top){

    int cociente;
    if(top->siguiente == NULL){
        cociente = 0;
    }else{
       int cociente= top->siguiente->dato / top->dato;
       return cociente;
    }
    return cociente;
}

#endif // _PILAS_H_
