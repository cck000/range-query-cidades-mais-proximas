#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include ".\include\avl.h"           //https://github.com/edpfacom/libfacom

int max(int a,int b){
    return a>b?a:b;
}

int altura(tnode *arv){
    int ret;
    if (arv==NULL){
        ret = -1;
    }else{
        ret = arv->h;
    }
    return ret;
}

void addlistano(tnode ** parv, titem * item){

    titem * aux;

    for (aux = (*parv)->item; aux->prox != NULL; aux = aux->prox);
    aux->prox = (titem*) malloc(sizeof(titem));
    aux->prox->reg = item->reg;
    aux->prox->prox = NULL;

}

void addlista(tnode ** parv, titem ** item){

    titem * aux;
    for (aux = *item; aux != NULL; aux = aux->prox);

    aux = (titem*) malloc(sizeof(titem));
    aux->reg = (*parv)->item->reg;
    aux->prox = NULL;
    
}

void _rd(tnode **parv){
    tnode * y = *parv; 
    tnode * x = y->esq;
    tnode * A = x->esq;
    tnode * B = x->dir;
    tnode * C = y->dir;

    x->pai = y->pai; // Atualiza o pai
    if (B != NULL) 
        B->pai = y; // Atualiza o pai de B

    y->esq = B; 
    x->dir = y;
    y->pai = x; // Atualiza o pai de y
    *parv  = x;
    y->h = max(altura(B),altura(C)) + 1;
    x->h = max(altura(A),altura(y)) + 1;
}

void _re(tnode **parv){
    tnode * x = *parv; 
    tnode * y = x->dir;
    tnode * A = x->esq;
    tnode * B = y->esq;
    tnode * C = y->dir;

    y->pai = x->pai; // Atualiza o pai
    if (B != NULL) 
        B->pai = x; // Atualiza o pai de B
    
    x->dir = B;
    y->esq = x; 
    x->pai = y;
    *parv  = y;
    x->h = max(altura(A),altura(B)) + 1;
    y->h = max(altura(x),altura(C)) + 1;
}

void _avl_rebalancear(tnode **parv){
    int fb;
    int fbf;
    tnode * filho;
    fb = altura((*parv)->esq) - altura((*parv)->dir);

    if (fb  == -2){
        filho = (*parv)->dir;
        fbf = altura(filho->esq) - altura(filho->dir);
        if (fbf <= 0){ /* Caso 1  --> ->*/
            _re(parv);
        }else{   /* Caso 2  --> <-*/
            _rd(&(*parv)->dir);
            _re(parv);
        }
    }else if (fb == 2){  
        filho = (*parv)->esq;
        fbf = altura(filho->esq) - altura(filho->dir);
        if (fbf >=0){ /* Caso 3  <-- <-*/
            _rd(parv);
        }else{  /* Caso 4  <-- ->*/
            _re(&(*parv)->esq);
            _rd(parv);
        }
    }
}

tnode * percorre_esq(tnode ** arv){
    tnode * aux = *arv;
    if (aux->esq  == NULL){
        return *arv;
    }else{
        while (aux->esq->esq != NULL)
            aux = aux->esq;
        return aux->esq;
    }
}

//função sucessor portado do livro "Introduction to Algorithms" de Thomas H. Cormen
tnode * sucessor(tnode ** parv){
    tnode * x = *parv;
    if (x->dir != NULL) {
        return percorre_esq(&(x->dir)); // Nó mais à esquerda na subárvore direita
    } else {
        tnode *y = x->pai;
        while (y != NULL && x == y->dir) {
            x = y;
            y = y->pai;
        }
        
        return y; // Menor ancestral de x cujo filho esquerdo é um ancestral de x
    }


}

int cmp_nome(titem* item1, titem * item2){

    return strcmp(item1->reg->nome_municipio, item2->reg->nome_municipio);
}

int cmp_ddd(titem * item1, titem * item2){

    return item1->reg->ddd - item2->reg->ddd;
}

int cmp_coduf(titem * item1, titem * item2){

    return item1->reg->cod_uf - item2->reg->cod_uf;
}

float cmp_longi(titem * item1, titem * item2){

    return item1->reg->longitude - item2->reg->longitude;
}

float cmp_lati(titem * item1, titem * item2){

    return item1->reg->latitude - item2->reg->latitude;
}

void avl_insere_nome(tnode ** parv, tnode * pai, titem * item){
    if (*parv == NULL){
        *parv = (tnode *) malloc(sizeof(tnode));
        (*parv)->pai = pai;
        (*parv)->item = (titem *) malloc(sizeof(titem));
        (*parv)->item = item;
        (*parv)->esq = NULL;
        (*parv)->dir = NULL;
        (*parv)->h = 0;

    }else if(cmp_nome((*parv)->item, item)>0){
        avl_insere_nome(&(*parv)->esq, *parv, item);
    }else if (cmp_nome((*parv)->item, item)<0){
        avl_insere_nome(&(*parv)->dir, *parv, item);
    }else{
        addlistano(&(*parv), item);
    }
    (*parv)->h = max(altura((*parv)->esq),altura((*parv)->dir)) + 1;
    _avl_rebalancear(parv);
}

void avl_insere_ddd(tnode ** parv, tnode * pai, titem * item){
    if (*parv == NULL){
        *parv = (tnode *) malloc(sizeof(tnode));
        (*parv)->item = (titem *) malloc(sizeof(titem));
        (*parv)->pai = pai;
        (*parv)->item = item;
        (*parv)->esq = NULL;
        (*parv)->dir = NULL;
        (*parv)->h = 0;

    }else if(cmp_ddd((*parv)->item, item)>0){
        avl_insere_ddd(&(*parv)->esq, *parv, item);
    }else if (cmp_ddd((*parv)->item, item)<0){
        avl_insere_ddd(&(*parv)->dir, *parv, item);
    }else{
        addlistano(&(*parv), item);
    }
    
    (*parv)->h = max(altura((*parv)->esq),altura((*parv)->dir)) + 1;
    _avl_rebalancear(parv);
}

void avl_insere_coduf(tnode ** parv, tnode * pai, titem * item){
    if (*parv == NULL){
        *parv = (tnode *) malloc(sizeof(tnode));
        (*parv)->item = (titem *) malloc(sizeof(titem));
        (*parv)->pai = pai;
        (*parv)->item = item;
        (*parv)->esq = NULL;
        (*parv)->dir = NULL;
        (*parv)->h = 0;

    }else if(cmp_coduf((*parv)->item, item)>0){
        avl_insere_coduf(&(*parv)->esq, *parv, item);
    }else if (cmp_coduf((*parv)->item, item)<0){
        avl_insere_coduf(&(*parv)->dir, *parv, item);
    }else{
        addlistano(&(*parv), item);
    }
    (*parv)->h = max(altura((*parv)->esq),altura((*parv)->dir)) + 1;
    _avl_rebalancear(parv);
}

void avl_insere_longi(tnode ** parv, tnode * pai, titem * item){
    if (*parv == NULL){
        *parv = (tnode *) malloc(sizeof(tnode));
        (*parv)->item = (titem *) malloc(sizeof(titem));
        (*parv)->pai = pai;
        (*parv)->item = item;
        (*parv)->esq = NULL;
        (*parv)->dir = NULL;
        (*parv)->h = 0;

    }else if(cmp_longi((*parv)->item, item)>0){
        avl_insere_longi(&(*parv)->esq, *parv, item);
    }else if (cmp_longi((*parv)->item, item)<0){
        avl_insere_longi(&(*parv)->dir, *parv, item);
    }else{
        addlistano(&(*parv), item);
    }
    (*parv)->h = max(altura((*parv)->esq),altura((*parv)->dir)) + 1;
    _avl_rebalancear(parv);
}

void avl_insere_lati(tnode ** parv, tnode * pai, titem * item){
    if (*parv == NULL){
        *parv = (tnode *) malloc(sizeof(tnode));
        (*parv)->item = (titem *) malloc(sizeof(titem));
        (*parv)->pai = pai;
        (*parv)->item = item;
        (*parv)->esq = NULL;
        (*parv)->dir = NULL;
        (*parv)->h = 0;

    }else if(cmp_lati((*parv)->item, item)>0){
        avl_insere_lati(&(*parv)->esq, *parv, item);
    }else if (cmp_lati((*parv)->item, item)<0){
        avl_insere_lati(&(*parv)->dir, *parv, item);
    }else{
        addlistano(&(*parv), item);
    }
    (*parv)->h = max(altura((*parv)->esq),altura((*parv)->dir)) + 1;
    _avl_rebalancear(parv);
}

void avl_destroi(tnode *parv){
    if (parv!=NULL){
        avl_destroi(parv->esq);
        avl_destroi(parv->dir);
        free(parv);
    }
}

void avl_RQ_nome(tnode **nodo, char * nome, tbusca **res) {
    if (nodo == NULL) {
        return;
    }

    tnode *current = percorre_esq(&(*nodo));
    
    while (current != NULL && strcmp(current->item->reg->nome_municipio, nome) < 0) {
        current = sucessor(&current);
    }
    while (current != NULL && strcmp(current->item->reg->nome_municipio, nome) == 0) {
        
        titem * x = current->item;
        tbusca * y;
        if ((*res) == NULL){
            (*res) = (tbusca*)malloc (sizeof(tbusca));
            (*res)->item = x;
            (*res)->prox = NULL;
        }else{

            for (y = *res ; y->prox != NULL; y = y->prox);
            y->prox= (tbusca*)malloc(sizeof(tbusca));
            y->prox->item = x;
            y->prox->prox = NULL;
        }
        
        current = sucessor(&current);
        
    }

}

void avl_RQ_ddd(tnode **nodo, int min, int max, tbusca **res) {
    if (nodo == NULL) {
        return;
    }

    tnode *current = percorre_esq(&(*nodo));
    
    while (current != NULL && (current->item->reg->ddd - min) < 0) {
        current = sucessor(&current);
    }
    if(max < min) max = 99999;
    while (current != NULL && (current->item->reg->ddd - max) <= 0) {
        
        titem * x = current->item;
        tbusca * y;
        if ((*res) == NULL){
            (*res) = (tbusca*)malloc (sizeof(tbusca));
            (*res)->item = x;
            (*res)->prox = NULL;
        }else{

            for (y = *res ; y->prox != NULL; y = y->prox);
            y->prox= (tbusca*)malloc(sizeof(tbusca));
            y->prox->item = x;
            y->prox->prox = NULL;
        }
        
        current = sucessor(&current);
        
    }

}

void avl_RQ_coduf(tnode **nodo, int min, int max, tbusca **res) {
    if (nodo == NULL) {
        return;
    }

    tnode *current = percorre_esq(&(*nodo));
    
    while (current != NULL && (current->item->reg->cod_uf - min) < 0) {
        current = sucessor(&current);
    }
    if(max < min) max = 99999;
    while (current != NULL && (current->item->reg->cod_uf - max) <= 0) {
        
        titem * x = current->item;
        tbusca * y;
        if ((*res) == NULL){
            (*res) = (tbusca*)malloc (sizeof(tbusca));
            (*res)->item = x;
            (*res)->prox = NULL;
        }else{

            for (y = *res ; y->prox != NULL; y = y->prox);
            y->prox= (tbusca*)malloc(sizeof(tbusca));
            y->prox->item = x;
            y->prox->prox = NULL;
        }
        
        current = sucessor(&current);
        
    }

}

void avl_RQ_longi(tnode **nodo, float min, float max, tbusca **res) {
    if (nodo == NULL) {
        return;
    }

    tnode *current = percorre_esq(&(*nodo));
    
    while (current != NULL && (current->item->reg->longitude - min) < 0) {
        current = sucessor(&current);
    }
    
    while (current != NULL && (current->item->reg->longitude - max) <= 0) {
        
        titem * x = current->item;
        tbusca * y;
        if ((*res) == NULL){
            (*res) = (tbusca*)malloc (sizeof(tbusca));
            (*res)->item = x;
            (*res)->prox = NULL;
        }else{

            for (y = *res ; y->prox != NULL; y = y->prox);
            y->prox= (tbusca*)malloc(sizeof(tbusca));
            y->prox->item = x;
            y->prox->prox = NULL;
        }
        
        current = sucessor(&current);
        
    }

}

void avl_RQ_lati(tnode **nodo, float min, float max, tbusca **res) {
    if (nodo == NULL) {
        return;
    }

    tnode *current = percorre_esq(&(*nodo));
    
    while (current != NULL && (current->item->reg->latitude - min) < 0) {
        current = sucessor(&current);
    }
    
    while (current != NULL && (current->item->reg->latitude - max) <= 0) {
        
        titem * x = current->item;
        tbusca * y;
        if ((*res) == NULL){
            (*res) = (tbusca*)malloc (sizeof(tbusca));
            (*res)->item = x;
            (*res)->prox = NULL;
        }else{

            for (y = *res ; y->prox != NULL; y = y->prox);
            y->prox= (tbusca*)malloc(sizeof(tbusca));
            y->prox->item = x;
            y->prox->prox = NULL;
        }
        
        current = sucessor(&current);
        
    }

}