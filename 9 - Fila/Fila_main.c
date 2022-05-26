#include <stdio.h>
#include "Fila.h"

void* preenche_estrutura(void* est){

  int i=1;
  for(i=1;i<=100;i++){
      i=i*2;
      push_fila(est,i);
      }
  return est;
}

int main(void) {

  // FILA
  
  Fila* fila = cria_fila();
  printf("Fila vazia: %d\n,",fila_vazia(fila));

  int i;

  preenche_estrutura(fila);
  exibe_fila(fila);
  pop_fila(fila);
  pop_fila(fila);
  exibe_fila(fila);

  while(!fila_vazia(fila)){
    pop_fila(fila);
  }
  exibe_fila(fila);
  libera_fila(fila);
  
  return 0;
}