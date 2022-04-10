#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
    int info;
    struct lista *proximo;
}Lista;

Lista* inserirTerceiro(Lista *L, int num){
    Lista *novo, *p = L;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->proximo = NULL;
    
    if(p==NULL){
        return novo;
    } else if(p->proximo==NULL){
        novo->proximo = p->proximo;
        p->proximo = novo;
    } else {
        novo->proximo = p->proximo->proximo;
        p->proximo->proximo = novo;
    }
    
    return L;
}
Lista* imprimeDados(Lista *L){
    Lista *p = L;
    
    while(p!=NULL){
        printf("%d ", p->info);
        p = p->proximo;
    }
}

int main()
{
    Lista *L1 = NULL;
    L1 = inserirTerceiro(L1, 8);
    L1 = inserirTerceiro(L1, 66);
    L1 = inserirTerceiro(L1, 14);
    L1 = inserirTerceiro(L1, 6);
    L1 = inserirTerceiro(L1, 45);
    
    imprimeDados(L1);
    return 0;
}
