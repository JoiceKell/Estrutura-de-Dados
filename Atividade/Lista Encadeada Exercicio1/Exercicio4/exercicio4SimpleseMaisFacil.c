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
    } else {
        while(p->prox != NULL)
            p=p->prox;
            
        novo->prox = p->prox;
        p->prox = novo;
        return L;
    }
}

Lista* controi(int n, int *v){
    Lista *L=NULL;
    
    for(int i = 0; i < n; i++){
        L = insereFinal(L, v[i]);    
    }
    return L;
}

void imprimeDados(Lista *L){
    if(L!=NULL){
        printf("%d ", L->info);
        imprimeDados(L->prox);
    }
}

Lista* retiraDados(Lista *L, int num){
    Lista *p=L, *ant=NULL;
    
    while(p!=NULL && p->info != num){
        ant = p;
        p=p->prox;
    }
    
    if(p==NULL){
        return L;
    }
    
    if(ant == NULL){
        L = p->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p);
    return L;
}

Lista* retira_prefixo(Lista *L, int n){
    Lista *p=L, *L2=L;
    int cont = 0;
    
    if(n>0){
        while(p!=NULL && cont < n){
            p=p->prox;
            L2 = retiraDados(L2, L2->info);
            cont++;
        }
    } else {
        printf("\n\nO prefixo deve ser maior que 0");
    }
    return L2;
}

int main(){
    Lista *L1 = NULL, *L2=NULL;
    int vet[] = {3, 8, 1, 7, 2};
    
    L1 = insereFinal(L1, 1);
    L1 = insereFinal(L1, 4);
    L1 = insereFinal(L1, 5);
    L1 = insereFinal(L1, 6);
    imprimeDados(L1);
    
    L2 = retira_prefixo(L1, 4);
    printf("\n");
    imprimeDados(L2);

    return 0;
}
