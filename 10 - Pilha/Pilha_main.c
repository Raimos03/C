#include <stdio.h>
#include "Pilha.h"

void* preenche_estrutura(void* est){
  int i;

  for(i=1;i<=100;i++){
      i=i*2;
      push_pilha(est,i);
    }
  return est;
}

int main(void) {

  // Pilha

  Pilha* pilha = cria_pilha();
  preenche_estrutura(pilha);
  exibe_pilha(pilha);
  
  while(!pilha_vazia(pilha)){
    pop_pilha(pilha);
  }
  
  exibe_pilha(pilha);
  libera_pilha(pilha);
  
  return 0;
}