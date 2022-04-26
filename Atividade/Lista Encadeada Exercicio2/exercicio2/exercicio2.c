#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista* insereInicio(Lista *L, int num){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = L;
    return novo;
}

void imprimeDados(Lista *L){
    if(L!=NULL){
        printf("%d ", L->info);
        imprimeDados(L->prox);
    }
}

int ordemCrescente(Lista *L){
    Lista *p=L;
    
    if(L!=NULL){
        while(p->prox!=NULL && p->info < p->prox->info)
            p=p->prox;
            
        if(p->prox == NULL)
            return 1;
        else 
            return 0;
    }
}

int main(){
    Lista *L1=NULL;
    int cresc;
    
    L1 = insereInicio(L1, 5);
    L1 = insereInicio(L1, 4);
    L1 = insereInicio(L1, 3);
    L1 = insereInicio(L1, 2);
    L1 = insereInicio(L1, 1);
    imprimeDados(L1);
    
    printf("\n");
    cresc = ordemCrescente(L1);
    if(cresc == 1)
        printf("\nA Lista está em ordem!");
    else
        printf("\nA lista não está em ordem!");
    return 0;
}
