#ifndef PILHA_H
#define PILHA_H

#include "bloco.h"
#include <stdbool.h>

typedef struct PilhaBloco
{
  struct PilhaBloco *anterior;
  Bloco *bloco;
} PilhaBloco;

typedef struct
{
  PilhaBloco *topo;
} Pilha;

void pilha_init(Pilha *pilha);
void pilha_push(Pilha *pilha, void *dado, unsigned long tamanho);
PilhaBloco *pilha_pop(Pilha *pilha);
bool pilha_vazia(Pilha *pilha);
void pilha_limpar(Pilha *pilha);

#endif
