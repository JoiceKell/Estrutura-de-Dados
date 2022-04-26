#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista* insereFinal(Lista *L, int num){
    Lista *novo, *p=L, *ant = NULL;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;
    
    if(p==NULL){
        return novo;
    } else {
        while(p->prox!=NULL)
            p=p->prox;
        
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

int contador(Lista *L){
    if(L==NULL){
        return 0;
    } else {
        return contador(L->prox)+1;
    }
}

Lista* trocaPoscicao(Lista *L, int pos1, int pos2){
    Lista *p1 = L, *p2 = L, *ant1=NULL, *ant2=NULL, *aux=NULL;
    int cont=0, count = 0;
    
    if(pos1 > pos2){
        pos1 = pos1 + pos2;
        pos2 = pos1 - pos2;
        pos1 = pos1 - pos2;
    }
    
    count = contador(L);
    printf("COUNT: %d\n", count);
    
    if(pos1 > count || pos2 > count){
        printf("Posição maior que a Lista: ");
        return L;
    }
    
    while(cont < pos1-1){
        cont++;
        ant1 = p1;
        p1=p1->prox;
    }
    
    cont = 0;
    while(cont < pos2-1){
        cont++;
        ant2 = p2;
        p2=p2->prox;
    }
    
    if(p1 == L){
        aux = p1->prox;
        p1->prox = p2->prox;
        p2->prox = aux;
        ant2->prox = p1; 
        return p2;
    } else {
        aux = ant1->prox;
        ant1->prox = ant2->prox;
        ant2->prox = aux;
        aux = p1->prox;
        p1->prox = p2->prox;
        p2->prox = aux;
        return L;
    }
}

int main(){
    Lista *L1 = NULL;
    
    L1 = insereFinal(L1, 1);
    L1 = insereFinal(L1, 2);
    L1 = insereFinal(L1, 3);
    L1 = insereFinal(L1, 4);
    L1 = insereFinal(L1, 5);
    L1 = insereFinal(L1, 6);
    
    imprimeDados(L1); 
    printf("\nTroca Posicao: ");
    L1 = trocaPoscicao(L1, 1, 2);
    imprimeDados(L1);

    return 0;
}
