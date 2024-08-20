#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "GerenciamentoOlimpiadas.h"

void GerenciamentoOlimpiadas::lerArquivo() {
  std::fstream arquivo;
  arquivo.open("Olimpiadas.txt", std::ios_base::in); 
  if (!arquivo.is_open()) std::cout << "Erro na abertura do arquivo para leitura!" << std::endl;

  while(!arquivo.eof()) {
    // Ler pessoa por pessoa do arquivo
    // Alocando ao vector de pessoas da superclasse
    Pessoa *pessoaAux;
    int tipoPessoa, _dia, _mes, _ano, _idade;
    std::string pessoaNome, pessoaCodigo, pessoaNac;
    arquivo >> tipoPessoa >> _dia >> _mes >> _ano;
    Data dataAux = Data(_dia, _mes, _ano);
    arquivo.ignore();
    getline(arquivo, pessoaNome);
    getline(arquivo, pessoaCodigo);
    getline(arquivo, pessoaNac);
    arquivo >> _idade;
    if(tipoPessoa == 1) {

      int auxMedalha;
      std::string auxMod;
      arquivo >> auxMedalha;
      arquivo.ignore();
      getline(arquivo, auxMod);
      pessoaAux = new Atleta(dataAux, pessoaNome, pessoaCodigo, pessoaNac, _idade, auxMedalha, auxMod);
      // Instanciando um atleta a partir dos dados do arquivo em PessoaAux
    } else if(tipoPessoa == 2) {
      
      std::string auxMod, auxEquipResp;
      arquivo.ignore();
      getline(arquivo, auxMod);
      getline(arquivo, auxEquipResp);
      pessoaAux = new Comissao(dataAux, pessoaNome, pessoaCodigo, pessoaNac, _idade, auxMod, auxEquipResp);
      // Instanciando um tecnico da comissao a partir dos dados do arquivo em PessoaAux
    } else if(tipoPessoa == 3) {
      arquivo.ignore();
      int bitStatusVip;
      arquivo >> bitStatusVip;
      bool auxStatusVip = (bitStatusVip == 1) ? true : false;
      // Instanciando um torcedor a partir dos dados do arquivo em PessoaAux
    }


    // Alocando pessoa auxiliar no vector 
    AdicionarPessoa(*pessoaAux);
  };

  arquivo.close();
};

void GerenciamentoOlimpiadas::salvarArquivo() {
  std::fstream arquivo;
  arquivo.open("Olimpiadas.txt", std::ios_base::out);

  if (!arquivo.is_open()) std::cout << "Erro na abertura do arquivo para escrita!" << std::endl;
  
  for (auto pessoa: gerenciamento) {
    int tipoPessoa, _dia, _mes, _ano, _idade;
    std::string pessoaNome, pessoaCodigo, pessoaNac;
    arquivo << _dia << _mes << _ano;
    Data dataAux = Data(_dia, _mes, _ano);
    arquivo.ignore();
    arquivo << pessoaNome << std::endl;
    arquivo << pessoaCodigo << std:: endl;
    arquivo << pessoaNac << std::endl;
    arquivo << _idade << std::endl;
  }
}

void GerenciamentoOlimpiadas::AdicionarPessoa(Pessoa p) { // Create
  gerenciamento.push_back(p);
}


void GerenciamentoOlimpiadas::gerarRelatorio() {
}

void GerenciamentoOlimpiadas::exibirTodos() {
    int count = 0;
    for(Pessoa p : gerenciamento){
      count++;
      std::cout << "-> " << count << "a Pessoa:\n ";
      p.exibir();
    }
}

int GerenciamentoOlimpiadas::menu() {
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
      return 0;
    }
  };
  case 2: {
    exibirTodos();
    // listar
  };
  case 3: {
    // Pessoa *p = &buscar();
    // (*p).exibir();
    Pessoa p = buscar();
    p.exibir();
    // exibir
  };
  case 4: {
    // Pessoa *p = &buscar();
    Pessoa p = buscar();
    int indice = 0;
    for(Pessoa busca : gerenciamento) {
      if(busca.getCodigo() == p.getCodigo());
        break;
      indice++;
    }
    if(indice > gerenciamento.size())
      return;

    int escolha;

    std::cout << "Digite o que sera alterado" << std::endl;
    std::cout << "-> 1 Data de Nascimento" << std::endl;
    std::cout << "-> 2 Nome" << std::endl;
    std::cout << "-> 3 Codigo" << std::endl;
    std::cout << "-> 4 Nacionalidade" << std::endl;
    std::cout << "-> 5 idade" << std::endl;
    std::cout << "\n -> ";

    std::cin >> escolha;

    //faltando acabar
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
    return 1;
    // sair
  };
  }
  return 0;
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
  if(indice > gerenciamento.size())
    return;
  indice--;
  return gerenciamento[indice];
}
