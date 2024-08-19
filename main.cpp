#include "GerenciamentoOlimpiadas.h"
#include <iostream>

int main() {
  GerenciamentoOlimpiadas Olimpiada;
  int opcao = 1;
  while (!(opcao == 7) || !(opcao < 1) || !(opcao > 7)) {
    int error = Olimpiada.menu();
    if (!(opcao == 7) || !(opcao < 1) || !(opcao > 7) || (error = 1))
      break;
  }
  std::cout << "\n\nAte a proxima!";
}