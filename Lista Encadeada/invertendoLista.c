#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista* insereFinal(Lista *L, int num){
    Lista *novo, *p=L;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;
    
    if(p==NULL){
        return novo;
    } else{
        while(p->prox!=NULL)
            p=p->prox;
        
        novo->prox = p->prox;
        p->prox = novo;
        return L;
    }
}

int tamanhoLista(Lista *L){
    if(L==NULL){
        return 0;
    } else {
        return tamanhoLista(L->prox)+1;
    }
}

void imprimeDados(Lista *L){
    if(L!=NULL){
        printf("%d ", L->info);
        imprimeDados(L->prox);
    }
}

Lista* invertendoLista(Lista *L){
    int *vet, tam;
    Lista *p = L;
    
    vet = (int*) malloc(sizeof(int)*tamanhoLista(L));
    tam = tamanhoLista(L);
    
    for(int i = 0; i < tam; i++){
        vet[i] = p->info;
        p=p->prox;
    }
    
    p = L;
    for(int i = tam-1; i >= 0; i--){
        p->info = vet[i];
        p=p->prox;
    }
    return L;
}


int main(){
    Lista *L1=NULL, *L2=NULL;
    
    L1 = insereFinal(L1, 2);
    L1 = insereFinal(L1, 7);
    L1 = insereFinal(L1, 5);
    L1 = insereFinal(L1, 1);
    imprimeDados(L1);
    
    printf("\nTamanho da Lista eh: %d\n", tamanhoLista(L1));
    invertendoLista(L1);
    imprimeDados(L1);
    
    return 0;
}
