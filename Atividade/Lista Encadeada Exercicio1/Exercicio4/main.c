/*
	Nome: Joice Mendes
	RA: 2348020
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 30
#include "exercicio4.h"

int main(){
    Lista *L2 = NULL;
    int vet[50], qnt, i;
    
    srand((unsigned) time(NULL));
    
    do{
        printf("Informe a quantidade de dados a ser retirado da lista: ");
            scanf("%d", &qnt);
        if(qnt < 0){
            printf("\n");
            printf("Valor Negativo!\nDigite novamente um número: \n");
        }
        
    }while(qnt<0);
    
    for(i = 0; i < TAM; i++){
        vet[i] = rand() % 101;
    }
   
    for(i = 0; i < TAM; i++){
         L2 = insereInicio(L2, vet[i]);
    }
    printf("Dados antes de retirar: \n");
    imprimir(L2);
    
    L2 = retirarTodos(L2, vet, qnt);
    printf("\nDados depois de retirados: \n");
    imprimir(L2);

    return 0;
}
