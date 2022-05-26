#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"


//typedef struct no Nof; //L encadeada - Pilha

/*
struct  no{
    int info;
    struct Nof* prox;
};
typedef struct fila Fila; // Pilha
struct fila{
    
    Nof* noinicio;
    Nof* nofinal;
    
};
*/

int fila_vazia(Fila* f){

  return f->noinicio==NULL && f->nofinal==NULL;
}

void exibe_fila(Fila* p){
  printf("Fila:\n");

  if(fila_vazia(p)){

    printf(" -- Fila vazia -- \n");
  }

  else{
    
  
    int i=0;
    
    Nof* a=p->noinicio;
    while(a!=NULL){
        printf("\t %d - %d\n",i,(a->info));
        a=a->prox;
      i++;
      }
  
    printf("\n");
    }
}
void libera_fila(Fila* p){

    Nof* t= p->noinicio;
    for(t; t!=NULL;){

        Nof * a=t->prox;
        free(t);
        t=a;      
    }
    free(p);
}

int  pop_fila(Fila* f){

    Nof* t;
    int v;

    if (fila_vazia(f)){
      return 0;
    }
  
    t=f->noinicio;
    v=t->info;

    f->noinicio=t->prox;
    if(f->noinicio==NULL)
        f->nofinal=NULL;
    
    free(t);
    return v;

}
void push_fila(Fila* f,int n){

    Nof* e=(Nof*) malloc  (sizeof(Nof));
    e->info=n;
    e->prox=NULL;

    if(f->nofinal!=NULL){
        f->nofinal->prox=e;
    }
    else{
        f->noinicio=e;
    }

    f->nofinal=e;
}

Fila* cria_fila(){

    Fila* n= (Fila*) malloc (sizeof(Fila));
    n->noinicio=NULL;
    n->nofinal=NULL;
    return n;
}

