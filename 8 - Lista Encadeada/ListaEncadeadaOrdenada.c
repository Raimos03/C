#include <stdio.h>
#include "ListaEncadeada.h"
#include <stdlib.h>


Lista* cria (int v)
{
 Lista* p = (Lista*) malloc(sizeof(Lista));
 p->info = v;
 return p;
}

Lista* inicializa (void)
{
 return NULL;
}

int vazia (Lista* l)
{
 return (l == NULL);
}

Lista* insere (Lista* l, int i)
{
 Lista* novo = (Lista*) malloc(sizeof(Lista));
 novo->info = i;
 novo->prox = l;
 return novo;
}

void imprime (Lista* l)
{
printf("\n-- Lista Encadeada -- \n\n");
Lista* p; /* variável auxiliar para percorrer a lista */
for (p = l; p != NULL; p = p->prox)
  printf("\tinfo = %d\n", p->info);
}

Lista* busca (Lista* l, int v)
{
 Lista* p;
 for (p=l; p!=NULL; p=p->prox)
 if (p->info == v)
 return p;
 return NULL; /* não achou o elemento */
}

Lista* insere_ordenado (Lista* l, int v)
{
 Lista* novo = cria(v); /* cria novo nó */
 Lista* ant = NULL; /* ponteiro para elemento anterior */
 Lista* p = l; /* ponteiro para percorrer a lista*/
 /* procura posição de inserção */
 while (p != NULL && p->info < v) {
 ant = p;
 p = p->prox;
 }
 /* insere elemento */
 if (ant == NULL) { /* insere elemento no início */
 novo->prox = l;
 l = novo;
 }
 else { /* insere elemento no meio da lista */
 novo->prox = ant->prox;
 ant->prox = novo;
 }
 return l;
}

void libera_rec (Lista* l)
{
 if (!vazia(l))
 {
 libera_rec(l->prox);
 free(l);
 }
}

Lista* retira (Lista* l, int v) {
 Lista* ant = NULL; /* ponteiro para elemento anterior */
 Lista* p = l; /* ponteiro para percorrer a lista*/
 /* procura elemento na lista, guardando anterior */
 while (p != NULL && p->info != v) {
 ant = p;
 p = p->prox;
 }
 /* verifica se achou elemento */
 if (p == NULL)
 return l; /* não achou: retorna lista original */
 /* retira elemento */
 if (ant == NULL) {
 /* retira elemento do inicio */
 l = p->prox;
 }
 else {
 /* retira elemento do meio da lista */
 ant->prox = p->prox;
 }
 free(p);
 return l;
}
