#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

Lista* insere(Lista *L, int num, int pos){
    Lista *novo, *p=L, *aux=NULL;
    
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    
    if(pos == 0){
        novo->ant = NULL;
        novo->prox = L;
        return novo;
    }
    
    for(int i = 0; i < pos-1; i++){
        p=p->prox;
    }
    
    novo->ant = p;
    novo->prox = p->prox;
    p->prox = novo;
    return L;
}
Lista* busca (Lista* l, int v){
	Lista* p;
	for (p=l; p!=NULL; p=p->prox)
		if (p->info == v)
			return p;
	return NULL;
}

Lista* retira (Lista* l, int v) {
	Lista* p = busca(l,v);
	
	if (p == NULL){
		printf("\nElemento nao encontrado para retirar!!!\n");
		return l; 
	}
	
	if (l == p)
		l = p->prox;
	else
		p->ant->prox = p->prox;
	
	if (p->prox != NULL)
		p->prox->ant = p->ant;
	
	free(p);
	return l;
}

Lista* trocaPosicao(Lista *L, int pos1, int pos2){
    Lista *novo, *p1=L, *p2=L;
    novo = (Lista*) malloc(sizeof(Lista));
    int cont = 0, aux1 = 0, aux2 = 0;

    while(p1!=NULL && cont < pos1){
        p1=p1->prox;
        cont++;
    }
    
    aux1 = p1->info;
    cont = 0;
    
    while(p2!=NULL && cont < pos2){
        p2=p2->prox;
        cont++;
    } 
    
    aux2 = p2->info;
    
    printf("P1->info %d \n", aux1);
    printf("P2->info %d \n", aux2);
    
    L = retira(L, aux1);
    L = retira(L, aux2);
    L = insere(L, aux2, pos1);
    L = insere(L, aux1, pos2);
    return L;
}


int main(){
    Lista *L1=NULL;
    
    L1 = inseririFinal(L1, 8);
    L1 = inseririFinal(L1, 5);
    L1 = inseririFinal(L1, 1); 
    L1 = inseririFinal(L1, 2);
    imprimeDados(L1);
    
    printf("\n");
    L1 = trocaPosicao(L1, 0, 3);
    printf("\nTroca Posição: ");
    imprimeDados(L1);
    return 0;
}
