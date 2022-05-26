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


void exibe_pilha(Pilha* p);
void libera_pilha(Pilha* p);
void push_pilha(Pilha *p, int numero);
int pop_pilha(Pilha* p);
int pilha_vazia(Pilha* p);
Pilha* cria_pilha();

int get_NumeroElementos(Pilha* p);
