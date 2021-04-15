#include <assert.h>
#include <stdio.h>
#include "lista.h"

int main() {
  Lista estoque;

  new_lista(&estoque);

  assert(estoque.tam == 0 && estoque.inicio != NULL && estoque.inicio == estoque.fim);

  Produto entrada;

  entrada.quantidade = 210;
  entrada.codigo = 1;
  strcpy(entrada.descricao, "P1");
  entrada.valor = 999.99;

  add_fim_lista(&estoque, entrada);
}