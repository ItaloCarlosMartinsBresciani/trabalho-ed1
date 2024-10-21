#include "bloco.h"
#include "pilha.h"
#include <stdio.h>
#include <locale.h> 

/* Protótipos das funções
void cadastra(/*lista de produtos, nome do produto);
void lista_produtos(/*lista de produtos...(?));
void dar_lance(/*lista de produtos...(?));
void avisa_usuario(/*lista de produtos...(?));
void encerra(/*lista de produtos...(?)); */ 

int main()
{
  setlocale(LC_ALL, "");
  // Menu inicial
  printf("Caro usuário, suas opções são:\n\t1)  cadastrar um produto\n\t2)  listar produtos e lances\n\t3)  dar um lance\n\t4)  listar outros produtos para lances\n\t5)  encerrar leilão\n\n");
  
  int comando;
  

  int cont_cadastros = 0;
  // Menu
  do{
    printf("O que deseja fazer? ");
    scanf("%d", &comando);
    switch (comando)
    {
    case 1: // cadastra um produto
      printf("Resposta: 1\n");
      if(cont_cadastros == 0){
        // *inicializa a lista
      }
      //cadastra();
      printf("\n");
      break;

    case 2: // lista todos os produtos e os lances de cada um 
      printf("Resposta: 2\n");
      if(1==1/*lista de produtos vazia*/)
      {
        printf("Não há produtos cadastrados\n");
      }else{
        //lista_produtos();
        printf("Listagem completa\n");
      }
      printf("\n");
      break;

    case 3: // dá um lance em um produto
      printf("Resposta: 3\n");
      //dar_lance();
      printf("\n");
      break;

    case 4: // avisa usuários os quais tiveram lances ultrapassados sobre quais outros produtos estão disponíveis para lance
      printf("Resposta: 4\n");
      //avisa_usuario();
      printf("\n");
      break;

    case 5: // encerra leilão: lista os usuários e o lance ganhador para cada produto, além de reinicializar o sistema
      printf("Resposta: 5\n");
      //encerra();
      printf("\n");
      break;

      default: 
      printf("Comando inválido\n");
      break;
    }
  }while(comando!=5);

  return 0;
}
