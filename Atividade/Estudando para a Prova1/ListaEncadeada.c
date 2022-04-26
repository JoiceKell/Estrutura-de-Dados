#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista* inicializa(){
    return NULL;
}

Lista* insereInicio(Lista *L, int num){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = L;
    return novo;
}

Lista* insereFinal(Lista *L, int num){
    Lista *novo, *p=L;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;
    
    if(p==NULL){
        return novo;
    } else {
        while(p->prox!=NULL)
            p=p->prox;
        
        novo->prox = p->prox;    
        p->prox = novo;
        return L;
    }
}

Lista* insereSegunda(Lista *L, int num){
    Lista *novo, *p=L, *aux;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;
    
    if(p==NULL){
        return novo;
    } else {
        novo->prox = p->prox;
        p->prox = novo;
        return L;
    }
}

Lista* insereTerceiro(Lista *L, int num){
    Lista *novo, *p=L;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;
    
    if(p==NULL){
        return novo;
    } else if(p->prox == NULL){
        novo->prox = p->prox;
        p->prox = novo;
        return L;
    } else {
        novo->prox = p->prox->prox;
        p->prox->prox = novo;
        return L;
    }
}

int totalLista(Lista *L){
    if(L==NULL){
        return 0;
    } else {
        return totalLista(L->prox)+1;
    }
}

Lista* inserePosicao(Lista *L, int num, int pos){
    Lista *novo, *p=L;
    int cont = 1, tamLista = 0;
    
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    
    if(pos == 1){
        novo->prox = p;
        return novo;
    } else {
        while(p->prox!=NULL && cont < pos-1){
            p=p->prox;
            cont++;
        }
        novo->prox = p->prox;
        p->prox = novo;
        return L;
    }
}

void buscaDados(Lista *L, int num){
    while(L->prox!=NULL && L->info != num)
        L=L->prox;
        
    if(L->info == num){
        printf("\nDados %d econtrado na lista!", L->info);
    } else {
        printf("\nDado não encontrado!");
    }
}

Lista* removeDado(Lista *L, int num){
    Lista *p=L, *ant=NULL;
    
    while(p!=NULL && p->info != num){ 
        ant = p;
        p=p->prox;
    }       
    
    if(ant == NULL){
        L = p->prox;
    } else {
        ant->prox = p->prox;
    }
    return L;
}

Lista* libera(Lista *L){
    Lista *p = L, *t;
    
    while(p!=NULL){
        t = p->prox;
        free(p);
        p = t;
    }
    return NULL;
}

Lista *insereOrdenado(Lista *L, int num){
    Lista *novo, *p=L, *ant = NULL;
    novo = (Lista*) malloc(sizeof(Lista));    
    novo->info = num;
    
    while(p!=NULL && num > p->info){
        ant = p;
        p=p->prox;
    }   
    
    if(ant==NULL){
        novo->prox = L;
        return novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
        return L;
    }
}

Lista* ordenaLista(Lista *L){
    Lista *L2=NULL, *p=L;
    
    while(p!=NULL){
        L2 = insereOrdenado(L2, p->info);
        p=p->prox;
    }
    return L2;
}

void imprimeDados(Lista *L){
    if(L!=NULL){
        printf("%d ", L->info);
        imprimeDados(L->prox);
    }
}

Lista* separa(Lista *L, int num){
    Lista *p=L, *aux;
    
    while(p!=NULL && p->info != num)
        p=p->prox;
        
    aux = p->prox;
    p->prox = NULL;
    return aux;
}

Lista* concatena(Lista *L1, Lista *L2){
    Lista *p=L1, *r=L2;
    
    if(p==NULL && r==NULL){
        printf("Listas vazias!");
        return NULL;
    } 
    
    if(p==NULL){
        return L2;
    } else {
        while(p->prox != NULL)
            p=p->prox;
        
        p->prox = L2;
        return L1;
    }
}


int main(){
    Lista *L1, *L2 = NULL;
    
    L1 = inicializa();
    L1 = insereFinal(L1, 1);
    L1 = insereFinal(L1, 240);
    L1 = insereFinal(L1, 3);
    L1 = insereFinal(L1, 480);
    L1 = insereFinal(L1, 1);
    L1 = insereFinal(L1, 10);
    imprimeDados(L1);
    
    /*printf("\nL2: ");
    L2 = ordenaLista(L1);
    imprimeDados(L2);
    printf("\nExclui Repetidas: ");
    L2 = excluirRepetidas(L2, 1);
    imprimeDados(L2);*/
    
    L2 = separa(L1, 480);
    printf("\nSepara: \n");
    imprimeDados(L2);
    printf("\nL1: \n");
    imprimeDados(L1);
    
    printf("\nConcatena: \n");
    L1 = concatena(L1, L2);
    imprimeDados(L1);
    

    return 0;
}
