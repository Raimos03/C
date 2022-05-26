#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

// preciso declarar a estrutura no arquivo para nao dar erro no visual code ou atraves da declaracao: struct no { struct No* prox, int info}
/*
typedef struct no No; //L encadeada - Pilha
struct  no{
    int info;
    No* prox;
};

typedef struct pilha Pilha; // Pilha
struct pilha{
    int topo;
    int tam;
    No* elem;
};
*/

void exibe_pilha(Pilha* p){
    No* a=p->elem;
    int i=p->tam;

  if (p->tam==0){
    printf("-- PIlha Vazia --\n");
    return ;
    }

  printf("Pilha: \n");

  printf("\t Topo : %d | Tam: %d\n\n", p->topo,p->tam);
    while(a!=NULL){
        printf("\t %d: %d\n",i,(a->info));
        a=a->prox;
        i--;
    }
  printf("\n");

}
void libera_pilha(Pilha* p){

    No* t;
    No* a=p->elem;
  
    for(*a; a!=NULL;){
        t=a->prox;
        free(a);
        a=t;      
    }
    free(p);
}
void push_pilha(Pilha *p, int numero)
{

    No* n = (No*) malloc (sizeof(No));
    if(!n){
        printf("Erro na alocação de novo No n No\n");
        exit(1);
    }
 
    n->info=numero;
    n->prox=p->elem;
    p->elem=n;
    p->topo=numero;
    p->tam=p->tam+1;
}
int pop_pilha(Pilha* p){ //retira e retorna o valor retirado


  if (p->topo==-1){
        printf("Pilha vazia \n");
    }
    
    No* t;
    int v_ult;
    
    t=p->elem;
    v_ult=t->info;

    p->elem=t->prox;
    p->topo=v_ult;
    p->tam=p->tam-1;

    free(t);
    if (p->tam==0){
      p->topo=-1;
    }
  
    return v_ult;
}
int pilha_vazia(Pilha* p){
    if (p->tam==0){
        return 1;
    }
    return 0;
}
Pilha* cria_pilha(){
    Pilha* p = (Pilha*) malloc ( sizeof( Pilha));
    if (!p){
        printf("Erro na alocação de memoria\n");
    }
    p->topo=-1; //inteiro
    
    p->elem= NULL;
  
    p->tam=0;
    return p;
}

int get_NumeroElementos(Pilha* p){
    return p->tam;
}
