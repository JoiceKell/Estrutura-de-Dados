#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista* inserirFinal(Lista *L, int num){
    Lista *novo, *p = L;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;
    
    if(p==NULL){
        return novo;
    } else {
        while(p->prox!=NULL){
            p = p->prox;
        }
        p->prox = novo;
        return L;
    }
}

void imprimeDados(Lista *L){
    if(L!=NULL){
        printf("%d ", L->info);
        imprimeDados(L->prox);
    }
}

int maior(Lista *L){
    int x=0;
    
    if(L==NULL)
        return 0;
    
    x = maior(L->prox);
    return x > L->info ? x : L->info;
}

int maximo(Lista *L){
    int x;
    x = L->info;
    
    while(L->prox!=NULL){
        if(x < L->info){
            x = L->info;
        }
        L = L->prox;
    }
    return x;
}

int Rmaximo(Lista *L){
    int x=0;
    
    if(L==0){
        return 0;
    } else {
        x = Rmaximo(L->prox);
        if(x < L->info){
            x = L->info;
        }
    }
    return x;
}

int main(){
    Lista *L1 = NULL;
    int max = 0;
    
    L1 = inserirFinal(L1, 1);
    L1 = inserirFinal(L1, 50);
    L1 = inserirFinal(L1, 10);
    L1 = inserirFinal(L1, 19);
    imprimeDados(L1);
    max = maior(L1);
    printf("\nMaximo: %d", max);
    max = maximo(L1);
    printf("\nMaximo: %d", max);
    max = Rmaximo(L1);
    printf("\nMaximo: %d", max);
    return 0;
}
