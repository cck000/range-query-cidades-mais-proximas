#ifndef __AVL__
#define  __AVL__

typedef struct _municipio{
    
    int cod_uf, siafi_id, ddd, capital, cod_ibge;
    char nome_municipio[100], fuso[100];
    float latitude, longitude;

} tmunicipio;

typedef struct _titem{
    tmunicipio * reg;
    struct _titem * prox;
}titem;

typedef struct _node{
    titem * item;
    struct _node *esq;
    struct _node *dir;
    struct _node *pai;
    int h;
   
}tnode;

typedef struct _busca{
    titem * item;
    struct _busca * prox;
}tbusca;



void avl_insere_nome(tnode ** parv, tnode * pai, titem *reg);
void avl_insere_ddd(tnode ** parv, tnode * pai, titem *reg);
void avl_insere_coduf(tnode ** parv, tnode * pai, titem *reg);
void avl_insere_longi(tnode ** parv, tnode * pai, titem *reg);
void avl_insere_lati(tnode ** parv, tnode * pai, titem *reg);

void avl_RQ_ddd(tnode **nodo, int min, int max, tbusca **res);
void avl_RQ_nome(tnode **nodo, char * nome, tbusca **res);
void avl_RQ_coduf(tnode **nodo, int min, int max, tbusca **res);
void avl_RQ_longi(tnode **nodo, float min, float max, tbusca **res);
void avl_RQ_lati(tnode **nodo, float min, float max, tbusca **res);

#endif
