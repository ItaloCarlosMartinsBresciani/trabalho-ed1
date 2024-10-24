#include "bloco.h"
#include "pilha.h"
#include "lista.h"
#include <stdio.h>
#include <locale.h> 
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Bloco *bloco_alocar(void *dado, unsigned long tamanho)
{
    Bloco *bloco = malloc(sizeof(Bloco));
    assert(bloco != NULL);
    
    bloco->tamanho = tamanho;
    bloco->dado = malloc(tamanho); // Aloca memória para o dado
    assert(bloco->dado != NULL);
    
    memcpy(bloco->dado, dado, tamanho);
    return bloco;
}

void bloco_liberar(Bloco *bloco)
{
    free(bloco->dado); // Libera o dado primeiro
    free(bloco); // Depois libera o bloco
}

