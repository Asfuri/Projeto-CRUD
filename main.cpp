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
  const std::string vermelho = "\033[31m";  // Vermelho
  const std::string laranja = "\033[33m";   // Amarelo (laranja pode ser semelhante)
  const std::string resetar = "\033[0m";    // Resetar cor

  // Desenho da tocha com cores
  std::cout << vermelho
            << "        /|, \n"
            << "       )  (, \n"
            << "      ( (  ) \n"
            << laranja
            << "_______\\__/_______\n"
            << "`--.._      _..--'\n"
            << "      `\\  /'\n"
            << "        ||\n"
            << "        ||\n"
            << "        ||\n"
            << resetar  // Resetar cor
            << std::endl;
  std::cout << "\nSalvando o programa...\n";
  sleep(2);
  std::cout << "Projeto encerrado, obrigado! \n";
}
