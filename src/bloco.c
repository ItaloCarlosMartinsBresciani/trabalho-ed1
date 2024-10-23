#include "bloco.h"
#include "pilha.h"
#include "lista.h"
#include <stdio.h>
#include <locale.h> 
#include <string.h>
#include <stdlib.h>

Bloco *bloco_alocar(void *dado, unsigned long tamanho)
{
  Bloco *bloco = malloc(sizeof(Bloco) + tamanho);
  assert(bloco!=NULL);
  
  bloco->tamanho = tamanho;
  memcpy(bloco->dado, dado, tamanho);
  return bloco;
}

void bloco_liberar(Bloco *bloco)
{
  free(bloco);
}
