//filas (de usuários que deram cada lance, por produto)
#include "bloco.h"

typedef struct FilaBloco
{
    struct FilaBloco *prox; 
    Bloco *bloco;
}FilaBloco;

typedef struct{
    FilaBloco *ini,*fim; 
    int total;
}Fila;

void create(Fila *fila);
int isempty(Fila *f);
void inserir(Fila *f, void *dado, unsigned long tamanho);
Bloco *remover(Fila *f);
int empty(Fila *f);
