#include <stdio.h>
#include <stdlib.h>
#include "ListaLinear_tad.h"

#define max_al 8

//typedef struct tinf Linf;
struct lista{

    int l[max_al]; //*queria criar um tipo de dado para o conjunto, assim e mais facil
    int qtel; //qtd elementos
    int max; // qtd maxima de elementos
    int ordenada; //1 se sim, 0 se nao
    int repeticao; //1 se sim, 0 se nao
};

Tlista* Tlista_cria_vazia( int ord, int rep ) //passagem por referencia
{
    Tlista* nl= (Tlista*) malloc (sizeof(Tlista));
    if(!nl){

        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    nl->qtel=0;
    nl->ordenada=ord;
    nl->repeticao=rep;
    nl->max=max_al;
    return nl;
}

void Tlista_exibe(Tlista* l){
    int i=0;
    while(i<l->qtel){
        printf("%d - ",l->l[i]);
        i++;
    }
    printf("\n");
}

int Tlista_vazia(Tlista* l){
    return l->qtel==0;
}
int Tlista_cheia(Tlista* l){
    return l->qtel==l->max;
}

int Tlista_avancaDir(Tlista* l,int* pos){

    int i =l->qtel;
    int temp;

    for(i;i>*pos;i--){
        temp=l->l[i-1];
        l->l[i]=temp;
    }
    return i==*pos;
}

int busca(Tlista* l, int v, int* pos){
    int i;
    int clasf, repet;
    clasf=l->ordenada;
    repet=l->repeticao;

    if (!clasf){ // nao classificada sem rep
    // ja possuo a posicao do ultimo elemento da lista; qtel

        for(i=0;i<l->qtel;i++){

            if (l->l[i]==v){ //existe
                *pos=i++; //guardo em (pos) a posicao do 1 elemento encontrado
                // encontrou
                return 1;
            }
        }        
        return 0;
    }
    else{ // classificada
        i=0;
        int achou=0;

        while(i<l->qtel && l->l[i]<=v ){
            if(l->l[i]==v){
                achou=1;
            }
            i++;
        }
        *pos=i;
    return achou==1;
  }
}

int busca_b(Tlista* l, int valor, int* pos){

    int inicio, fim,meio;
    int achou =0;
    inicio=0;
    fim=l->qtel-1;

    while(!achou && inicio<=fim){

        meio=(inicio+fim)/2;
        if (valor>l->l[meio]){
            inicio=meio+1;
        }
        else if (valor<l->l[meio]){
           fim=meio-1;
        }
        else{
            *pos=meio; //achou
            achou=1;
            return 1;
        }
    }

    return achou;
}

int busca_exclusao(Tlista* l, int valor, int* pos){

    int achou=-1;
    if (l->ordenada){
        achou=busca_b(l,valor,pos);
    }
    else{ //lista desordenada
        achou=busca(l,valor,pos);
    }
    if(achou!=1){
        achou=-1;
    }
    return achou;   
}

int Tlista_insere(Tlista* l, int valor){

    int clasf, repet;
    clasf=l->ordenada;
    repet=l->repeticao;
    int res, pos,cheia;

    cheia=Tlista_cheia(l);

    //no primeiro caso se a lista for vazia , inclui de qualquer modo
    // faço a busca se a lista nao for vazia

    if (cheia){
        printf("Impossivel colocar um novo elemento \n");
        printf("A lista esta cheia \n");
        return -1;
    }

    else if (Tlista_vazia(l) || (clasf==0 && repet==1)){// vazia ou classificada se estiver vazia. Bem como Nao classif e com rep, inclui  no ultimo
        
        l->l[l->qtel]=valor;
        l->qtel++;
        return 1;
        }

    else if (!clasf){//n classificada e sem repeticao

        res=busca(l,valor,&pos);

        if (!res){
            l->l[l->qtel]=valor;
            l->qtel++;
            printf("Valor inserido com sucesso \n");
            return 1;
        }
        else {
            printf("A lista nao aceita valores repetidos. Valor %d na %d posicao \n",valor, pos+1);
            return 0;
        }
    }

    else{ // classificada
        res=busca(l,valor,&pos);

        if(repet){ // com repeticao e nao tiver o numero
            //chega para la;
            if(Tlista_avancaDir(l,&pos)){
                l->l[pos]=valor;
                l->qtel++;
                return 1;
                    }
                }
        else{ // sem repeticao
            if(!res){ //se elmento nao esta, inclui
                if(Tlista_avancaDir(l,&pos)){
                    l->l[pos]=valor;
                    l->qtel++;
                    return 1;
                    }
                }
            else{
                printf("A lista nao aceita valores repetidos. Valor %d na %d posicao \n",valor, pos+1);
                return 0;
                }
            }
    }
    printf("Erro ao reposicionar os elementos. Direita\n");
    return -2;
}

int Tlista_Get_Elemento(Tlista* l, int pos){

    if (pos>=0 && pos <=l->qtel){
       return l->l[pos-1];
    }
    return 0;
}
int Tlista_Get_qtdElementos(Tlista* l){
    return l->qtel;
}
int Tlista_Get_maxElementos(Tlista* l){
    return l->max;
}
void Tlista_Get_Tipo(Tlista* l){

    printf("\n<< Tipo: %d - %d >>",l->ordenada,l->repeticao);
    if (l->ordenada)
        printf(" Lista ordenada");
    else
        printf(" Lista desordenada");
    if (l->repeticao)
        printf(" com repeticao");
    else
        printf(" sem repeticao"); 
    printf("\n");
    return;
}
int Tlista_Exclui(Tlista* l, int valor){
    int pos, res, pinicio,pfim,i, desloc;
    pinicio=0;
    pfim=0;
  
    if (Tlista_vazia(l)){
        printf("Lista Vazia\n");
        return 0;
    }
    res=busca_exclusao(l,valor,&pos);
    i=pos;
    if(res==-1){ // nao encontrou
        printf("O elemento a ser excluido nao existe na lista\n");
        return res;
    }
    else if (l->ordenada){ // lista ordenada ( classificada)
        //ja tenho a posicao de algum elemento    

        if (l->repeticao){// com repeticao
            while(l->l[i]==valor && i<l->qtel){ // procurando pela direita
                i++;
            }
            pfim=i-1;
            i=pos;
            while(l->l[i]==valor && i>=0){ // procurando pela esquerda
                i--;
            }
            pinicio=i+1;
            //printf("%d %d\n", pinicio,pfim);
        }       
        else { // sem repeticao
            pinicio=pos;
            pfim=pos;
        }
        //deslocamento  ult-inicial+1
        desloc=pfim-pinicio+1;
        i++;
        while(i<l->qtel-desloc){
            l->l[i]=l->l[i+desloc];
            i++;
        }

        l->qtel=l->qtel-desloc;
    }
    else{ // caso contrario, lista desordenada

        if (l->repeticao){ // tem repeticao
            while(i<l->qtel){
                if(l->l[i]==valor){
                    do {l->l[i]=l->l[l->qtel-1];l->qtel--;}
                    while (l->qtel>=i&&l->l[(l->qtel)-1]==valor);                     
                }
                else{
                    i++;
                    }
                //if(l->l[i]==valor){l->l[i]=l->l[l->qtel-1];}    
                }
        }
        else{ // caso contrario
            l->l[i]=l->l[l->qtel-1];
            l->qtel--;
        }
    }
    return 0;
}

int Tlista_Set(Tlista* l, int v, int pos){

    if (pos<=l->qtel-1|| pos >=0){// mais especifico 
        l->l[pos]=v;
    }
    else {
        printf("Posicao invalida \n");
    }
    return 0;
}