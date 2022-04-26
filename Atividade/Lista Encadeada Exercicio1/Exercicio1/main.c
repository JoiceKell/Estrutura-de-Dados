/*
Nome: Joice Mendes
RA: 2348020
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "exercicio1.h"

int main(){
    Lista *L1=NULL, *novaLista;
    
    setlocale(LC_ALL, "Portuguese");
	
	L1 = insereInicio(L1,2);
	L1 = insereInicio(L1,3);
    L1 = insereInicio(L1,5);
    L1 = insereInicio(L1,9);
    L1 = insereInicio(L1,11);
    L1 = insereInicio(L1,3);
    L1 = insereInicio(L1,3);
    
    printf("Lista L1 antes de separar: ");
	imprimir(L1);
    novaLista = separa(L1,9);
    printf("\n");
	printf("\nNova lista após a divisao: ");
	imprimir(novaLista);
	printf("\n");
	printf("\nLista L1 depos de separada: ");
	imprimir(L1);
}
