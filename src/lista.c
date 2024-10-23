#include "lista.h"
#include "bloco.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void lista_init(Lista *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
}

bool lista_vazia(Lista *lista)
{
    if (lista->inicio == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ListaBloco *lista_pop(Lista *lista)
{
    if (lista_vazia(lista) == true)
    {
        return NULL;
    }
    else
    {
        ListaBloco *aux = lista->inicio;
        if (lista->inicio == lista->fim)
        {
            lista->inicio = NULL;
            lista->fim = NULL;
        }
        else
        {
            lista->inicio = lista->inicio->proximo;
            lista->inicio->anterior = NULL;
        }
        return aux;
        aux->pilha=NULL;
    }
}

void lista_print(Lista *lista)
{
    assert(lista != NULL);
    ListaBloco *aux = lista->inicio;
    while (aux != NULL)
    {

        printf("%s\n", aux->bloco->dado);
        printf("%s\n", aux->pilha->bloco->dado);
        aux = aux->proximo;
    }
}

void lista_print_inv(Lista *lista)
{
    assert(lista != NULL);
    ListaBloco *aux = lista->fim;
    while (aux != NULL)
    {
        printf("%s\n", aux->bloco->dado);
        printf("%s\n", aux->pilha->bloco->dado);
        aux = aux->anterior;
    }
}

void lista_push(Lista *lista, void *dado, unsigned long tamanho)
{
    Bloco *B = bloco_alocar(dado, tamanho);
    assert(B != NULL);

    ListaBloco *Lista_bloco = (ListaBloco *)malloc(sizeof(ListaBloco));
    assert(Lista_bloco != NULL);
    
    Pilha *P; //criamos uma pilha de lances ligado a cada produto (listabloco)
    pilha_init(P);

    Lista_bloco->pilha= P;
    Lista_bloco->bloco = B;

    ListaBloco *aux, *ant;
    aux = lista->inicio;
    ant = NULL;

    while (aux != NULL && strcmp(dado, aux->bloco->dado) > 0)
    {
        ant = aux;
        aux = aux->proximo;
    }
    if (aux != NULL && strcmp(dado, aux->bloco->dado) == 0)
    {
        free(B);
        free(Lista_bloco);
        return;
    }
    if (ant == NULL)
    {
        Lista_bloco->proximo = lista->inicio;
        if (lista->inicio != NULL) lista->inicio->anterior = Lista_bloco;
        lista->inicio = Lista_bloco;
    }else{
        Lista_bloco->proximo = ant->proximo;
        ant->proximo = Lista_bloco;
        if (Lista_bloco->proximo != NULL ) Lista_bloco->proximo->anterior = Lista_bloco;
        else lista->fim = Lista_bloco;
        Lista_bloco->anterior = ant;
    }
}