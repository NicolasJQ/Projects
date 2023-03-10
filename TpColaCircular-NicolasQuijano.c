//TP COLA CIRCULAR | NICOLÁS QUIJANO AUS 2022//
#include<stdio.h>
#include<stdlib.h>

typedef struct _nodum {
    int info;
    struct _nodum* next;
} nodo;


typedef struct _cola {
    nodo *tail;
} cola;

cola *InicializarCola();
void Push(cola *nodum, int v);
int Pop(cola *nodum );
int Comprobar(cola *nodum );
void Opciones(cola *c);
void Listar(cola *nodum);


int main() {
    cola *nodum = InicializarCola();
    Opciones(nodum);
    return 0;
}
void Opciones(cola *nodum) {
    int choice, dato;
    do {
        printf("____________________\n1: Push\n2: Pop\n3: Listar\n4: Comprobar vacia\n5: Salir\n____________________\n");
        scanf("%d", &choice);
        printf("\n\n");
        switch(choice) {
            case 1:     printf("\nIngrese el dato: ");
                        scanf("%d", &dato);
                        Push(nodum,dato);
                        break;
            case 2:     dato = Pop(nodum);
                        if(dato == 0)
                            printf("La cola esta vacia\n");
                        else
                            printf("Se ha eliminado el elemento %d\n", dato);
                        break;
            case 3:     Listar(nodum);
                        break;
            case 4:     if(Comprobar(dato) == 1)
                            printf("La cola esta vacia\n");
                        else
                            printf("La cola no esta vacia\n");
                        break;
        }
    } while(choice != 5);
}
cola *InicializarCola() {
    cola *nodum = (cola*)malloc(sizeof(cola));
    nodum->tail = NULL;
    return nodum;
}

void Push(cola *nodum, int dato) {
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->info = dato;
    if( Comprobar(nodum) ) {
        nuevo->next = nuevo;
    } else {
        nuevo->next = nodum->tail->next;
        nodum->tail->next = nuevo;
    }
    nodum->tail = nuevo;
}


int Pop(cola *nodum ) {
    int i = 0;
    nodo *aux;
    if(Comprobar(nodum)) {
        return i;
    } else {
        i = (nodum->tail->next)->info;
        aux = nodum->tail->next;
        if(aux == nodum->tail) {
            nodum->tail = NULL;
        } else {
            nodum->tail->next = aux->next;
        }
        free(aux);
    }
    return i;
}

int Comprobar(cola *nodum) {
    return nodum->tail == NULL? 1:0;
}

void Listar(cola *nodum) {

    nodo *actual = nodum->tail->next;
    printf("Lista de datos:\n");
    while(actual != nodum->tail) {
        printf("%d\n", actual->info);
        actual = actual->next;
    }
    printf("%d\n", actual->info);
}
