/**************************************
* Trabalho 3-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Bruno Silveira - matricula: 0050011381
***************************************/

//biblioteca de fila fila.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//nó da lista para armazenar valores reais
struct lista{
	char info[30];
	struct lista* prox;
}; typedef struct lista Lista;

struct fila{
	Lista* ini;
	Lista* fim;
};typedef struct fila Fila;


Fila* fila_cria(void)
{
	Fila* f= (Fila*)malloc(sizeof(Fila));
	f->ini=f->fim=NULL;
	return f;
}

//insere novo elemento no fim da fila
void fila_insere(Fila* f, char nome[])
{
	Lista* n= (Lista*)malloc(sizeof(Lista));
	strcpy (n->info,nome);
	n->prox=NULL;   //novo nó passa a ser o ultimo
	if (f->fim != NULL)  //verfica se lista nao esta vazia
	{
		f->fim->prox=n;	
	}
	else  //fila esta vazia
	{
		f->ini=n;
	}
	f->fim=n;  //fila aponta pra um novo elemento
}

char fila_retira(Fila* f,char* turn)
{
	Lista* t;
	if(fila_vazia(f))
	{
		printf("Fila vazia\n\n");
		exit(1);  //aborta programa
	}
	t=f->ini;
	strcpy(turn,t->info);
	f->ini=t->prox;
	if(f->ini==NULL)  //verifica se fila ficou vazia
	{
		f->fim=NULL;
	}
	free(t);	
}

void fila_libera(Fila* f)
{
	Lista* q=f->ini;
	while(q!=NULL)
	{
		Lista* t=q->prox;
		free(q);
		q=t;
	}
	free(f);
}

int fila_vazia(Fila* f)
{
  return f->ini == NULL;
}

void imprimir(Fila *f)
{
	Lista* q=f->ini;
    while (q!=NULL)
    {
        printf("%s\n",q->info);
        q = q->prox;
    }

}

