#ifndef LISTA_H
#define LISTA_H

#include "bloco.h"
#include <stdbool.h>

typedef struct ListaBloco
{
  struct ListaBloco *anterior;
  struct ListaBloco *proximo;
  Bloco *bloco;
} ListaBloco;

typedef struct
{
  ListaBloco *inicio;
  ListaBloco *fim;
} Lista;

void lista_init(Lista *lista);
void lista_push(Lista *lista, void *dado, unsigned long tamanho);
ListaBloco *lista_pop(Lista *lista);
bool lista_vazia(Lista *lista);

#endif