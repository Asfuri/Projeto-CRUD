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
    Olimpiada.salvarArquivo();
    if (error == 1)
      break;
  }   
  // Salvar aquivos antes de sair
  Olimpiada.salvarArquivo(); 
  std::cout << "\nSalvando o programa...\n";
  sleep(1);
  std::cout << "Encerrando! \n";
}

// -> Faltando...

// - Arrumar a estética 
// - Tratar as entradas (opcional)
// - Terminar de organizar o github