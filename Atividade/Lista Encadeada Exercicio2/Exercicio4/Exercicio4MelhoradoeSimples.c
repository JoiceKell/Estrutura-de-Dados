#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *ant;
    struct lista *prox;
}Lista;

Lista* insereInicio(Lista *L, int num){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = L;
    novo->ant = NULL;
    
    if(L!=NULL)
        L->ant = novo;
        
    return novo;
}

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

Lista* retirar(Lista *L, int num){
    Lista *p=L;
    
    while(p!=NULL && p->info != num)
        p=p->prox;
        
    if(p==NULL)
        return NULL;
        
    if(p==L)
        L=p->prox;
    else 
        p->ant->prox = p->prox;
    
    if(p->prox != NULL)
        p->prox->ant = p->ant;
    
    free(p);
    return L;
}

void imprimeDados(Lista *L){
    if(L!=NULL){
        printf("%d ", L->info);
        imprimeDados(L->prox);
    }
}

Lista* busca(Lista *L, int num){
    while(L!=NULL){
        if(L->info == num){
            printf("\nDado %d encontrado!", L->info);
            return L;
        }
        L=L->prox;
    }
    printf("\nDado não encontrado!");
    return NULL;
}

Lista* retira_prefixo(Lista *L, int n){
    Lista *p=L, *L2=L;
    int cont = 0;
    
    if(n>0){
        while(p!=NULL && cont < n){
            p=p->prox;
            L2 = retirar(L2, L2->info);
            cont++;
        }
    } else {
        printf("\n\nO prefixo deve ser maior que 0");
    }
    return L2;
}

int main(){
    Lista *L1=NULL;
    
    L1 = insereFinal(L1, 1);
    L1 = insereFinal(L1, 2);
    L1 = insereFinal(L1, 3);
    imprimeDados(L1);
    L1 = retira_prefixo(L1, 2);
    printf("\n");
    imprimeDados(L1);

    return 0;
}
