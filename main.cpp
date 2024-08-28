#include "GerenciamentoOlimpiadas.h"
#include <iostream>
#include <fstream>

int main() {
  
  GerenciamentoOlimpiadas Olimpiada;
  // READ geral
  Olimpiada.iniciarOlimpiada();
  
  while (1) {
    // Abrir o menu principal do gerenciamento
    int error = Olimpiada.menu();
    if (error == 1)
      break;
  }   
  // Salvar aquivos antes de sair
  Olimpiada.salvarArquivo(); 
  std::cout << "\n\nAte a proxima!\n\n";
}

// -> Faltando...

// - Arrumar a estética 
// - Tratar as entradas (opcional)
// - Terminar de organizar o github