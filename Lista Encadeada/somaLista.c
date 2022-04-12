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

int somaDados(Lista *L){
    int soma = 0;
    
    while(L!=NULL){
        soma += L->info;
        L = L->prox;
    }
    return soma;
}

int main(){
    Lista *L1 = NULL;
    
    L1 = insereInicio(L1, 1);
    L1 = insereInicio(L1, 10);
    L1 = insereInicio(L1, 8);
    printf("Lista: ");
    imprimirDados(L1);
    
    printf("\nSoma Total dos valores da lista eh: %d ", somaDados(L1));
    return 0;
}
