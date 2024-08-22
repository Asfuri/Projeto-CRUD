#include "GerenciamentoOlimpiadas.h"
#include <iostream>
#include <fstream>

int main() {
  
  GerenciamentoOlimpiadas Olimpiada;
  // READ geral
  Olimpiada.iniciarOlimpiada();
  
  while (1) {
    int error = Olimpiada.menu();
    if (error == 1)
      break;
  }   
  // Salvar aquivos antes de sair
  Olimpiada.salvarArquivo(); 
  std::cout << "\n\nAte a proxima!";
}