//filas (de usuários que deram cada lance, por produto)
#include "bloco.h"

typedef struct{
    Bloco *prox;
}fila_bloco;

typedef struct{
    fila_bloco *ini,*fim; 
    int total;
}fila;

fila create();
int isempty(fila *f);
int inserir(fila *f, void *dado, unsigned long tamanho);
int remover(fila *f, Bloco *x);
int empty(fila *f);
