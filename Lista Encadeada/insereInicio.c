#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
    int info;
    struct lista *proximo;
}Lista;

Lista* inserirInicio(Lista *L, int num){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->proximo = L;
    return novo;
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
    L1 = inserirInicio(L1, 8);
    L1 = inserirInicio(L1, 66);
    imprimeDados(L1);
    return 0;
}
