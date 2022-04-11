#include <stdio.h>
#include <stdlib.h>
#include "exercicio2.h"

typedef struct lista{
	int info;
	struct lista *prox;
}Lista;

Lista* separa(Lista* L, int v){
	Lista *p=L, *aux;
	
	while(p!=NULL && p->info!=v){
		p = p->prox;
	}	
	
	if(p==NULL)
		return NULL;
		
	aux = p->prox;
	p->prox = NULL;
	return aux;
}

Lista* concatenar(Lista* L1, Lista* L2){
	Lista *p = L1, *r = L2;
	
	if (p == NULL && r == NULL)
	{
		printf("Listas vazias!!!");
		return NULL;
	}
	else if(p == NULL)
	{
		return L2;
	}
	else{
		while(p->prox!=NULL){
			p = p->prox;
		}
		p->prox = L2;
		return L1;		
	}

}

Lista* insereInicio(Lista *L, int v){
	Lista *novo;
	novo = (Lista*)malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = L;	
	return novo;	
}

void imprimir(Lista *L){
	Lista *p = L;
	printf("\n");
	while(p!=NULL){
		printf("[%d] -> ", p->info);
		p = p->prox;
	}
}
