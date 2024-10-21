#include "lista.h"
#include "bloco.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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
    }else
    {
        return false;
    }
}

ListaBloco *lista_pop(Lista *lista){
    if (lista_vazia(lista) == true){
        return NULL;
    }else{
        ListaBloco * aux = lista->inicio;
        if (lista->inicio == lista->fim){
            lista->inicio = NULL;
            lista->fim = NULL;
        }else{
            lista->inicio = lista->inicio->proximo;
            lista->inicio->anterior = NULL;
        }
        return aux;
    }
}

void lista_push(Lista *lista, void *dado, unsigned long tamanho){
    Bloco * B = bloco_alocar(dado, tamanho);
    ListaBloco * Lista_bloco = (ListaBloco*)malloc(sizeof(ListaBloco));
    Lista_bloco->bloco = B;
    if (lista_vazia(lista) == true){
        lista->inicio = Lista_bloco;
        lista->fim = Lista_bloco;
        Lista_bloco->proximo = NULL;
        Lista_bloco->anterior = NULL;
    }else{
        ListaBloco * aux1 = lista->inicio;
        ListaBloco * aux2 = lista->fim;
        int cont=0;
        while (1){
            int cmp = strcmp(aux1->bloco->dado,B->dado);
            if (cont%2==0){
                if (cmp <= 0){
                    if (aux1->anterior == NULL){
                        lista->inicio->anterior = Lista_bloco;
                        Lista_bloco->proximo = lista->inicio;
                        Lista_bloco->anterior = NULL;
                        lista->inicio = Lista_bloco;
                        break;
                    }else{
                        Lista_bloco->anterior = aux1->anterior;
                        aux1->anterior->proximo = Lista_bloco;
                        Lista_bloco->proximo = aux1;
                        aux1->anterior = Lista_bloco;
                        break;
                    }
                }else if (cmp > 0){
                    cont++;
                    aux1 = aux1->proximo;
                }
            }else{
                if (cmp <= 0){
                    if (aux2->proximo == NULL){
                        lista->fim->proximo = Lista_bloco;
                        Lista_bloco->anterior = lista->fim;
                        Lista_bloco->proximo = NULL;
                        lista->fim = Lista_bloco;
                        break;
                    }else{
                        Lista_bloco->proximo = aux2->proximo;
                        aux2->proximo->anterior = Lista_bloco;
                        Lista_bloco->anterior = aux2;
                        aux2->proximo = Lista_bloco;
                        break;
                    }
                }else if (cmp > 0){
                    cont++;
                    aux2 = aux2->anterior;
                }
            }
        }   
    }
}