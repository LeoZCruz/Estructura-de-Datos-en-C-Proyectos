
//Cedillo Cruz Erik Leonel
//2020640069


int alturaArbol(Tree* Arbol){
    int auxAltura;

    if(Arbol==NULL){
        return auxAltura = 0;
    }else{
        auxAltura++;
        Tree* auxArbol = NULL;
        if(Arbol->hijo==NULL){
            auxArbol = Arbol->izquierdo;
            auxAltura = alturaArbol(auxArbol);
        }else if(Arbol->izquierdo==NULL){
            alturaArbol = alturaArbol(Arbol->hijo);
        }else{
            alturaArbol = alturaArbol(Arbol->hijo);
        }
    }
    return auxAltura;
}

int nivelArbol(Tree* Arbol,int dato){
    int auxNivel;
    if(Arbol == NULL){
        return auxNivel = 0;
    }else if(Arbol->dato == dato){
        auxNivel++;
        return auxNivel;
    }else if(dato < Arbol->dato){
        auxNivel++;
        auxNivel = auxNivel +  nivelArbol(Arbol->izquierdo,dato);

        return auxNivel;
    }else{
        auxNivel++;
        auxNivel = auxNivel +  nivelArbol(Arbol->derecho,dato);
        return auxNivel;
    }
}
