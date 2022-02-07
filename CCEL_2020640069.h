#ifndef _filas_h_
#define _filas_h_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo{
    char nombre[15];
    int cuenta;
    int saldo;
    struct Nodo *sig;

}Nodo;

Nodo *crear(char nombre[15],int cuenta,int saldo){
    Nodo *nuevo;
    nuevo=( Nodo*)malloc(sizeof (Nodo));
    for (int i = 0; i < 15; i++) {
        nuevo->nombre[i] = nombre[i];
    }
    nuevo->cuenta=cuenta;
    nuevo->saldo=saldo;
    nuevo->sig=NULL;
    return nuevo;

}

Nodo *insertar(Nodo *frente,char nombre[15],int cuenta,int saldo){
    Nodo * nuevo,*aux;
    nuevo=crear(nombre,cuenta,saldo);
    if(frente==NULL){
        return nuevo;
    }
    else{
        aux=frente;
        while(aux->sig!=NULL){
                aux= aux->sig;
        }
        aux->sig=nuevo;
        return frente;
    }
}

void Mostrar(Nodo* frente){
    if(frente==NULL){
        printf("LA FILA ESTA VACIA\n");
    }
    else{

        while(frente!=NULL){
            printf("%s\t%d\t%d\n",frente->nombre,frente->cuenta,frente->saldo);
            frente=frente->sig;
        }
    }
}

Nodo *salirse(Nodo* frente){
    Nodo *aux=frente;
    if(frente!=NULL){
        frente= frente->sig;
        free(aux);

    }
    return frente;

}

int CuentaElementos(Nodo* frente){
    int c=0;
    if(frente== NULL){

        return 0;
    }
    else{
        while(frente!=NULL){
            c+=1;
    frente=frente->sig;
        }
    }
    return c;
}

Nodo *EscribirPagos(Nodo *frente){

    char nombre[15];
    int cuenta;
    int saldo;
        FILE *archivoP = fopen("pagos.txt","a");
        if(archivoP==NULL){
            printf("No se pudo abrir el archivo\n");
        }else{
            if(frente == NULL){
            return 0;
            }else{
                while(frente != NULL){
                    for (int i = 0; i < 15; i++) {
                        nombre[i]=frente->nombre[i] ;
                    }
                    cuenta = frente ->cuenta;
                    saldo = frente -> saldo;
                    fprintf(archivoP,"%s\t%d\t%d\n",nombre,cuenta,saldo);
                    frente = frente->sig;
                }
            frente=salirse(frente);
            return frente;
            }

        }

        fclose(archivoP);
}


Nodo *EscribirCobros(Nodo *frente){

    char nombre[15];
    int cuenta;
    int saldo;
        FILE *archivoC = fopen("cobros.txt","a");
        if(archivoC==NULL){
            printf("No se pudo abrir el archivo\n");
        }else{
            if(frente == NULL){
            return 0;
            }else{
                while(frente != NULL){
                    for (int i = 0; i < 15; i++) {
                        nombre[i]=frente->nombre[i] ;
                    }
                    cuenta = frente ->cuenta;
                    saldo = frente -> saldo;
                    fprintf(archivoC,"%s\t%d\t%d\n",nombre,cuenta,saldo);
                    frente = frente->sig;
                }
            frente=salirse(frente);
            return frente;
            }

        }

        fclose(archivoC);
}

Nodo *Leer(Nodo * frente){
    char nombre[15];
    int cuenta;
    int saldo;
        FILE *archivo = fopen("personas.txt","r");

        if(archivo == NULL){
            return NULL;
        }else{
            while(feof(archivo)== NULL){
                fscanf (archivo,"%s\t%d\t%d",nombre,&cuenta,&saldo);
                frente = insertar(frente,nombre,cuenta,saldo);
            }
            return frente;
        }

        fclose(archivo);
}

/////////////////////////////////////////////////////////////////////////////////////
Nodo *Magia(Nodo *recepcion,Nodo *nuevo){
    char nombre[15];
    int cuenta;
    int saldo;
    for (int i = 0; i < 15; i++) {
        nombre[i]=recepcion->nombre[i] ;
    }
    cuenta=recepcion->cuenta;
    saldo=recepcion->saldo;
    nuevo=insertar(nuevo,nombre,cuenta,saldo);
return nuevo;
}
////////////////////////////////////////////////////////////////////////////////////////


#endif // _filas_h
