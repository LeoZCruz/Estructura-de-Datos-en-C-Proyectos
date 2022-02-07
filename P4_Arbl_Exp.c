/** *PRACTICA 4  Arboles binarios: DE EXPRESION
 * *GRUPO:					1TM4
 * *INTEGRANTES:
 *	CEDILLO CRUZ ERIK LEONEL        2020640069
 *	FLORES DE LA ROSA AXEL YAEL.	2020640145
 *	GONZALEZ SAN JUAN ALEXIS.	    2020640207

 PROFE para ingresar la expresion no tiene que tener espacios
 Se tiene que escribir asi:
 por ejemplo:
 5+7-(3*4-(5-1)-1)
 5+7
 1*9-(2*7-(2*1))
 */



#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct nodoArbol
{
	char valor;
	struct nodoArbol* left, * right;
} TreeNode;
typedef struct nodoArbol* ExpTree;
//PILAS
//Struct
struct nodo {
  TreeNode* datoT;
  char dato;
  struct nodo *siguiente;
};
struct nodo *superior = NULL;
struct nodo *superiorChar = NULL;
//push
void agregar(TreeNode* datoT) {
  struct nodo *nuevoNodo = malloc(sizeof(struct nodo));

  nuevoNodo->datoT = datoT;
  nuevoNodo->siguiente = superior;
  superior = nuevoNodo;
}
void agregarChar(char dato) {
  struct nodo *nuevoNodo = malloc(sizeof(struct nodo));

  nuevoNodo->dato = dato;
  nuevoNodo->siguiente = superiorChar;
  superiorChar = nuevoNodo;
}
//pop
void eliminarUltimo(void) {
  if (superior != NULL) {

    struct nodo *temporal = superior;
    superior = superior->siguiente;
    free(temporal);
  }
}
void eliminarUltimoChar(void) {
  if (superiorChar != NULL) {

    struct nodo *temporal = superiorChar;
    superiorChar = superiorChar->siguiente;
    free(temporal);
  }
}
//isEmpty
bool vacia(void) { return superior == NULL; }
bool vaciaChar(void) { return superiorChar == NULL; }
//return top
TreeNode* ultimo() {
  if (superior == NULL)
    return NULL;
  return superior->datoT;
}
char ultimoChar() {
  if (superiorChar == NULL)
    return NULL;
  return superiorChar->dato;
}

//FINALPILA

ExpTree CrearNodo(int valor);
ExpTree constructTree(ExpTree T, char postfix[]);
int ordenOperadores(char ch);
void Convert_In_To_Post(char infix[], char postfix[]);
void preorder(ExpTree T);
void preorderEscritura(ExpTree T);
bool comprobarExpresion(char infix[]);
bool esOperador(char ch);
bool esDigito(char c);
char expFinal[30];
int sumador;
int main()
{
	char expresioninf[30];
	char postfix[30];
	printf("\n\t\tArbol Binario de Expresion\n");
	printf("\n__________________________________________________________________\n");
	printf("\n\tLeer de un archivo la expresion:\n");
/*Aqui hago la lectura del archivo*/
///////////////////////////////////////////////////////////////
FILE *fichero = NULL;
fichero = fopen("expresion.txt", "rw");
if(fichero == NULL){
            printf("No se pudo abrir.\n");
        }else{
		while(!feof(fichero)){
			fgets(expresioninf,30,fichero);
		}
		}
	fclose(fichero);
//////////////////////////////////////////////////////////
	if (!comprobarExpresion(expresioninf)) {
		printf(" Solo puedes usar estas expresiones  [ Numeroes entre: 1-9 ,  + , - , * , / , ^ , ( , )  ] \n");
		return 0;
	}
	Convert_In_To_Post(expresioninf, postfix);
	ExpTree tree1 = NULL;
	tree1 = constructTree(tree1, postfix);
	printf("\n__________________________________________________________________\n");
	printf("\nArbol Generado PreOrden: \t[");
	preorder(tree1);
	printf("]");
	printf("\n__________________________________________________________________\n");
    printf("\n\tESCRIBIENDO EN ARCHIVO RESULTADO.TXT...\n");
    int i=0;
		/*Aqui escribire en el archivo*/
//////////////////////////////////////////////////////////////
FILE *ficheroSalida = NULL;
  ficheroSalida = fopen( "RESULTADO.txt", "a" );
  if(ficheroSalida == NULL){
            printf("No se pudo abrir.\n");
        }else{
        	int k = 0;
           for(k=0;k<=sumador;k++){
             fprintf(ficheroSalida,"%c ",expFinal[k]);
        }
        fprintf(ficheroSalida,"\n");
		}
	fclose(ficheroSalida);
//////////////////////////////////////////////////////////////
	return 0;
}

bool esDigito(char ch)
{
	if (ch > 47 && ch <= 57){
		return true;
	}
	return false;
}

bool esOperador(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
		return true;
	}
	return false;
}

bool comprobarExpresion(char infix[])
{
	int i =0;
	for (i; i < strlen(infix); i++) {
		if (!esDigito(infix[i]) && !esOperador(infix[i]) && infix[i] != '(' && infix[i] != ')'){
			return false;
		}
	}
	return true;
}

int ordenOperadores(char ch)
{
	switch (ch)
	{
	case '^':
		return 3;
	case '/':
	case '*':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}

ExpTree CrearNodo(int valor)
{
	TreeNode* temp;
	temp = (TreeNode*)malloc(sizeof(TreeNode));
	if (temp == NULL)
	{
		printf("\nError...\n");
		return (temp);
	}
	temp->left = NULL;
	temp->right = NULL;
	temp->valor = valor;
	return temp;
};
void preorder(ExpTree T)
{

	if (T != NULL){
        sumador++;
		printf("%c ",T->valor);
		expFinal[sumador]=T->valor;
		preorder(T->left);
		preorder(T->right);
    }
}

ExpTree constructTree(ExpTree tree, char postfix[])
{
	int i = 0;
	TreeNode* temp_tree1;
	TreeNode* temp_tree2;
	while (postfix[i] != '\0')
	{
		if (!(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^'))
		{
			tree = CrearNodo(postfix[i]);
			agregar(tree);
		}
		else
		{
			tree = CrearNodo(postfix[i]);

			temp_tree1 = ultimo(); eliminarUltimo();
			temp_tree2 = ultimo(); eliminarUltimo();
			tree->right = temp_tree1;
			tree->left = temp_tree2;
			agregar(tree);
		}
		i++;
	}
	return tree;
}
void Convert_In_To_Post(char infix[], char postfix[])
{
	int counter1 = 0;
	int postCount = 0;
	char element;
	while (counter1 < strlen(infix))
	{
		element = infix[counter1];
		if (element == '(')
		{
			agregarChar(element);
			counter1++;
			continue;
		}
		if (element == ')')
		{
			while (!vaciaChar() && ultimoChar() != '(')
			{
				postfix[postCount++] = ultimoChar();
				eliminarUltimoChar();
			}
			if (!vaciaChar())
			{
				eliminarUltimoChar();
			}
			counter1++;
			continue;
		}

		if (ordenOperadores(element) == 0)
		{
			postfix[postCount++] = element;
		}
		else
		{
			if (vaciaChar())
			{
				agregarChar(element);
			}
			else
			{
				while (!vaciaChar() && ultimoChar() != '(' && ordenOperadores(element) <= ordenOperadores(ultimoChar()))
				{
					postfix[postCount++] = ultimoChar();
					eliminarUltimoChar();
				}
				agregarChar(element);
			}
		}
		counter1++;
	}

	while (!vaciaChar())
	{
		postfix[postCount++] = ultimoChar();
		eliminarUltimoChar();
	}
	postfix[postCount] = '\0';
}
