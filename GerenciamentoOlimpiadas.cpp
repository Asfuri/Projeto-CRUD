#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "GerenciamentoOlimpiadas.h"

void GerenciamentoOlimpiadas::AdicionarPessoa(Pessoa p) {
}

void GerenciamentoOlimpiadas::gerarRelatorio() {
}

void GerenciamentoOlimpiadas::exibirTodos() {
    int count = 0;
    for(Pessoa p : gerenciamento){
      count++;
      std::cout << "-> " << count << "ª Pessoa:\n ";
      p.exibir();
    }
}

void GerenciamentoOlimpiadas::menu() {
  std::cout << "1. Inserir pessoa" << std::endl;
  std::cout << "2. Listar pessoas" << std::endl;
  std::cout << "3. Exibir pessoa" << std::endl;
  std::cout << "4. Alterar pessoa" << std::endl;
  std::cout << "5. Remover pessoa" << std::endl;
  std::cout << "6. Exibir Relatorio" << std::endl;
  std::cout << "7. Sair" << "\n\n-> ";

  int opcao;
  std::cin >> opcao;
  switch (opcao) {
  case 1: {
    // Falta perguntar o tipo da pessoa (subclasse)

    std::string nome, codigo, nacionalidade;
    int dia, mes, ano, idade;

    std::cin.ignore();
    std::cout << "Digite o nome da pessoa a ser adicionada" << "\n ->";
    std::getline(std::cin, nome);

    std::cout << "Digite o dia do nascimento de " << nome << "\n ->";
    std::cin >> dia;
    std::cout << "Digite o mes do nascimento de " << nome << "\n ->";
    std::cin >> mes;
    std::cout << "Digite o ano do nascimento de " << nome << "\n ->";
    std::cin >> ano;
    Data dataNasc(dia, mes, ano);

    std::cout << "Digite o codigo de " << nome << "\n ->";
    std::cin >> codigo;

    std::cin.ignore();
    std::cout << "Digite a nacionalidade de " << nome << "\n ->";
    std::getline(std::cin, nacionalidade);

    std::cout << "Digite a idade de " << nome << "\n ->";
    std::cin >> idade;

    Pessoa Pessoa(dataNasc, nome, codigo, nacionalidade, idade);
    AdicionarPessoa(Pessoa);
  };
  case 2: {
    exibirTodos();
    // listar
  };
  case 3: {
    // exibir
  };
  case 4: {
    // alterar
  };
  case 5: {
    // remover
  };
  case 6: {
    // exibir relatorio
  };
  case 7: {
    // sair
  };
  }
};

Pessoa GerenciamentoOlimpiadas::buscar() {
}
