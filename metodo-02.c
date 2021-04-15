#include <assert.h>
#include <stdio.h>
#include "lista.h"

int main() {
  Lista estoque;

  new_lista(&estoque);

  for(int i = 0; i < 5; i++) {
    Produto p;
    sprintf(p.descricao, "PRODDESC: %d", i + 1);
    p.quantidade = rand()%100;
    p.valor = rand()%100;
    p.codigo = i + 1;

    add_inicio_lista(&estoque, p);
  }

  print_lista(&estoque);
}