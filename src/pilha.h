#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef struct PilhaBloco
{
  unsigned long tamanho;
  struct PilhaBloco *proximo;
  char dado[];
} PilhaBloco;

typedef struct
{
  PilhaBloco *topo;
  // PilhaBlock *base;
} Pilha;

void pilha_init(Pilha *pilha);
void pilha_push(Pilha *pilha, void *dado, unsigned long tamanho);
PilhaBloco *pilha_pop(Pilha *pilha);
bool pilha_vazia(Pilha *pilha);
void pilha_limpar(Pilha *pilha);

#endif
