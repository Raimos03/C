
typedef struct lista Tlista;

Tlista* Tlista_cria_vazia( int ord, int rep );
void Tlista_exibe(Tlista* l);
int Tlista_vazia(Tlista* l);
int Tlista_cheia(Tlista* l);
int Tlista_avancaDir(Tlista* l,int* pos);
int busca(Tlista* l, int v, int* pos);
int busca_b(Tlista* l, int valor, int* pos);
int Tlista_insere(Tlista* l, int valor);
int Tlista_Get_Elemento(Tlista* l, int pos);
int Tlista_Get_qtdElementos(Tlista* l);
int Tlista_Get_maxElementos(Tlista* l);
void Tlista_Get_Tipo(Tlista* l);
int Tlista_Set(Tlista* l, int v, int pos);
int busca_exclusao(Tlista* l, int valor, int* pos);
int Tlista_Exclui(Tlista* l, int valor);
