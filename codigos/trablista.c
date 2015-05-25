/**************************************
* Trabalho 1-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Bruno Silveira - matricula: 0050011381
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main()
{
    int num;
    Lista *x1,*x2;//declarando as listas
    
	x1=lst_cria();//criando a lista x1
    
    x1=lst_insere(x1,100);//insere os valores na lista x1
    x1=lst_insere(x1,200);
    x1=lst_insere(x1,300);
    x1=lst_insere(x1,400);
    x1=lst_insere(x1,500);
    x1=lst_insere(x1,600);
    x1=lst_insere(x1,700);
    x1=lst_insere(x1,800);
    x1=lst_insere(x1,900);
    x1=lst_insere(x1,1000);
    
    printf("\nLista criada (x1):");
    //Imprimi a Lista x1
    
    puts("\n/***************/\n");
	lst_imprime(x1);
    puts("\n/***************/\n");
    
    x2=lst_cria();//cria lista x2
    puts("Em qual valor deseja separar a lista?\n");
    scanf("%d",&num);
	x2=lst_separa(x1,num);
    
    
    printf("Separado apartir do %d:\n",num);
    //Segunda lista apos separação
    puts("\n/***************/\n");
    lst_imprime(x1);
	lst_imprime(x2);
    puts("\n/***************/\n");
    
    
    system("pause");
    return 0;
}
