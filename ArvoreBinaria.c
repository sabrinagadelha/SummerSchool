#include <stdio.h>

typedef struct no{
    int dado;
    struct no *esq, *dir;
} no;

typedef no *p_no;

p_no criar_arvore(int x, p_no esq, p_no dir){
    p_no r = malloc(sizeof(no));
    r->dado = x; r->esq = esq; r->dir = dir;
    return r;
}

p_no procurar_no(p_no raiz, int x){
    p_no esq;
    if(raiz->dado == x || raiz == NULL){
        return raiz;
    }
    esq = procurar_no(raiz->esq, x);
    if(esq != NULL){
        return esq;
    }
    return procurar_no(raiz->dir, x);
}

int numero_de_nos(p_no raiz){
    if(raiz == NULL){
        return 0;
    }
    return numero_de_nos(raiz->esq) + numero_de_nos(raiz->dir) + 1;
}

