#ifndef TREE_H
#define TREE_H

typedef struct no {
  int value;
  struct no* esq;
  struct no* dir;
} No;

void showTree(No *raiz);
void isFull(No *raiz);
void searchValue(No *raiz,int value);
int getHeight(No *raiz);
No *removeValue(No *raiz,int value);
void printInOrder(No *raiz);
void printPreOrder(No *raiz);
void printPostOrder(No *raiz);
No *balanceTree(No *raiz);

#endif
