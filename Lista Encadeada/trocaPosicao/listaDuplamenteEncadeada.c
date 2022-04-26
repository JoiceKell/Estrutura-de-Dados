#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *ant;
    struct lista *prox;
}Lista;

Lista* inseririFinal(Lista *L, int num){
    Lista *novo, *p=L;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;
    
    if(L==NULL){
        novo->ant = NULL;
        return novo;
    } else {
        while(p->prox!=NULL)
            p = p->prox;
        
        novo->ant = p;
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
    Lista *p1 = L, *p2 = L, *aux=NULL, *anterior, *proximo;
    int cont=0, count = 0;
    
    if(pos1 == pos2)
        return L;
    
    if(pos1 > pos2){
        pos1 = pos1 + pos2;
        pos2 = pos1 - pos2;
        pos1 = pos1 - pos2;
    }
    
    count = contador(L);
    
    if(pos1 > count || pos2 > count){
        printf("Posição maior que a Lista: ");
        return L;
    }
    
    while(cont < pos1-1){
        cont++;
        p1=p1->prox;
    }
    
    cont = 0;
    while(cont < pos2-1){
        cont++;
        p2=p2->prox;
    }
    
    if(p1 != L && p2->prox != NULL){
        anterior = p2->ant;
        proximo = p2->prox;
        p1->ant->prox = p2;
        p2->ant->prox = p1;
        p1->prox->ant = p2;
        p2->prox->ant = p1;
        p2->prox = p1->prox;
        p1->prox = proximo;
        p2->ant = p1->ant;
        p1->ant = anterior;
        return L;
    }
    
    if(p1 != L && p2->prox == NULL){
        anterior = p1->ant;
        proximo = p1->prox;
        p1->ant->prox = p2;
        p2->ant->prox = p1;
        p1->prox->ant = p2;
        p1->ant = p2->ant;
        p1->prox = p2->prox;
        p2->ant = anterior;
        p2->prox = proximo;
        return L;
    }
    
    if(p1 == L && p2->prox != NULL){
        anterior = p2->ant;
        proximo = p2->prox;
        p2->ant->prox = p1;
        p1->prox->ant = p2;
        p2->prox->ant = p1;
        p2->ant = p1->ant;
        p2->prox = p1->prox;
        p1->ant = anterior;
        p1->prox = proximo;
        return p2;
    }
    
    if(p1 == L && p2->prox == NULL){
        proximo = p1->prox;
        anterior = p2->ant;
        p1->prox->ant = p2;
        p2->ant->prox = p1;
        p1->prox = p2->prox;
        p2->prox = proximo;
        p2->ant = p1->ant;
        p1->ant = anterior;
        return p2;
    }
}

int main(){
    Lista *L1=NULL;
    
    L1 = inseririFinal(L1, 1);
    L1 = inseririFinal(L1, 2);
    L1 = inseririFinal(L1, 3); 
    L1 = inseririFinal(L1, 4);
    L1 = inseririFinal(L1, 5);
    L1 = inseririFinal(L1, 6);
    L1 = inseririFinal(L1, 7);
    L1 = inseririFinal(L1, 8);
    imprimeDados(L1);

    printf("\nTroca Posição: ");
    L1 = trocaPoscicao(L1, 1, 8);
    imprimeDados(L1);

    return 0;
}