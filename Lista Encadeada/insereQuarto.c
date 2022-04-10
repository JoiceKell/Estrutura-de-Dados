#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista* insereQuarto(Lista *L, int num){
    Lista *novo, *p = L;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    
    if(L==NULL){
        return novo;
    } else if(p->prox == NULL){
        novo->prox = p->prox;
        p->prox = novo;
    } else if(p->prox->prox == NULL){
        novo->prox = p->prox->prox;
        p->prox->prox = novo;
    } else {
        novo->prox = p->prox->prox->prox;
        p->prox->prox->prox = novo;
    }
    return L;
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
    L1 = insereQuarto(L1, 8);
    L1 = insereQuarto(L1, 5);
    L1 = insereQuarto(L1, 4);
    L1 = insereQuarto(L1, 10);
    L1 = insereQuarto(L1, 17);
    L1 = insereQuarto(L1, 9);
    imprimeDados(L1);
    return 0;
}
