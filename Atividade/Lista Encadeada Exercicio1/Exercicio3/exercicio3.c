#include <stdio.h>
#include <stdlib.h>
#include "exercicio3.h"

typedef struct lista{
	int info;
	struct lista *prox;
}Lista;

Lista* insereFinal(Lista *L, int num){
	Lista *novo, *p = L;
	novo = (Lista*) malloc (sizeof(Lista));
	novo->info = num;
	novo->prox = NULL;
	
	if(p==NULL){
		return novo;
	} else {
		while(p->prox!=NULL){
			p = p->prox;
		}
		p->prox = novo;
		return L;
	}
}

void imprimir(Lista *L){
	Lista *p = L;
	
	printf("Lista recebe vetor: \n");
	while(p!=NULL){
		printf("%d ", p->info);
		p = p->prox;
	}
}

Lista* constroi(int n, int *v){
    int i;
    Lista *L2 = NULL;
    
    for(i = 0; i < n; i++){
        L2 = insereFinal(L2, v[i]);
    }
    return L2;
}
