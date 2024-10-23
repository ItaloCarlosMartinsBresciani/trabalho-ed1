#include <stdio.h>
#include "fila.h"
#include "bloco.h"

void fila_init(Fila *f){
    f->ini=NULL;
    f->fim=NULL;
    f->total=0;
}

int fila_vazia(Fila *f){
    if (f->total==0)
        return 1;
    return 0;
}
void fila_push(Fila *f, void *dado, unsigned long tamanho) {

    Bloco *novo_bloco = bloco_alocar(dado, tamanho);
    if (novo_bloco == NULL) {
        return 0; 
    }
    if (fila_vazia(f)) {
        f->ini = novo_bloco;
    } else {
        f->fim->prox = novo_bloco;
    }

    f->fim = novo_bloco;
    f->fim->prox = NULL;
    f->total++;
}

Bloco *fila_pop(Fila *f) {

    if (!isempty(f)) {
        Bloco *p;
        p=f->ini->prox;
        x = f->ini;  
        f->ini=p;  
        f->total--;
        bloco_liberar(x);
        
        return 1;  
    }
    return 0;  
}
int empty(Fila *f) { 
    if (!isempty(f)) {
        while (!isempty(f)) {
            Bloco *bloco;
            remover(f, bloco);  
        }
        f->ini = NULL;
        f->fim = NULL;
        f->total = 0;
        return 1;  
    }
    return 0;  
}
