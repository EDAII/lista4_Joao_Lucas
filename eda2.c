#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.c"

void liberaArvore(No *raiz);
No *selecionaArquivo();
char menu();
void limpaBuff();
void continuar();

int main()
{
  char select;
  No *raiz;
  int valor;
  No *aux;
  raiz = NULL;
  do
  {
    select = menu();
    switch (select)
    {
      case '1':
        system("clear");
        showTree(raiz);
        break;
      case '2':
        system("clear");
        isFull(raiz);
        break;
      case '3':
        system("clear");
        printf("Digite o valor que deseja procurar na arvore: \n");
        showTree(raiz);
        scanf("%d",&valor);
        getchar();
        searchValue(raiz,valor);
        break;
      case '4':
        system("clear");
        printf("altura da arvore: %d\n",getHeight(raiz));
        break;
      case '5':
        system("clear");
        printf("Digite o valor que deseja remover da arvore: \n");
        showTree(raiz);
        scanf("%d",&valor);
        getchar();
        raiz = removeValue(raiz,valor);
        break;
      case '6':
        do
        {
          system("clear");
          printf("Escolha o algoritmo que deseja utlizar: \n\n");
          printf("1 - InOrder: \n");
          printf("2 - PreOrder: \n");
          printf("3 - PostOrder: \n");
          scanf("%c",&select );
          limpaBuff();
        } while(select < '1' || select > '3');
        switch (select)
        {
          case '1':
            system("clear");
            printInOrder(raiz);
            break;
          case '2':
            system("clear");
            printPreOrder(raiz);
            break;
          case '3':
            system("clear");
            printPostOrder(raiz);
            break;
        }
        break;
      case '7':
        system("clear");
        raiz = balanceTree(raiz);
        showTree(raiz);
        break;
      case '8':
        system("clear");
        printf("Digite o valor que deseja inserir na arvore: \n");
        scanf("%d",&valor);
        getchar();
        if(aux = (No*)malloc(sizeof(No)),aux == NULL)
        {
          printf("alocação falhou!\n");
        }
        aux->value = valor;
        aux->dir = NULL;
        aux->esq = NULL;
        if (getHeight(raiz) != 0) {
          insereNo(raiz,aux);
        }
        else{
          raiz = aux;
        }
        system("clear");
        showTree(raiz);
        break;
      case '0':
        liberaArvore(raiz);
    }
    if (select != '0')
    {
      continuar();
    }
  } while(select != '0');
  return 0;
}

////////////////////////////////////////////////////////////////////////////////
char menu()
{
  char select;
  do
  {
    system("clear");
    printf("\n");
    printf("\t1 - Mostrar arvore\n\n");
    printf("\t2 - Verificar se a arvore é cheia\n\n");
    printf("\t3 - Procurar valor na arvore\n\n");
    printf("\t4 - Verificar altura da arvore\n\n");
    printf("\t5 - Remover valor da arvore\n\n");
    printf("\t6 - Mostrar valores da arvore usando algoritmos\n\n");
    printf("\t7 - Balancear arvore\n\n");
    printf("\t8 - Inserir valor na arvore\n\n");
    printf("\t0 - Sair\n\n");
    scanf("%c",&select);
    limpaBuff();
  } while(select < '0' || select > '8');
  return select;
}
////////////////////////////////////////////////////////////////////////////////
void liberaArvore(No *raiz)
{
  if(raiz != NULL)
  {
    liberaArvore(raiz->esq);
    liberaArvore(raiz->dir);
    free(raiz);
  }
}
////////////////////////////////////////////////////////////////////////////////
void limpaBuff()
{
  char c;
  do
  {
    c = getchar();
  } while(c != '\n');
}
////////////////////////////////////////////////////////////////////////////////
void continuar()
{
  char c;
  printf("\nAperte enter para continuar\n");
  do
  {
    c = getchar();
  } while(c != '\n');
}
