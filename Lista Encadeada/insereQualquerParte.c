#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista* insereFim(Lista* L, int v){
	Lista *novo, *p=L;
	novo = (Lista*)malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = NULL;

	if(L!=NULL){
		while(p->prox!=NULL){
			p = p->prox;
		}
		p->prox = novo;
		return L;
	}
	else{
		return novo;
	}
}

void imprimir(Lista *L){
	Lista *p = L;
	printf("\n");
	while(p!=NULL){
		printf("[%d] -> ", p->info);
		p = p->prox;
	}
}

int countList(Lista *L){
    if(L==NULL)
        return 0;
    else
        return countList(L->prox)+1;
}

Lista* insert(Lista *L, int num, int pos){
    Lista *novo, *p=L, *aux=NULL;

    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;

    if(pos == 0){
        novo->prox = L;
        return novo;
    }

    for(int i = 0; i < pos-1; i++){
        p=p->prox;
    }

    novo->prox = p->prox;
    p->prox = novo;
    return L;
}

int main(){
    Lista *L1 = NULL;
    int posicao, num;

    printf("\n\nTamanho da Lista eh: %d", countList(L1));

    printf("\nInforme o numero que deseja inserir o dado: ");
        scanf("%d", &num);

    printf("\nInforme a posição que deseja inserir o dado: ");
        scanf("%d", &posicao);

    L1 = insert(L1, num, posicao);
    imprimir(L1);
}


