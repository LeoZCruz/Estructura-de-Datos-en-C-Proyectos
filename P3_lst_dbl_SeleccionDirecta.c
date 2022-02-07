#include "P3_lst_dbl_SeleccionDirecta.h"
/**
*INTEGRANTES:
*CEDILLO CRUZ ERIK LEONEL
*FLORES DE LA ROSA AXEL YAEL
*GONZALEZ SAN JUAN ALEXIS
*/

int main()
{
    Nodo *Lista = NULL;
    menu(Lista);
    return 0;
}

void menu(Nodo* Lista){

    printf("Programa para realizar el ordenamiento de autos, mediante Seleccion directa\n");
    printf("Programa para ordenar datos ALFABETICAMENTE segun el color.\n");
    printf("SE ESTA CREANDO LA LISTA DE AUTOS...\n");
    Lista=Leer(Lista);
    printf("\n");
    mostrarLista(Lista);
    printf("PRESIONA ENTER PARA CONTINUAR:\n");
    system("pause");
    system("cls");
    printf("SE ESTA ORDENANDO LA LISTA DE AUTOS.TXT...\n");
    Ordenar(Lista);
    Escribir(Lista);
    printf("SEA ORDENADO LA LISTA...\n");
    mostrarLista(Lista);
    printf("ORDEN EXITOSO SE GUARDO EN SALIDAORDENADA.TXT:\n");

}


