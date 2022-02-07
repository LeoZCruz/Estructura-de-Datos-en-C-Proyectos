#include "CCEL_2020640069.h"

int main(){

    srand(time(NULL));
    Nodo *cobros=NULL;
    Nodo *pagos = NULL;
    Nodo *recepcion=NULL;
    menu(recepcion,cobros,pagos);
    return 0;
}

void menu(Nodo* recepcion,Nodo* cobros,Nodo* pagos){

    int num,nuevaCuenta;
    int nuevoTop;
    do{
        system("cls");
        printf("Programa para realizar la simulación de una fila de atencion a clientes.\n");
        printf("\n1.  Empezar Secuencia:\n");
        printf("\n2.  Salir:\n");
        printf("\nIngresa la accion a realiazar: ");
        scanf("%d",&num);
        switch (num){
            case 1:
                system("cls");
                printf("CREARA FILA DE PERSONAS.TXT.... \n");
                printf("==========PILA RECEPCION===========\n");                                     //METODO QUE LEA LISTA ORIGINAL E INSERTE EN LISTA FILA RECEPCION
                recepcion = Leer(recepcion);
                printf("TOMA DE DECICION PAGO O COBRO... \n");
                int elementos, a, numAle;
                elementos = CuentaElementos(recepcion);
                fflush( stdin );
                                                        //while hasta que fila llegue a nulo
                while(a<elementos){
                    fflush( stdin );
                    numAle = rand()%2;
                    if(numAle == 1){
                                                                //METODO QUE INGRESA A LISTA PAGOS
                        printf("===============INSERTAR PAGOS==================\n");
                        pagos =Magia(recepcion,pagos);
                    }else{
                                                                //METODO QUE INGRESA A LISTA COBROS
                        printf("===============INSERTAR COBROS==================\n");
                        cobros=Magia(recepcion,cobros);
                    }
                    recepcion=salirse(recepcion);//SACA ELEMENTOS DE LA RECEPCION
                    a++;
                }
                system("cls");
                printf("==========PILA PAGOS===========\n");
                Mostrar(pagos);
                printf("==========PILA COBROS===========\n");
                Mostrar(cobros);
                printf("==================================== \n");
                printf("====INGRESANDO DATOS A PAGOS.TXT==== \n");
                pagos=EscribirPagos(pagos);
                printf("===INGRESANDO DATOS A COBROS.TXT====\n");
                cobros=EscribirCobros(cobros);
                printf("====================================\n");
                printf("====SE COMPLETO SECUENCIA====\n");
                printf("=======REVISE BITACORA=======\n");
                printf("===DA ENTER PARA CONTINUAR===\n");
                system("pause");

            break;
            default:
                printf("No se realizo ninguna Accion\n");
            break;
        }
    }while (num!=2);
}


