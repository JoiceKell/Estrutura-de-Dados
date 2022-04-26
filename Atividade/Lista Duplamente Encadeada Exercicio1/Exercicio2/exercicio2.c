#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
    struct lista *ant;
}Lista;

Lista* insereFinal(Lista *L, int num){
    Lista *novo, *p=L;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;
    novo->ant = NULL;
    
    if(p==NULL){
        return novo;
    } else {
        while(p->prox!=NULL)
            p=p->prox;
            
        novo->prox = p->prox;
        p->prox = novo;
        novo->ant = p;
        return L; 
    }
}

void imprimeDados(Lista *L){
    if(L!=NULL){
        printf("%d ", L->info);
        imprimeDados(L->prox);
    }
}

Lista* separa(Lista *L, int num){
    Lista *p=L, *aux;
    
    while(p!=NULL && p->info != num)
        p=p->prox;
        
    aux = p->prox;
    p->prox = NULL;
    aux->ant = NULL;
    return aux;
}

int main(){
    Lista *L1=NULL, *L2=NULL;
    
    L1 = insereFinal(L1, 1);
    L1 = insereFinal(L1, 2);
    L1 = insereFinal(L1, 3);
    L1 = insereFinal(L1, 4);
    imprimeDados(L1);
    
    printf("\n\nL2: ");
    L2 = separa(L1, 2);
    imprimeDados(L2);
    printf("\nL1: ");
    imprimeDados(L1);

    return 0;
}
