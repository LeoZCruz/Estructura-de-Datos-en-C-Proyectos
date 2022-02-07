#ifndef _P3_LST_DBL_SELECCIONDIRECTA_H_
#define _P3_LST_DBL_SELECCIONDIRECTA_H_
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
/**
*INTEGRANTES:
*CEDILLO CRUZ ERIK LEONEL
*FLORES DE LA ROSA AXEL YAEL
*GONZALEZ SAN JUAN ALEXIS
*/
typedef struct _Nodo
{
char marca[20];
char color[20];
char placa[10];
struct _Nodo *sig;
struct _Nodo *ant;
}Nodo;
Nodo *asignar(char marca[20],char color[20], char placa[10]){
    Nodo *Nuevo;
    Nuevo=(Nodo*)malloc(sizeof (Nodo));
    strcpy(Nuevo->marca,marca);
    strcpy(Nuevo->color,color);
    strcpy(Nuevo->placa,placa);


    Nuevo->sig=NULL;
    Nuevo->ant=NULL;
    return Nuevo;
}

Nodo *insertarAlInicio(Nodo *lista,char marca[20],char color[20], char placa[10]){
    Nodo *Nuevo;
    Nuevo=asignar(marca, color, placa);
    if(lista!=NULL)
    {
        Nuevo->sig=lista;
   		lista->ant=Nuevo;
    }
    return Nuevo;
}
int noElementos(Nodo *lista){
    int resultado=0;
    if(lista==NULL)
    {
        return 0;
    }
    else
    {
        while(lista!=NULL)
        {
            lista=lista->sig;
            resultado++;
        }
    }
    return resultado;
}
void mostrarLista(Nodo *lista){
    if(lista==NULL)
    {
        printf("LA LISTA NO TIENE ELEMENTOS\n");
    }
    else
    {
        while(lista!=NULL)
        {
            printf("%s\t%s\t%s\n",lista->marca,lista->color,lista->placa);

            lista=lista->sig;
        }
        printf("\n");
    }
}
Nodo *Escribir(Nodo *lista){

    char marca[20];
    char color[20];
    char placa[10];
    FILE *archivo = fopen("salidaOrdenada.txt","a");
    if(archivo==NULL){
        printf("No se pudo abrir el archivo\n");
    }else{
        if(lista == NULL){
            return 0;
            printf("No se puedo\n");
        }else{
            while(lista != NULL){
                strcpy(marca,lista->marca);
                strcpy(color,lista->color);
                strcpy(placa,lista->placa);
                fprintf(archivo,"%s\t%s\t%s\n",marca,color,placa);
                lista = lista->sig;
            }

        }

    }

    fclose(archivo);
    return lista;
}
Nodo *Leer(Nodo *lista){

    int dato;
    char marca[20];
    char color[20];
    char placa[10];
    FILE *archivo = fopen("autos.txt","r");

    if(archivo == NULL){
        return NULL;
    }else{
        while(feof(archivo)== NULL){
            fscanf (archivo,"%s\t%s\t%s\n",marca,color,placa);
            lista = insertarAlInicio(lista,marca,color,placa);
        }
        return lista;
        }
    fclose(archivo);
}
Nodo *Ordenar(Nodo *lista){
    Nodo* actual;
    Nodo* siguiente;
    char tempColor[20];
    char tempMarca[20];
    char tempPlaca[20];
    actual = lista;

    if(lista==NULL)
    {
        printf("LA LISTA NO TIENE ELEMENTOS\n");
    }
    else
    {
     while(actual->sig != NULL)
     {
          siguiente = actual->sig;
          while(siguiente!=NULL)
          {
                if(strcmp(actual->color , siguiente->color)>0)
                {
                    strcpy(tempColor,siguiente->color);
                    strcpy(tempMarca,siguiente->marca);
                    strcpy(tempPlaca,siguiente->placa);
                    strcpy(siguiente->color,actual->color);
                    strcpy(siguiente->marca,actual->marca);
                    strcpy(siguiente->placa,actual->placa);
                    strcpy(actual->color,tempColor);
                    strcpy(actual->marca,tempMarca);
                    strcpy(actual->placa,tempPlaca);
                }
            siguiente = siguiente->sig;
            }
        actual = actual->sig;
        siguiente = actual->sig;

     }
        printf("\n");
    }
}





/*
///////////////////////////NO SE USA PARA LO QUE PIDE EL PROGRAMA////////////////////////////////////////////////////

Nodo *insertarAlFinal(Nodo *lista,char marca[20],char color[20], char placa[10]){
    Nodo *Nuevo, *auxiliar;
    Nuevo=asignar(marca, color, placa);
    if(lista==NULL)
    {
        return Nuevo;
    }
    else
    {
        auxiliar=lista;
        while(auxiliar->sig!=NULL)
        {
            auxiliar=auxiliar->sig;
        }
        auxiliar->sig=Nuevo;
        Nuevo->ant=auxiliar;
    }
    return lista;
}


Nodo *insertarPosicion(Nodo *lista,int posicion,char marca[20],char color[20], char placa[10]){
    Nodo *auxiliar,*Nuevo,*resto;
    int longitudLista=0,i=0;
    longitudLista=noElementos(lista);
    if(posicion<1 || posicion > longitudLista)
    {
        printf("LA POSICION NO ESTA DENTRO DEL RANGO");
        return lista;
    }
    else
    {
        if(posicion==1)
        {
            Nuevo = insertarAlInicio(lista,marca,color,placa);
            return Nuevo;
        }
        else
        {
            auxiliar = lista;
            Nuevo=asignar(marca,color,placa);
            for(i=1;i<posicion-1;i++)
            {
                auxiliar = auxiliar->sig;
            }
            resto=auxiliar->sig;
            resto->ant=Nuevo;
            Nuevo->ant=auxiliar;
            Nuevo->sig = auxiliar->sig;
            auxiliar->sig = Nuevo;
        }
    }
    return lista;
}

void reversaLista(Nodo *lista){

	if(lista==NULL)
	{
		printf("La lista no tiene elementos\n");
	}
	else{
		while(lista->sig!=NULL)
	{
		lista=lista->sig;
	}

		while(lista!=NULL){
        printf("%s\t%s\t%s\n",lista->marca,lista->color,lista->placa);
		lista=lista->ant;
	}
	printf("\n");
	}
}
Nodo *borrarInicio(Nodo *frente){
	Nodo *aux=frente;

	if(frente!=NULL){
		frente=frente->sig;
		frente->ant=NULL;
		free(aux);
	}
	return frente;
}
Nodo *borrarFinal(Nodo *final){
	Nodo *aux, *borrar;
	aux=final;
	if(aux->sig == NULL){
		final=borrarInicio(final);
	}
	else{
		while(aux->sig->sig!=NULL){
			aux=aux->sig;
		}
		borrar=aux->sig;
		aux->sig=NULL;
		free(borrar);
	}
	return final;
}
Nodo *borrarPosicion(Nodo *lista,int posicion){
    Nodo *auxiliar,*auxiliar2,*borrar;
    int longitudLista=0,i=0;
    longitudLista=noElementos(lista);
    if(posicion<1 || posicion>longitudLista)
    {
        printf("\nLA POSICION NO ESTA DENTRO DEL RANGO");
        return lista;
    }
    else
    {
        if(posicion==1)
        {
            lista = borrarInicio(lista);
        }
        else
        {
            auxiliar = lista;
            for(i=1;i<posicion-1;i++)
            {
                auxiliar = auxiliar->sig;
            }
            borrar = auxiliar->sig;
            auxiliar2 = borrar->sig;
            if(auxiliar2!=NULL){
                auxiliar2->ant=auxiliar;
            }
            auxiliar->sig = auxiliar2;

            free(borrar);
        }
    }
    return lista;
}
*/

#endif
