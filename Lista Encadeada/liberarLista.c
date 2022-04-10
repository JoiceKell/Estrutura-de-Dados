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

Lista* liberarLista(Lista *L){
    Lista *p = L;
    while(p->prox!=NULL){
        free(p);
        p = p->prox;
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
    Lista *L1=NULL;
    L1 = insereMeio(L1, 8);
    L1 = insereMeio(L1, 5);
    L1 = insereMeio(L1, 4);
    L1 = insereMeio(L1, 10);
    L1 = insereMeio(L1, 17);
    L1 = insereMeio(L1, 9);
    printf("Antes de retirar: ");
    imprimeDados(L1);

    L1 = liberarLista(L1);
    printf("\nDepois de retirar: ");
    imprimeDados(L1);
    return 0;
}
