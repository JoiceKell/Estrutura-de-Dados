#include <stdio.h>
#include <stdlib.h>
#include "exercicio4.h"

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

int retornaTamanho(Lista *L){
    int tamanho = 0;
    Lista *p = L;
    
    while(p!=NULL){
        p = p->prox;
        tamanho++;
    }
    return tamanho;
}

Lista* retira_prefixo(Lista* L, int *v){
	Lista *p=L, *ant=NULL;
	
	while(p==NULL && p->prox!=NULL){
		ant = p;
		p = p->prox;
	}
	
	if (ant==NULL){
		L = p->prox; //retirando o elemento do in�cio da lista
	}
	else{
		ant->prox = p->prox;
	}
	
	free(p);
	return L;	
}

Lista* retirarTodos(Lista* L, int *v, int qnt){
	Lista *p=L;
	int cont=0, tamanho;


    tamanho = retornaTamanho(L);
    if(qnt > tamanho){
        printf("\n\nTodos os dados retirados com Sucesso!");
        return 0;
    } else {
    	while(p!=NULL && cont < qnt){	
    		p=p->prox;
    		L = retira_prefixo(L, v);
    		cont++;
    	}
    	return L;
    }
}

void imprimir(Lista *L){
    Lista *p=L;
    
    while(p!=NULL){
        printf("%d-> ", p->info);
        p = p->prox;
    }
}

Lista* insereInicio(Lista *L, int num){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = L;
    return novo;
}

