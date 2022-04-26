#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista* inserirFinal(Lista *L, int num){
    Lista *novo, *p=L;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;
    
    if(p==NULL){
        return novo;
    } else {
        while(p->prox!=NULL){
            p = p->prox;
        }
        novo->prox = p->prox;
        p->prox = novo;
        return L;
    }
}

int count(Lista *L){
    int cont = 0;
    
    while(L!=NULL){
        cont++;
        L = L->prox;
    }
    return cont;
}

int Rcount(Lista *L){
    if(L==NULL){
        return 0;
    } else {
        return Rcount(L->prox)+1;
    }
}

int soma(Lista *L){
    int sum = 0;
    while(L!=NULL){
        sum += L->info;
        L = L->prox;
    }
    return sum;
}

int Rsoma(Lista *L){
    int sum = 0;
    
    if(L==NULL){
        return 0;
    } else {
        return Rsoma(L->prox)+L->info;
    }
}

void imprimeDados(Lista *L){
    if(L!=NULL){
        printf("%d ", L->info);
        imprimeDados(L->prox);
    }
}

int main(){
    Lista *L1 = NULL;
    L1 = inserirFinal(L1, 7);
    L1 = inserirFinal(L1, 1);
    L1 = inserirFinal(L1, 2);
    L1 = inserirFinal(L1, 3);
    imprimeDados(L1);
    printf("\nA quantidade de dados na lista eh: %d", count(L1));
    printf("\nA quantidade de dados na lista eh: %d", Rcount(L1));
    printf("\nA soma dos dados na lista eh: %d", soma(L1));
    printf("\nA soma dos dados na lista eh: %d", Rsoma(L1));

    return 0;
}
