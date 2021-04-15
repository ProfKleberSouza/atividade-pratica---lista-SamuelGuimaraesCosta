#ifndef  LISTA_H
#define  LISTA_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Produto {
  int codigo;
  char descricao[100];
  float valor;
  int quantidade;
}Produto;

void print_produto(Produto p) {
  printf("PRODUTO: { Codigo: %d - Desc: %s - Valor: %.2f - Quant: %d }\n", p.codigo, p.descricao, p.valor, p.quantidade);
}

typedef struct Celula {
  Produto dado;
  struct Celula *prox;
}Celula;

Celula *new_celula() {
  Celula *tmp = (Celula*)malloc(sizeof(Celula));
  tmp->prox = NULL;
  return tmp;
}

typedef struct Lista {
  Celula *inicio;
  Celula *fim;
  int tam;
}Lista;

void new_lista(Lista *l) {
  l->inicio = l->fim = new_celula();
  l->tam = 0;
}

void add_inicio_lista(Lista *l, Produto p) {
  l->inicio->dado = p;

  Celula *temp = new_celula();
  temp->prox = l->inicio;
  l->inicio = temp;

  l->tam++;
}

void add_fim_lista(Lista *l, Produto p) {
  Celula *temp = new_celula();
  temp->dado = p;

  l->fim->prox = temp;
  l->fim = temp;

  l->tam++;
}

void print_lista(Lista *l) {
  Celula *temp = l->inicio->prox;

  while(temp != NULL) {
    print_produto(temp->dado);
    temp = temp->prox;
  }
}

#endif