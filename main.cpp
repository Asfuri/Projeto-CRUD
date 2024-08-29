#include "GerenciamentoOlimpiadas.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

int main() {
  
  GerenciamentoOlimpiadas Olimpiada;
  // READ geral
  Olimpiada.iniciarOlimpiada();
  
  while (1) {
    // Abrir o menu principal do gerenciamento
    int error = Olimpiada.menu();
    // Salvar aquivos antes de sair
    Olimpiada.salvarArquivo();
    if (error == 1)
      break;
  }   

  std::cout << "\nSalvando o programa...\n";
  sleep(1);
  std::cout << "Encerrando! \n";
}
