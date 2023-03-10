//TP ARBOL BINARIO | NICOLÁS QUIJANO AUS 2022//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

typedef struct nodo {
    char string[30];
    struct nodo *left , *right;
} tree;

tree *NuevoNodo(char cadena[30]);
void Inserta(tree **raiz, char cadena[30]);
char *EliminarMinimo(tree **raiz);
void PreOrden(tree *nodo, FILE *);
void InOrden(tree *raiz, FILE*);
void PostOrden(tree *raiz, FILE*);
void Opciones(FILE *p, tree *raiz);

int main() {
    tree *raiz = NULL;
    FILE *p = fopen("Entrada.txt", "r");
    Opciones(p,raiz);
    fclose(p);
    return 0;
}

void Opciones(FILE *p, tree *raiz) {
    FILE *a;
    int choice;
    char cadena[30], *sdin;
    int counter = 0;
    do {
        printf("__________________\n1: Insertar\n2: Eliminar Minimo\n3: PreOrden\n4: InOrden\n5: PostOrden\n6: Salir\n__________________\n");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1:   while(!feof(p)) {
                            fscanf(p, "%s", &cadena);
                            Inserta(&raiz,cadena);
                            counter++;
                        }
                        printf("Cantidad de elementos: %d\n", counter);
                        fclose(p);
                        break;
            case 2:   sdin = EliminarMinimo(&raiz);
                        free(sdin);
                        break;
            case 3:   a = fopen("PreOrden.txt", "a");
                        PreOrden(raiz,a);

                        fclose(a);
                        break;
            case 4:   a = fopen("InOrden.txt", "a");
                        InOrden(raiz,a);
                        fclose(a);
                        break;
            case 5:   a = fopen("PostOrden.txt", "a");
                        PostOrden(raiz,a);
                        fclose(a);
                        break;
        }
    }while(choice != 6);
}

tree *creaNodo(char cadena[30]) {
    tree *nuevo = (tree*)malloc(sizeof(tree));
    strcpy(nuevo->string,cadena);
    nuevo->left=NULL;
    nuevo->right = nuevo->left;
    return nuevo;
}

void Inserta(tree **raiz, char cadena[30]) {
    if(*raiz == NULL) {
        tree *nodo = creaNodo(cadena);
        *raiz = nodo;
    } else {
        if(strcmp(cadena,(*raiz)->string) > 0) {
            Inserta(&(*raiz)->right,cadena);
        } if(strcmp(cadena,(*raiz)->string) < 0) {
            Inserta(&(*raiz)->left,cadena);
        }
    }
}

char *EliminarMinimo(tree **raiz) {
    char *cad = (char*)malloc(sizeof(char)*30);

    if((*raiz)->left == NULL) {
        strcpy(cad,(*raiz)->string);
        tree *nodo = *raiz;
        *raiz = (*raiz)->right;
        free(nodo);
        return cad;

    } else {
        return EliminarMinimo(&((*raiz)->left));
    }
}

void PreOrden(tree *raiz, FILE *a) {
    if (raiz != NULL) {
        printf("%s\n", raiz->string);
        fputs(raiz->string,a);
        fputs("\n",a);
        PreOrden(raiz->left,a);
        PreOrden(raiz->right,a);
    }
}

void InOrden(tree *raiz, FILE *a) {
    if (raiz != NULL) {
        InOrden(raiz->left,a);
        printf("%s\n",raiz->string);
        fputs(raiz->string,a);
        fputs("\n",a);
        InOrden(raiz->right,a);
    }
}

void PostOrden(tree *raiz, FILE *a) {
    if (raiz != NULL) {
        PostOrden(raiz->left,a);
        PostOrden(raiz->right,a);
        printf("%s\n",raiz->string);
        fputs(raiz->string,a);
        fputs("\n",a);
    }
}
