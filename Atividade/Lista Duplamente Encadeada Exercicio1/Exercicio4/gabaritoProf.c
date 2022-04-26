#include<stdio.h>
#include<stdlib.h>

struct lista2{
	struct lista2 *prox;
	struct lista2 *ant;
	int info;
};
typedef struct lista2 Lista2;

Lista2* iniciar(){
	return NULL;
}

Lista2* insere(Lista2 *L, int v){
	Lista2* novo;
	novo = (Lista2*) malloc(sizeof(Lista2));
	novo->info=v;
	novo->prox=L;
	novo->ant=NULL;
	
	if (L!=NULL){
		L->ant=novo;
	}
	
	return novo;
}

void imprime(Lista2* L){
	Lista2* p=L;
	printf("\n\n");
	
	if (p==NULL)
		printf("Nao ha elementos na Lista para imprimir!!!");
	else{
		while(p!=NULL){
			if(p->prox==NULL)
				printf("%d",p->info);
			else
				printf("%d -> ",p->info);
			p = p->prox;
		}
	}
}

Lista2* inserirFinal(Lista2 *L, int v){ //Fun��o gen�rica para inserir um n� ao final da lista
	Lista2 *p = L, *novo;
	
	novo = (Lista2*) malloc(sizeof(Lista2)); //Aloca um novo n� na mem�ria
	novo->info = v;
	novo->prox = NULL; //Como a iser��o � no final, ent�o o ponteior prox do novo n� sempre apontar� para NULL
	
	if(L==NULL){ //Verifica��o se a lista � vazia para fazer com que o n� anterior aponte para NULL
		novo->ant = NULL;
		L = novo;
	}
	else{ //Caso a lista n�o esteja vazia deve-se encontrar o �ltimo n� da lista
		while(p->prox!=NULL) //La�o de repeti��o para encontrar o �ltimo n� da lista
			p = p->prox;
		
		p->prox = novo; //O �ltimo n� aponta para o n� novo
		novo->ant = p; //Faz com que o ponteiro ant aponte para o �ltimo n� de L
	}
	
	return L;	
}


Lista2* constroi(int n, int *vet){ //RESOLU��O DO EXERC�CIO 3 - Lista Duplamente Encadeada
	int cont=0,i;
	Lista2 *L;
	
	L = iniciar();
	
	if (vet!=NULL && n!=0){
		
		for(i=0; i<n; i++){ //O tamanho do vetor � passado por par�metro			
			L = inserirFinal(L,vet[i]); //Chama a fun��o para inserir no final devido ao comportamento solicitado pelo enunciado		
		}	
	}
	else
		printf("\n\nO vetor e vazio e nao e possivel contruir uma lista!");
	
	return L;
	
}


Lista2* retira_prefixo(Lista2 *L, int n){ //RESOLU��O DO EXERC�CIO 4 - Lista Duplamente Encadeada - remove os n primeiros elementos da lista e retorna o restante
	Lista2 *p=L, *aux=L, *ant=NULL; 
	int cont1=0, cont2=0; //cont1 para controlar em qual n� o ponteiro deve parar para encontrar o ponto de corte
	
	if (n>0){ //Teste para atender ao enunciado de que o prefixo n�o pode ser menor ou igual a zero		
		while(p!=NULL && cont1<n){ //Loop para encontrar o ponto de corte, pode ser que n�o encontre pois o prefixo pode ser maior que o n�mero de n�s e o p ser� NULL
			p = p->prox;
			cont1++;
		}
		
		if (p==NULL){ //Caso n�o encontre o ponto de corte, deve-se eliminar a lista toda
			printf("\n\nO prefixo e maior que o numero de elementos da lista!!! Nesta lista tem %d nos!!! Todos os nos serao retirados!!!", cont1);
			while(aux!=NULL){
				ant = aux;
				aux = aux->prox;
				free(ant);
			}
			
			L = NULL;
		}
		else{ //Caso encontre o ponto de corte, elimina-se os n primeiros n�s
			while(cont2<n){
				ant = aux;
				aux = aux->prox;
				free(ant);
				cont2++;
			}			
			L = p; //Ajusta o ponteiro L com o apontamento de p para retornar
		}		
	} 
	else{ //Somente para informar ao usu�rio que o prefixo informado est� incorreto
		printf("\n\nO prefixo deve ser maior que 0!!!");
	}
		
	return L;
	
}


Lista2* busca(Lista2* L, int v){
	Lista2* p;
	
	for (p=L; p!=NULL; p=p->prox)
		if (p->info == v)
			return p;	
	/*p=L;
	while (p!=NULL){
		if (p->info == v)
			return p;
		p=p->prox;
	}*/
	
	return NULL;
}

Lista2* retira(Lista2* L, int v){
	Lista2* p;
	
	p = busca(L, v);
	
	if (p==NULL)
		return L;
	
	if (L==p){
		L = p->prox;
	}
	else
		p->ant->prox = p->prox;
	
	if (p->prox!=NULL)
		p->prox->ant = p->ant;
	
	free(p);
	
	return L;			
}




int main(){
	Lista2 *L1, *L2, *B, *Lconstroi;
	int n=10; //Determina o tamanho do vetor
	int vet[] = {10,20,30,40,50,60,70,80,90,100};
	
	L1 = iniciar();
	L2 = iniciar();
	
	L1 = insere(L1,5);
	L1 = insere(L1,4);
	L1 = insere(L1,3);
	L1 = insere(L1,2);
	
	//imprime(L1);
	
	//B = busca(L1,10);
	
	//if (B!=NULL)
	//	printf("\nO valor buscado e: %d", B->info);
	//else
	//	printf("\nNao foi encontrado");
	
	//L1 = retira(L1,3);
	//L1 = retira(L1,5);
	
	L1 = retira(L1,3);
	imprime(L1);
	
	Lconstroi = constroi(n, vet); //Chamada da fun��o relativa ao Exerc�cio 5
	imprime(Lconstroi);
	
	Lconstroi = retira_prefixo(Lconstroi, -4); //Chamada do fun��o relativa ao Exerc�cio 4
	
	imprime(Lconstroi);
	
}