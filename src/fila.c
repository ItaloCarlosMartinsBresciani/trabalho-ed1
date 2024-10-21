#include <stdio.h>
#include "fila.h"
#include "bloco.h"

fila create(){
    fila f;
    f.ini=NULL;
    f.fim=NULL;
    f.total=0;
    return f;
}

int isempty(fila *f){
    if (f->total==0)
        return 1;
    return 0;
}
int inserir(fila *f, void *dado, unsigned long tamanho) {

    Bloco *novo_bloco = bloco_alocar(dado, tamanho);
    if (novo_bloco == NULL) {
        return 0; 
    }
    if (isempty(f)) f->ini = novo_bloco;     
    else f->fim->prox=novo_bloco;

    f->fim=novo_bloco;
    f->fim->prox=NULL;
    f->total++;
    return 1;  
}
int remover(fila *f, Bloco *x) {

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
int empty(fila *f) { 
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
