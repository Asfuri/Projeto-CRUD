#include "./headers/GerenciamentoOlimpiadas.h"
#include <fstream>
#include <iostream>
#include <unistd.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <locale>

int main() {
// Adicionando formata��o no portugu�s brasileiro, facilitando o uso de acentos outros caracteres
#ifdef _WIN32
  std::setlocale(LC_ALL, "Portuguese_Brazil.1252");
  SetConsoleOutputCP(1252);
  SetConsoleCP(1252);
#else
  std::setlocale(LC_ALL, "pt_BR.UTF-8");
#endif
  // �nica inst�ncia de olimp�ada durante toda a execu��o
  GerenciamentoOlimpiadas Olimpiada;
  // READ geral
  Olimpiada.iniciarOlimpiada();

  while (1) {
    // Abrir o menu principal do gerenciamento
    int error = Olimpiada.menu();
    // Salvando o arquivo periodicamente para evitar a perda de dados
    Olimpiada.salvarArquivo();
    if (error == 1)
      break;
  }
  const std::string vermelho = "\033[31m"; // Vermelho
  const std::string laranja = "\033[33m";  // Amarelo (laranja pode ser semelhante)
  const std::string resetar = "\033[0m";   // Resetar cor

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
            << resetar // Resetar cor
            << std::endl;
  std::cout << "\nSalvando o programa...\n";
  sleep(1);
  std::cout << "Projeto encerrado, obrigado! \n";
}
