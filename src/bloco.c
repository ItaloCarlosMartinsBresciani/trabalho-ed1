#include "bloco.h"
#include <stdlib.h>
#include <string.h>
Bloco *bloco_alocar(void *dado, unsigned long tamanho)
{
  Bloco *bloco = malloc(sizeof(Bloco) + tamanho);
  bloco->tamanho = tamanho;
  memcpy(bloco->dado, dado, tamanho);
  return bloco;
}

void bloco_liberar(Bloco *bloco)
{
  free(bloco);
}
