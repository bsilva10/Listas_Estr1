/**************************************
* Trabalho 3-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Bruno Silveira - matricula: 0050011381
* Quiz
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fila.h"

int main()
{
	int players,p,op,pergunta,j,resp;
	char resposta;
	char playerinfo[50],insere[50];
	Fila *f1;
	f1=fila_cria();
	char perguntas[6][200] = {{"Em que ano Alan Turing construiu a maquina para quebrar codigos nazistas?\n\n a) 1940  b)1945  c)1943 d)1939\n\nResposta:"},
							  {"Em que pais foi sediada a copa de 1970?\n\n  a)Estados Unidos  b)Mexico  c)França  d)Inglaterra\n\nResposta:"},
							  {"Quem era o 1º Ministro ingles quando a Alemanha foi derrotada na 2º G.M?\n\n  a)Margaret Thatcher  b)Harold Wilson  c)Stanley Baldwin  d)Winston Churchill\n\nResposta:"},
							  {"Em que ano foi lançado o Playstation 2?\n\n  a)1998  b)2000  c)2001  d)2002\n\nResposta:"},
							  {"Em 2015, quantos anos fazem desde a criacao do protocolo de kyoto?\n\n  a)10 anos  b)15 anos  c)18 anos  d)20 anos\n\nResposta:"},
							  {"De qual desses estudos Leornado Da Vince e considerado percursor?\n\n  a)Balistica  b)Teoria da evoluçao  c)Teoria da Relatividade  d)Bioquimica\n\nResposta:"}};
	char respostas[6][2] = {{"c"},{"b"},{"d"},{"b"},{"c"},{"a"}};

	printf("\n***Bem vindo ao Quiz! ***");
	
	do{
		printf("\nO que deseja fazer?");
		printf("\n1-Jogar!  2-Adicionar jogadores 3-Sair\n");
		scanf("%d",&op);
		if(op==3)
			{
			 fila_libera(f1);
			 return 0;	
			}
		if(op==2)
		{
			do
				{
				printf("Digite o nome do jogador. Digite 'fim' quando acabar. ");
				scanf("%s",&playerinfo);
				fflush(stdin);
			
				if(strcmp(playerinfo,"fim")==0)
				break;
				else	
				{
					players++;
					fila_insere(f1,playerinfo);
				}
					
				}while(1);
				
		}
		if(op==1)
		{
			if(fila_vazia(f1))
				{
					puts("Nao ha jogadores");
					exit(1);
				}
				else
				{
					while(players!=1)
					{
						fila_retira(f1,playerinfo);
						players--;
						printf("Vez de: %s\n",playerinfo);
						//puts("aaaaaaaaaaaa");
						pergunta= rand() % 6;
						pergunta= rand() % 6;
						
						for (p=0;perguntas[pergunta][p]!='\0';p++)
							printf("%c",perguntas[pergunta][p]);
						scanf("%s",&resp);
						fflush(stdin);
						
						if(respostas[pergunta][0]==resp)
						{
							strcpy(insere,playerinfo);
							puts("Resposta certa!");
							fila_insere(f1,insere);
							players++;
						}
						else
							puts("Resposta Errada!");
						
						if(players==1)
						{
							players=0;
							fila_retira(f1,playerinfo);
							printf("Parabens %s, voce foi o campeao!!!",playerinfo);
							break;
						}
						
					}
						
				}
		}
	}while(op!=1 || op!=2 || op!=3);
	
	fila_libera(f1);
	system("pause");
	return 0;
	
}


