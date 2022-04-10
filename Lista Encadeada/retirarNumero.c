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

Lista* retirar(Lista* L, int num){
	Lista *p=L, *ant=NULL;

    while(p!=NULL && p->info != num){
        ant = p;
        p = p->proximo;
    }
    
    if(p==NULL){
        return L;
    }
    
    if(ant == NULL){
        L = p->proximo; // ou L = NULL é a mesma coisa
    } else {
        ant->proximo = p->proximo;
    }
    free(p);
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
    L1 = inserirTerceiro(L1, 9);
    L1 = inserirTerceiro(L1, 4);
    L1 = inserirTerceiro(L1, 1);
    L1 = inserirTerceiro(L1, 3);
    printf("Antes do retiro: \n");
    imprimeDados(L1);
    L1 = retirar(L1, 4);
    printf("\nDepois do retiro: \n");
    imprimeDados(L1);
    return 0;
}
