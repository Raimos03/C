struct lista {
 int info;
 struct lista* prox;
};
typedef struct lista Lista;


Lista* cria (int v);
Lista* inicializa();
int vazia (Lista* l);
Lista* insere (Lista* l, int i);
void imprime (Lista* l);
Lista* busca (Lista* l, int v);
Lista* insere_ordenado (Lista* l, int v);
void libera_rec (Lista* l);
Lista* retira (Lista* l, int v);
