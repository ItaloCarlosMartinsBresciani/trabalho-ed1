#ifndef BLOCO_H
#define BLOCO_H

typedef struct
{
  unsigned long tamanho;
  void *dado;
} Bloco;

Bloco *bloco_alocar(void *dado, unsigned long tamanho);
void bloco_liberar(Bloco *bloco);

#endif
