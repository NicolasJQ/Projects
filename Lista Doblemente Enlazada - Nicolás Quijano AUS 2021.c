//TP LISTA DOBLEMENTE ENLAZADA | NICOLÁS QUIJANO AUS 2021//
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *next;
    struct nodo *prev;
}NODUM;

NODUM *NuevoNodo(int dato);
void NodoAlInicio(NODUM **cabeza, int dato);
void NodoAlFinal(NODUM **cabeza, int dato);
void BorrarNodo(NODUM **cabeza, int dato);
void MostrarNodos(NODUM *cabeza);


int main(){
    NODUM *cabeza=NULL;
    menu(cabeza);
}

NODUM *NuevoNodo(int dato){
    NODUM *nuevo_nodo=NULL;
    nuevo_nodo=(NODUM*)malloc(sizeof(NODUM));
    if(nuevo_nodo!=NULL){
        nuevo_nodo->dato=dato;
        nuevo_nodo->next=NULL;
        nuevo_nodo->prev=NULL;
    }
    else{
        printf("No se pudo crear el nuevo nodo");
        exit(1);
    }
    return nuevo_nodo;
}

void NodoAlInicio(NODUM **cabeza, int dato){
    NODUM *nodo_siguiente=NULL;
    NODUM *nodo_actual=*cabeza;
    NODUM *nodo_anterior=NULL;
    nodo_siguiente=NuevoNodo(dato);

    while((nodo_actual != NULL) && (nodo_actual->dato <= nodo_siguiente->dato)) {
        nodo_anterior = nodo_actual;
        nodo_actual = nodo_actual->next;
    }
    if(nodo_anterior != NULL) {
        nodo_anterior->next = nodo_siguiente;
        nodo_siguiente->prev = nodo_anterior;
    }
    else {
        *cabeza = nodo_siguiente;
        nodo_siguiente->prev = NULL;
    }
    nodo_siguiente->next = nodo_actual;
    if(nodo_actual != NULL) {
        nodo_actual->prev= nodo_siguiente;
    }
    return 0;
}
void MostrarNodos(NODUM *cabeza){
    NODUM *cont=cabeza;
    while(cont!=NULL){
        printf("%d\n",cont->dato);
        cont=cont->next;
    }
}
void NodoAlFinal(NODUM **cabeza, int dato){
    NODUM *nuevo_nodo=NULL, *cont=*cabeza;
    nuevo_nodo=NuevoNodo(dato);
    if(nuevo_nodo!=NULL){
        while(cont->next!=NULL){
            cont=cont->next;
        }
        nuevo_nodo->prev=cont;
        cont->next=nuevo_nodo;
        return 1;
    }
    return 0;
}
void BorrarNodo(NODUM **cabeza, int dato){
    NODUM *nodo_siguiente=NULL;
    NODUM *nodo_actual=*cabeza;
    NODUM *nodo_anterior=NULL;

    while(nodo_actual!=NULL){
        if(nodo_actual->dato==dato){
            if(nodo_actual==*cabeza){
            *cabeza=nodo_actual->next;
            if(nodo_actual->next!=NULL){
                nodo_actual->next->prev=NULL;
            }}
        else if(nodo_actual->next==NULL){
            nodo_anterior=nodo_actual->prev;
            nodo_actual->prev=NULL;
            nodo_anterior->next=NULL;
        }
        else{
            nodo_anterior=nodo_actual->prev;
            nodo_actual->prev=NULL;
            nodo_siguiente=nodo_actual->next;
            nodo_actual->next=NULL;
            nodo_anterior->next=nodo_siguiente;
            nodo_siguiente->prev=nodo_anterior;
            }
            free(nodo_actual);
            return 1;
        }
        nodo_actual=nodo_actual->next;
    }
    return 0;
    }
void menu(NODUM *cabeza) { // MENU
    int opcion = 100, dato;
    do {
        printf("Presione 1 para insertar un nodo al inicio\nPresione 2 para insertar un nodo al final\nPresione 3 para borrar un nodo\nPresione 4 para mostrar todos los nodos\nPresione 5 para salir\n");
        scanf("%d", &opcion);
        printf("\n");
        switch(opcion) {
            case 1:     printf("\nIngrese un numero: ");
                        scanf("%d", &dato);
                        NodoAlInicio(&cabeza,dato);
                        break;
            case 2:     printf("Ingrese un numero: ");
                        scanf("%d", &dato);
                        NodoAlFinal(&cabeza,dato);
                        break;
            case 3:     printf("Ingrese el valor del nodo que desea borrar: ");
                        scanf("%d", &dato);
                        BorrarNodo(&cabeza,dato);
                        break;
            case 4:     MostrarNodos(cabeza);
                        break;
        }
    } while(opcion != 5);
}
