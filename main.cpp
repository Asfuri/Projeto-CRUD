#include "GerenciamentoOlimpiadas.h"
#include <iostream>

int main() {
  GerenciamentoOlimpiadas Olimpiada;
  int opcao = 1;
  while (!(opcao == 7) || !(opcao < 1) || !(opcao > 7)) {
    Olimpiada.menu();
    if (!(opcao == 7) || !(opcao < 1) || !(opcao > 7))
      return -1;
  }
}