#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista* insereMeio(Lista *L, int num){
    Lista *novo, *p = L, *ant = NULL;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    
    while(p!=NULL && p->info < num){
        ant = p;
        p = p->prox;
    }
    
    if(ant == NULL){
        novo->prox = L;
        return novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
        return L;
    }
}

Lista* separa(Lista *L, int num){
    Lista *p = L, *aux;
    
    while(p!=NULL && p->info != num){
        p = p->prox;
    }
    
    if(p == NULL){
        return L;
    } else {
        aux = p->prox;
        p->prox = NULL;
        return p;
    }
}

Lista* imprimeDados(Lista *L){
    Lista *p = L;
    
    if(L==NULL){
        return L;
    } else {
        printf("%d ", p->info);
        imprimeDados(p->prox);
    }
}

int main(){
    Lista *L1=NULL, *p = L1, *novaLista;
    int num;
    
    L1 = insereMeio(L1, 1);
    L1 = insereMeio(L1, 5);
    L1 = insereMeio(L1, 1);
    L1 = insereMeio(L1, 7);
    L1 = insereMeio(L1, 17);
    L1 = insereMeio(L1, 10);
    printf("Antes de separar: ");
    imprimeDados(L1);
    printf("\nNova lista: ");
    novaLista = separa(L1, 10);
    imprimeDados(novaLista);
    printf("\nLista: ");
    imprimeDados(L1);

    return 0;
}
