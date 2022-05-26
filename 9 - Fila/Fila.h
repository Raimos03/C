
typedef struct nof Nof;
struct  nof{
    int info;
    Nof* prox;
};

typedef struct fila Fila; // Pilha
struct fila{
    
  Nof* noinicio;
  Nof* nofinal;
    
};


Fila* cria_fila();
void exibe_fila(Fila* p);
void libera_fila(Fila* p);
int  pop_fila(Fila* f);
void push_fila(Fila* f,int n);
int fila_vazia(Fila* f);
