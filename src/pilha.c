#include "pilha.h"
#include "bloco.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pilha_init(Pilha *pilha)
{
  pilha->topo = NULL;
}

void pilha_push(Pilha *pilha, void *dado, unsigned long tamanho)
{
  Bloco *bloco = bloco_alocar(dado, tamanho);

  PilhaBloco *pilha_bloco = malloc(sizeof(PilhaBloco));
  pilha_bloco->bloco = bloco;

  memcpy(bloco->dado, dado, tamanho);

  if (pilha->topo != NULL)
  {
    pilha_bloco->anterior = pilha->topo;
  }
  else
  {
    pilha_bloco->anterior = NULL;
  }
  pilha->topo = pilha_bloco;
}

Bloco *pilha_pop(Pilha *pilha)
{
  if (pilha->topo == NULL)
  {
    return NULL;
  }

  Bloco *bloco = pilha->topo->bloco;
  PilhaBloco *anterior = pilha->topo;
  pilha->topo = pilha->topo->anterior;
  free(anterior);
  return bloco;
}
