#include <stdio.h>
#include "ListaEncadeada.h"

void* preenche_estrutura(void* est){

  int i=1;
  for(i=1;i<=100;i++){
    i=i*2;
    est=insere_ordenado(est,i);
     
  }
  return est;

}

int main(void) {

   // Lista Encadeada

  Lista* lse= inicializa();
  lse=preenche_estrutura(lse);
  imprime(lse);
  lse=retira(lse,6);
  lse=retira(lse,40);
  lse=retira(lse,126);

  imprime(lse);
  libera_rec(lse);

  
  return 0;
}