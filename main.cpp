#include <iostream>
#include <unistd.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <locale>

#include "./headers/GerenciamentoOlimpiadas.h"
/*
  Importa��o da principal classe do sistema, que inclui a maior parte das funcionalidades da biblioteca padr�o
  diretamente ou indiretamente. Possui a composi��o de ponteiros da superclasse Pessoa, ou seja, composi��o das suas subclasses (Atleta, Comiss�o e Torcedor). Inclui diretamente essas classes, assim como a classe Data.
*/

int main() {
#ifdef _WIN32
  std::setlocale(LC_ALL, "Portuguese_Brazil.1252");
  SetConsoleOutputCP(1252);
  SetConsoleCP(1252);
#else
  std::setlocale(LC_ALL, "pt_BR.UTF-8");
#endif
  /*
    Adicionando formata��o no portugu�s brasileiro, facilitando o uso de acentos outros caracteres
  */
  GerenciamentoOlimpiadas Olimpiada;
  /*
    �nica inst�ncia de olimp�ada durante toda a execu��o, sendo esse objeto o respons�vel por todo o sistema
  */
  // READ geral
  Olimpiada.iniciarOlimpiada();

  while (1) {
    int error = Olimpiada.menu();
    // Abrir o menu principal do gerenciamento
    Olimpiada.salvarArquivo();
    // Salvando o arquivo periodicamente para evitar a perda de dados
    if (error == 1)
      break;
  }
  /*
    O C�digo abaixo s� acontece no devido encerramento do programa
  */

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
  std::cout << "Programa encerrado, obrigado! At� a Pr�xima \n";
  sleep(3);
}
