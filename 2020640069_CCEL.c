#include "2020640069_CCEL.h"
#include <windows.h>
#include <stdlib.h>

void menu();

int main(){
    NODO* top;
    top=NULL;
    menu(top);
}
void menu(NODO* top){
    int num;
    int nuevoTop;
    do{
    printf("\n1.  Mostrar pila:\n");
    printf("\n2.  Calcular de Archivo:\n");
    printf("\n3.  SALIR:\n");
    printf("\nIngresa la accion a realiazar: ");
    scanf("%d",&num);
    switch (num){
    case 1:
        MostrarPila(top);
        system("pause");
        system("cls");
        break;
    case 2:
        printf("Se leera de un archivo:\n");
        FILE *fichero = NULL;
        FILE *fichero2 = NULL;
        char  nAux;
        fichero = fopen("postfija.txt", "rw");
        if(fichero == NULL){
            printf("No se pudo abrir.\n");
        }else{
            while(!feof(fichero)){
            fscanf(fichero,"%c ",&nAux);
            printf("%c ",nAux);
            if((nAux=='+')||nAux=='-'||nAux=='*'||nAux=='/'){
            switch (nAux){
                case '+':
                    nuevoTop = CalcularSuma(top);
                    if(nuevoTop!=0){
                    top = DesApilar(top);
                    top = DesApilar(top);
                    top = Apilar(top,nuevoTop);
                    }
                break;
                case '-':
                    nuevoTop = CalcularResta(top);
                    if(nuevoTop!=0){
                    top = DesApilar(top);
                    top = DesApilar(top);
                    top = Apilar(top,nuevoTop);
                    }
                break;
                case '*':
                    nuevoTop = CalcularProducto(top);
                    if(nuevoTop!=0){
                    top = DesApilar(top);
                    top = DesApilar(top);
                    top = Apilar(top,nuevoTop);
                    }
                break;
                case '/':
                    nuevoTop = CalcularCociente(top);
                    if(nuevoTop!=0){
                    top = DesApilar(top);
                    top = DesApilar(top);
                    top = Apilar(top,nuevoTop);
                    }
                break;
                default:
                    printf("No se realizo ninguna tarea\n");
                break;
                }
            }else{
                int nuevoAux = nAux - '0';
                top = Apilar(top,nuevoAux);
            }
        }
        printf("\n");
        fprintf(fichero,"\n");

    }
        fclose(fichero);
        MostrarPila(top);

        fichero2 = fopen("postfijaEvaluacion.txt","a");
        if(fichero2 == NULL){
            perror("Error de creacion de archivo\n");

        }else{
            fprintf(fichero2,"%d \n",top->dato);
        }
        fclose(fichero2);
        //printf("El valor de la pila Se guardo en variable PILAAUX y en archivo PostFijaEvaluacion.txt\n ");
        //printf("Mientras tanto top original se le dara valor de 0 para futuras operaciones\n");
        system("pause");
        system("cls");
       // NODO* pilaAux= top;
       // top->dato= 0;
        break;

    }
    }while (num!=3);
}
