#include "pilha.h"
#include <stdio.h>
#include <string.h>

void pilha_init(Pilha *pilha)
{
  pilha->topo = NULL;
}

void pilha_push(Pilha *pilha, void *dado, unsigned long tamanho)
{
  PilhaBloco *bloco = malloc(sizeof(PilhaBloco) + tamanho);

  bloco->tamanho = tamanho;
  bloco->proximo = NULL;
  memcpy(bloco->dado, dado, tamanho);

  if (pilha->topo != NULL)
  {
    pilha->topo->proximo = bloco;
  }
  pilha->topo = bloco;
}
