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

void imprimeDados(Lista *L){
    if(L!=NULL){
        printf("%d ", L->info);
        imprimeDados(L->prox);
    }
}

void removeDuplicadas(Lista *L){
    Lista *pos=L->prox;
    
    while(pos!=NULL){
        if(L->info != pos->info){
            L = pos;
            pos=pos->prox;
        } else {
            L->prox = pos->prox;
            free(pos);
            pos=L->prox;
        }
    }
}

int main(){
    Lista *L1=NULL;
    
    L1 = insereFinal(L1, 2);
    L1 = insereFinal(L1, 1);
    L1 = insereFinal(L1, 1);
    L1 = insereFinal(L1, 2);
    imprimeDados(L1);
    
    removeDuplicadas(L1);
    printf("\n");
    imprimeDados(L1);
    

    return 0;
}
