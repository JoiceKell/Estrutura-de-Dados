#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
    int info;
    struct lista *proximo;
}Lista;

Lista* inserirFinal(Lista *L, int num){
    Lista *novo, *p = L;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info =  num;
    novo->proximo = NULL;
    
    if(p==NULL){
        return novo;
    } else {
        while(p->proximo!=NULL){
            p = p->proximo;
        }
        p->proximo = novo;
        return L;
    }
}

Lista* imprimeDados(Lista *L){
    Lista *p = L;
    
    while(p!=NULL){
        printf("%d ", p->info);
        p = p->proximo;
    }
}

int main(){
    Lista *L1 = NULL;

    L1 = inserirFinal(L1, 5);
    L1 = inserirFinal(L1, 8);
    imprimeDados(L1);
    return 0;
}
