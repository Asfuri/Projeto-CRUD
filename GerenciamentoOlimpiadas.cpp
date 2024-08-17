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
    std::string nome, codigo, nacionalidade;
    int dia, mes, ano, idade, tipoPessoa;

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

    std::cout << "Digite o tipo" << std::endl;
    std::cout << "-> 1 Atleta\t-> 2 Tecnico da comissao\n-> 3 Torcedor\t-> 4 Cancelar operacao\n-> ";
    std::cin >> tipoPessoa;

    if(tipoPessoa == 1) {

      std::cin.ignore();
      int medalha;
      std::string modalidade;
      std::cout << "Digite a modalidade do atleta\n ->";
      std::getline(std::cin, modalidade);
      std::cout << "Digite a colocacao de " << nome << " em " << modalidade << "\n ->";
      std::cin >> medalha;

      Atleta Atleta(dataNasc, nome, codigo, nacionalidade, idade, medalha, modalidade);
      AdicionarPessoa(Atleta);

    } else if(tipoPessoa == 2) {
    
      std::cin.ignore();
      std::string modalidade, equipeResponsavel;
      std::cout << "Digite a modalidade de atuacao do tecnico\n ->";
      std::getline(std::cin, modalidade);
      std::cout << "Dentro de " << modalidade << ", digite a equipe de atuacao de " << nome << "\n ->";
      std::getline(std::cin, equipeResponsavel);

      Comissao Tecnico(dataNasc, nome, codigo, nacionalidade, idade, modalidade, equipeResponsavel);  
      AdicionarPessoa(Tecnico);

    } else if (tipoPessoa == 3) {

      std::cin.ignore();
      bool vipBool;
      std::string vip;
      std::cout << "O torcedor " << nome << " possui acesso vip? (Sim/Nao)\n ->";
      std::getline(std::cin, vip);

      if((vip.find("s") != -1) || (vip.find("S") != -1) || 
         (vip.find("y") != -1) || (vip.find("y") != -1))
          vipBool = true;
      else 
        vipBool = false;

      Torcedor Torcedor(dataNasc, nome, codigo, nacionalidade, idade, vipBool); 
      AdicionarPessoa(Torcedor);
    } else {
      return;
    }
  };
  case 2: {
    exibirTodos();
    // listar
  };
  case 3: {
    Pessoa p = buscar();
    p.exibir();
    // exibir
  };
  case 4: {
    // alterar
  };
  case 5: {
    // remover
  };
  case 6: {
    // deve mostrar a quantidade de pessoas no geral, e a quantidade de cada subclasse
    // exibir relatorio
  };
  case 7: {
    // sair
  };
  }
};

Pessoa GerenciamentoOlimpiadas::buscar() {
  int count = 0;
  for(Pessoa p : gerenciamento) {
    count++;
    std::cout << "-> " << count << p.getTipo() << ": " << p.getNome() << std::endl;
  }
  std::cout << "\n\nEscolha o indice\n->";
  int indice;
  std::cin >> indice;
  return gerenciamento[indice];
}
