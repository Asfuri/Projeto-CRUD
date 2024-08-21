#include "GerenciamentoOlimpiadas.h"
#include <iostream>
#include <fstream>

int main() {
  
  std::fstream arqOlimpiada;
  GerenciamentoOlimpiadas *Olimpiada;
  arqOlimpiada.open("olimpiada.txt", std::ios_base::in);
  
  if(arqOlimpiada.is_open()) {
    int _dia, _mes, _ano;
    std::string Cidade, mascote;

    arqOlimpiada >> _dia, _mes, _ano;
    Data DatadeInicio(_dia, _mes, _ano);
    arqOlimpiada.ignore();

    getline(arqOlimpiada, Cidade);
    arqOlimpiada >> _dia, _mes, _ano;

    Data DataFinal(_dia, _mes, _ano);
    arqOlimpiada.ignore();
    
    getline(arqOlimpiada, mascote);

    Olimpiada = new GerenciamentoOlimpiadas(DatadeInicio, Cidade, DataFinal, mascote);
    arqOlimpiada.close();

  } else {
    arqOlimpiada.close();
    int _dia, _mes, _ano;

    std::string Cidade, mascote;
    std::cout << "Digite a cidade sede " << std::endl;
    std::cout << "\n-> ";
    
    getline(std::cin, Cidade);
    std::cout << "Digite o ano das Olimpí­adas de " << Cidade << std::endl;
    std::cout << "\n-> ";
    std::cin >> _ano;
    std::cout << "Digite o mes de " << _ano << " que começam as Olimpí­adas de " << Cidade << std::endl;
    std::cout << "\n-> ";
    std::cin >> _mes;
    std::cout << "Digite dia do mes de " << _mes << "/" << _ano << " que começam as Olimpí­adas de " << Cidade << std::endl;
    std::cin >> _dia;
    Data DatadeInicio(_dia, _mes, _ano);
    
    std::cout << "Digite o ano que acaba as Olimpí­adas de " << Cidade << std::endl;
    std::cout << "\n-> ";
    std::cin >> _ano;
    std::cout << "Digite o mes de " << _ano << " que acabam as Olimpí­adas de " << Cidade << std::endl;
    std::cout << "\n-> ";
    std::cin >> _mes;
    std::cout << "Digite dia do mes de " << _mes << "/" << _ano << " que acabam as Olimpí­adas de " << Cidade << std::endl;
    std::cin >> _dia;
    Data DataFinal(_dia, _mes, _ano);

    std::cin.ignore();
    getline(std::cin, mascote);

    Olimpiada = new GerenciamentoOlimpiadas(DatadeInicio, Cidade, DataFinal, mascote);
    
    // Comeca a escrever no arquivo as informacoes sobre a olimpiada
    // O usuario so consegue "criar" outra olimpiada se apagar o arquivo olimpiada.txt
    // Isso deve ser documentado no README
    arqOlimpiada.open("olimpiada.txt", std::ios_base::out);

    // Salvando a data inicial
    arqOlimpiada << DatadeInicio.getDia() << std::endl;
    arqOlimpiada << DatadeInicio.getMes() << std::endl;
    arqOlimpiada << DatadeInicio.getAno() << std::endl;

    // Salvando a cidade
    arqOlimpiada << Cidade << std::endl;

    // Salvando a data final
    arqOlimpiada << DataFinal.getDia() << std::endl;
    arqOlimpiada << DataFinal.getMes() << std::endl;
    arqOlimpiada << DataFinal.getAno() << std::endl;

    // Salvando mascote
    arqOlimpiada << mascote << std::endl;

    arqOlimpiada.close();

  }

  // READ 
  Olimpiada->lerArquivo();
  while (1) {
    int error = Olimpiada->menu();
    if (error == 1)
      break;
  }   
  // Salvar aquivos antes de sair
  Olimpiada->salvarArquivo(); 
  std::cout << "\n\nAte a pr�xima!";
}