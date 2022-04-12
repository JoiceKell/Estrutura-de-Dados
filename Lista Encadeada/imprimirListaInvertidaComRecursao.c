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

Lista* imprimirDados(Lista *L){
    if(L!=NULL){
        printf("%d ", L->info);
        imprimirDados(L->prox);
    }
}

Lista* imprimirDadosInverso(Lista *L){
    if(L!=NULL){
        imprimirDadosInverso(L->prox);
        printf("%d ", L->info);
    }
}

int main(){
    Lista *L1 = NULL;
    
    L1 = insereInicio(L1, 1);
    L1 = insereInicio(L1, 10);
    L1 = insereInicio(L1, 8);
    printf("Lista: ");
    imprimirDados(L1);
    
    printf("\n\nLista Inverso: ");
    imprimirDadosInverso(L1);
    return 0;
}
