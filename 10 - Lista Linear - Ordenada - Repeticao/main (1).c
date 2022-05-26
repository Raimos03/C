#include <stdio.h>
#include "ListaLinear_tad.h"

int main(){

    Tlista* l=Tlista_cria_vazia(0,1);
    int pos;
    
    Tlista_insere(l,9);
    Tlista_insere(l,3);
    Tlista_insere(l,4);
    Tlista_insere(l,3);
    Tlista_insere(l,3);
    Tlista_insere(l,10);
    Tlista_insere(l,9);
    
    //int r=busca(l,0,&pos); //depuracao
    //printf("%d  - %d",r,pos);
    Tlista_insere(l,10);
    Tlista_exibe(l);
    Tlista_insere(l,6);

    printf("Elemento da 3 posicao: \n ");
    printf("%d\n",Tlista_Get_Elemento(l,3));

    Tlista_Get_Tipo(l);
    Tlista_Exclui(l,5);
    Tlista_exibe(l);
    Tlista_Exclui(l,9);
    Tlista_exibe(l);
    Tlista_Exclui(l,3);
    Tlista_exibe(l);

    Tlista_Set(l,25,1);
    Tlista_exibe(l);

    return 0;
}