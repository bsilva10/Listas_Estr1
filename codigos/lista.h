#include <stdio.h>
#include <stdlib.h>

struct lista{
       int info;
       struct lista *prox;
       };
       typedef struct lista Lista;
       
Lista * lst_cria()
{
      return NULL;
}
       
int lst_vazia(Lista *l)
{
	return(l==NULL);
}
 
Lista* lst_insere(Lista *x, int num)
{
   
   Lista *nova =(Lista*) malloc( sizeof (Lista));
   nova->info = num;
   nova->prox = x;
   return nova;
}
    


int lst_buscar(Lista *l,int chave)
{
    Lista *p;
    for(p=l;p!=NULL;p=p->prox)
    {
       if(chave==p->info) return 1;
    }
    return 0;
}

void lst_imprime( Lista *l) {
  Lista *h;
   for (h = l; h != NULL; h = h->prox) 
   {
      printf( "%d", h->info);
      if(h->prox!=NULL)
    		printf(" -> ");
      else
    		printf(" -> NULL\n");
    }
}

Lista* lst_separa (Lista* l, int n) 
{
     Lista* p;   /* variável auxiliar para percorrer a lista */
     Lista* q;   /* variável auxiliar para nova lista */
     
       for (p = l; p != NULL ; p = p->prox)

          if (p->info == n) 
          {
              q = p->prox; 
              p->prox = NULL; 
          return q;
          }
return NULL;
}
	
	

