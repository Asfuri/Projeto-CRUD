#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "GerenciamentoOlimpiadas.h"

GerenciamentoOlimpiadas::GerenciamentoOlimpiadas() {

  this->DatadeInicio = Data();
  this->Cidade = "";
  this->DataFinal = Data();
  this->mascote = "";
  this->posicao = 0;
}

void GerenciamentoOlimpiadas::setOlimpiada(Data DatadeInicio, std::string Cidade, Data DataFinal, std::string mascote) {
  this->DatadeInicio = DatadeInicio;
  this->Cidade = Cidade;
  this->DataFinal = DataFinal;
  this->mascote = mascote;
  this->posicao = 0;
}

void GerenciamentoOlimpiadas::iniciarOlimpiada() {

  lerArquivoOlimpiadas();
  // Read Pessoas
  lerArquivoPessoas();
}

void GerenciamentoOlimpiadas::lerArquivoOlimpiadas() {
  std::fstream arqOlimpiada;
  arqOlimpiada.open("dadosOlimpiadas.txt", std::ios_base::in);

  if (arqOlimpiada.is_open()) {
    int diaAux, mesAux, anoAux;
    std::string Cidade, mascote;

    arqOlimpiada >> diaAux >> mesAux >> anoAux;
    Data dataInicioAux(diaAux, mesAux, anoAux);
    arqOlimpiada.ignore();

    getline(arqOlimpiada, Cidade);
    arqOlimpiada >> diaAux >> mesAux >> anoAux;

    Data dataFinalAux(diaAux, mesAux, anoAux);
    arqOlimpiada.ignore();

    getline(arqOlimpiada, mascote);

    setOlimpiada(dataInicioAux, Cidade, dataFinalAux, mascote);
    arqOlimpiada.close();

  } else {
    arqOlimpiada.close();
    int diaAux, mesAux, anoAux, anoFinal;

    std::string Cidade, mascote;
    std::cout << "Digite a cidade sede " << std::endl;
    std::cout << "\n-> ";

    getline(std::cin, Cidade);
    std::cout << "Digite o ano das olimpiadas de " << Cidade << std::endl;
    std::cout << "\n-> ";
    std::cin >> anoAux;
    std::cout << "Digite o mes de " << anoAux << " que comecam as olimpiadas de " << Cidade << std::endl;
    std::cout << "\n-> ";
    std::cin >> mesAux;
    std::cout << "Digite dia do mes de " << mesAux << "/" << anoAux << " que comecam as olimpiadas de " << Cidade << std::endl;
    std::cout << "\n-> ";
    std::cin >> diaAux;
    Data dataInicioAux(diaAux, mesAux, anoAux);

    std::cout << "Digite o ano que acabam as olimpiadas de " << Cidade << std::endl;
    std::cout << "\n-> ";
    std::cin >> anoFinal;
    std::cout << "Digite o mes de " << anoAux << " que acabam as olimpiadas de " << Cidade << std::endl;
    std::cout << "\n-> ";
    std::cin >> mesAux;
    std::cout << "Digite dia do mes de " << mesAux << "/" << anoAux << " que acabam as olimpiadas de " << Cidade << std::endl;
    std::cout << "\n-> ";
    std::cin >> diaAux;
    Data dataFinalAux(diaAux, mesAux, anoFinal);

    std::cout << "Digite o nome do mascote das olimpiadas de " << Cidade << " " << anoAux << std::endl;
    std::cout << "\n-> ";
    std::cin.ignore();
    getline(std::cin, mascote);

    setOlimpiada(dataInicioAux, Cidade, dataFinalAux, mascote);

    // Comeca a escrever no arquivo as informacoes sobre a olimpiada
    // O usuario so consegue "criar" outra olimpiada se apagar o arquivo olimpiada.txt
    // Isso deve ser documentado no README
    arqOlimpiada.open("dadosOlimpiadas.txt", std::ios_base::out);

    // Salvando a data inicial
    arqOlimpiada << dataInicioAux.getDia() << std::endl;
    arqOlimpiada << dataInicioAux.getMes() << std::endl;
    arqOlimpiada << dataInicioAux.getAno() << std::endl;

    // Salvando a cidade
    arqOlimpiada << Cidade << std::endl;

    // Salvando a data final
    arqOlimpiada << dataFinalAux.getDia() << std::endl;
    arqOlimpiada << dataFinalAux.getMes() << std::endl;
    arqOlimpiada << dataFinalAux.getAno() << std::endl;

    // Salvando mascote
    arqOlimpiada << mascote << std::endl;

    arqOlimpiada.close();
  }
};

void GerenciamentoOlimpiadas::lerArquivoPessoas() {
  std::fstream arquivo;
  arquivo.open("dadosPessoas.txt", std::ios_base::in);
  if (!arquivo.is_open())
    return;

  while (!arquivo.eof()) {
    // Ler pessoa por pessoa do arquivo
    // Alocando ao vector de pessoas da superclasse
    Pessoa *pessoaAux;
    int tipoPessoa, diaAux, mesAux, anoAux, idadeAux;
    std::string pessoaNome, pessoaCodigo, pessoaNac;
    arquivo >> tipoPessoa >> diaAux >> mesAux >> anoAux;

    Data dataAux = Data(diaAux, mesAux, anoAux);
    arquivo.ignore();
    std::getline(arquivo, pessoaNome);
    std::getline(arquivo, pessoaCodigo);
    std::getline(arquivo, pessoaNac);
    arquivo >> idadeAux;

    if (tipoPessoa == 1) {

      int auxMedalha;
      std::string auxMod;
      arquivo >> auxMedalha;
      arquivo.ignore();
      std::getline(arquivo, auxMod);
      pessoaAux = new Atleta(dataAux, pessoaNome, pessoaCodigo, pessoaNac, idadeAux, auxMedalha, auxMod);
      // Instanciando um atleta a partir dos dados do arquivo em PessoaAux
    } else if (tipoPessoa == 2) {

      std::string auxMod, auxEquipResp;
      arquivo.ignore();
      std::getline(arquivo, auxMod);
      std::getline(arquivo, auxEquipResp);
      pessoaAux = new Comissao(dataAux, pessoaNome, pessoaCodigo, pessoaNac, idadeAux, auxMod, auxEquipResp);

      // Instanciando um membro da comissao a partir dos dados do arquivo em PessoaAux
    } else if (tipoPessoa == 3) {

      arquivo.ignore();
      int bitStatusVip;
      arquivo >> bitStatusVip;
      bool auxStatusVip = (bitStatusVip == 1) ? true : false;
      // Instanciando um torcedor a partir dos dados do arquivo em PessoaAux
    }

    // Alocando pessoa auxiliar no vector
    AdicionarPessoa(pessoaAux);
  };

  arquivo.close();
};

void GerenciamentoOlimpiadas::salvarArquivo() {
  // FALTA ATUALIZAR ESSE METODO, FALTA IMPRIMIR O TIPO E OS ATRIBUTOS DO TIPO
  std::fstream arquivo;
  arquivo.open("dadosPessoas.txt", std::ios_base::out);

  if (!arquivo.is_open())
    std::cout << "Erro na abertura do arquivo para escrita!" << std::endl;

  for (auto pessoa : gerenciamento) {
    int tipoPessoa, diaAux, mesAux, anoAux, idadeAux;

    std::string pessoaNome, pessoaCodigo, pessoaNac;
    arquivo << diaAux << "\n" << mesAux << "\n" << anoAux << "\n";
    arquivo.ignore();
    arquivo << pessoaNome << std::endl;
    arquivo << pessoaCodigo << std::endl;
    arquivo << pessoaNac << std::endl;
    arquivo << idadeAux << std::endl;
  }
}

void GerenciamentoOlimpiadas::AdicionarPessoa(Pessoa *p) { // Create
  gerenciamento.push_back(p);
}

void GerenciamentoOlimpiadas::gerarRelatorio() {
  // deve mostrar a quantidade de pessoas no geral, e a quantidade de cada subclasse
  // exibir relatorio
  int countTotal = 0, countTorcedor = 0, countComissao = 0, countAtleta = 0;

  // Conta pessoas e os tipos
  for (auto p : gerenciamento) {
    if (p->tipo == 1)
      countAtleta++;
    else if (p->tipo == 2)
      countComissao++;
    else if (p->tipo == 3)
      countTorcedor++;
    countTotal++;
  }

  if (countTotal == 0) {
    std::cout << "Nao ha pessoas cadastradas" << std::endl;
    return;
  } else {
    float porcAtleta = 100 * (float)countAtleta / (float)countTotal;
    float porcComissao = 100 * (float)countComissao / (float)countTotal;
    float porcTorcedor = 100 * (float)countTorcedor / (float)countTotal;

    std::cout << "Quantidade total de pessoas: " << countTotal << std::endl;
    std::cout << "Quantidade total de Atletas: " << countAtleta << " (" << porcAtleta << "%)" << std::endl;
    std::cout << "Quantidade total de Membros da Comissao: " << countComissao << " (" << porcComissao << "%)" << std::endl;
    std::cout << "Quantidade total de Torcedores: " << countTorcedor << " (" << porcTorcedor << "%)" << std::endl;
  }
}

void GerenciamentoOlimpiadas::exibirTodos() {
    int contador = 1; // Inicializa o contador
    for (Pessoa* pessoa : gerenciamento) {
        std::cout << contador;
        contador++; // Incrementa o contador
        if(pessoa->tipo == 1)
          std::cout << "Atleta";
        if(pessoa->tipo == 2)
          std::cout << "Comissao";
        if(pessoa->tipo == 3)
          std::cout << "Torcedor";
        std::cout << " : " << pessoa->getNome() << std::endl;
    }
}
//   int count = 0;
//     for(auto p : gerenciamento) {
//     count++;
//     std::string imprimir = "-> " + std::to_string(count) + p->getTipo() + ": " + p->getNome();
//     std::cout << imprimir << std::endl;
//   }
// }

int GerenciamentoOlimpiadas::lerDadosPessoa() {
  Pessoa *pessoaAux;
  std::string nome, codigo, nacionalidade;
  int dia, mes, ano, idade, tipoPessoa;

  std::cin.ignore();
  std::cout << "Digite o nome da pessoa a ser adicionada" << "\n-> ";
  std::getline(std::cin, nome);

  std::cout << "Digite o dia do nascimento de " << nome << "\n-> ";
  std::cin >> dia;
  std::cout << "Digite o mes do nascimento de " << nome << "\n-> ";
  std::cin >> mes;
  std::cout << "Digite o ano do nascimento de " << nome << "\n-> ";
  std::cin >> ano;
  Data dataNasc(dia, mes, ano);

  std::cout << "Digite o codigo de " << nome << "\n-> ";
  std::cin >> codigo;

  std::cin.ignore();
  std::cout << "Digite a nacionalidade de " << nome << "\n-> ";
  std::getline(std::cin, nacionalidade);

  std::cout << "Digite a idade de " << nome << "\n-> ";
  std::cin >> idade;

  std::cout << "Digite o tipo" << std::endl;
  std::cout << "-> 1 Atleta\t-> 2 Membro da comissao\n-> 3 Torcedor\t-> 4 Cancelar operacao\n-> ";
  std::cin >> tipoPessoa;

  if (tipoPessoa == 1) {

    std::cin.ignore();
    int medalha;
    std::string modalidade;
    std::cout << "Digite a modalidade do atleta\n-> ";
    std::getline(std::cin, modalidade);
    std::cout << "Digite a colocacao de " << nome << " em " << modalidade << "\n-> ";
    std::cin >> medalha;

    pessoaAux = new Atleta(dataNasc, nome, codigo, nacionalidade, idade, medalha, modalidade);

  } else if (tipoPessoa == 2) {

    std::cin.ignore();
    std::string modalidade, equipeResponsavel;
    std::cout << "Digite a modalidade de atuacao do membro da comissao:\n-> ";
    std::getline(std::cin, modalidade);
    std::cout << "Dentro de " << modalidade << ", digite a equipe de atuacao de " << nome << "\n-> ";
    std::getline(std::cin, equipeResponsavel);

    pessoaAux = new Comissao(dataNasc, nome, codigo, nacionalidade, idade, modalidade, equipeResponsavel);

  } else if (tipoPessoa == 3) {

    std::cin.ignore();
    bool vipBool;
    std::string vip;
    std::cout << "O torcedor " << nome << " possui acesso vip? (Sim/Nao)\n-> ";
    std::getline(std::cin, vip);

    if ((vip.find("s") != -1) || (vip.find("S") != -1) ||
        (vip.find("y") != -1) || (vip.find("y") != -1))
      vipBool = true;
    else
      vipBool = false;

    pessoaAux = new Torcedor(dataNasc, nome, codigo, nacionalidade, idade, vipBool);
  } else {
    delete pessoaAux;
  }
  AdicionarPessoa(pessoaAux);
  delete pessoaAux;
  return 0;
}

int GerenciamentoOlimpiadas::alterarPessoa() {
  // Pessoa *p = &buscar();
  Pessoa *pessoaAlterar;
  Pessoa *p = buscar();
  int indice = 0;
  for (auto busca : gerenciamento) {
    if (busca->getCodigo() == p->getCodigo()) {
      break;
    }
    indice++;
  }
  if (indice > gerenciamento.size())
    return 1;

  int escolha;

  std::cout << "Digite o que sera alterado" << std::endl;
  std::cout << "-> 1 Data de Nascimento" << std::endl;
  std::cout << "-> 2 Nome" << std::endl;
  std::cout << "-> 3 Codigo" << std::endl;
  std::cout << "-> 4 Nacionalidade" << std::endl;
  std::cout << "-> 5 idade" << std::endl;

  if (p->tipo == 1) {
    std::cout << "-> 6 Medalha" << std::endl;
    std::cout << "-> 7 Modalidade" << std::endl;
    std::cout << "\n-> ";

  } else if (p->tipo == 2) {
    std::cout << "-> 6 Modalidade" << std::endl;
    std::cout << "-> 7 Equipe de atuacao" << std::endl;
    std::cout << "\n-> ";

  } else if (p->tipo == 3) {
    std::cout << "-> 6 Status VIP" << std::endl;
    std::cout << "\n-> ";
  }

  std::cin >> escolha;
  std::cin.ignore();

  switch (escolha) {
  case 1: {
    // Para alterar a data de nascimento
    int diaAux, mesAux, anoAux;
    std::cout << "Digite o dia da nova data de nascimento de " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::cin >> diaAux;
    std::cout << "Digite o mes da nova data de nascimento de " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::cin >> mesAux;
    std::cout << "Digite o ano da nova data de nascimento de " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::cin >> anoAux;
    Data novaDataDeNascimento(diaAux, mesAux, anoAux);
    gerenciamento[indice]->setDataDeNascimento(novaDataDeNascimento);
    std::cout << "Nova data de nascimento de " << gerenciamento[indice]->getNome() << " definida com sucesso!" << std::endl;
    return 0;
  } break;
  case 2: {
    // Para alterar o nome
    std::cout << "Digite o novo nome para alterar " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::string novoNome;
    std::cin.ignore();
    getline(std::cin, novoNome);
    gerenciamento[indice]->setNome(novoNome);
    std::cout << "Novo nome definido com sucesso!" << std::endl;
    return 0;
  } break;
  case 3: {
    // Para alterar o codigo
    std::cout << "Digite o novo codigo para " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::string novoCodigo;
    std::cin.ignore();
    getline(std::cin, novoCodigo);
    gerenciamento[indice]->setCodigo(novoCodigo);
    std::cout << "Novo codigo de " << gerenciamento[indice]->getNome() << " definido com sucesso!" << std::endl;
    return 0;
  } break;
  case 4: {
    // Para alterar a nacionalidade
    std::cout << "Digite a nova nacionalidade para " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::string novaNacionalidade;
    std::cin.ignore();
    getline(std::cin, novaNacionalidade);
    gerenciamento[indice]->setNacionalidade(novaNacionalidade);
    std::cout << "Nova nacionalidade de " << gerenciamento[indice]->getNome() << " definida com sucesso!" << std::endl;
    return 0;
  } break;
  case 5: {
    // Para alterar a idade
    std::cout << "Digite a nova idade para " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    int idade;
    std::cin >> idade;
    gerenciamento[indice]->setIdade(idade);
    std::cout << "Nova idade de " << gerenciamento[indice]->getNome() << " definida com sucesso!" << std::endl;
    return 0;
  } break;
  default:
    return 0;
    break;
  }

  if (p->tipo == 1 && escolha == 6) {
    // alterar a medalha do atleta

    int medalha;
    std::cout << "Digite a nova colocacao de " << gerenciamento[indice]->getNome() << " em " << dynamic_cast<Atleta *>(gerenciamento[indice])->getModalidade() << std::endl;
    std::cout << "\n-> ";
    std::cin >> medalha;
    dynamic_cast<Atleta *>(gerenciamento[indice])->setMedalha(medalha);
    std::cout << "Nova medalha de " << gerenciamento[indice]->getNome() << " definida com sucesso!" << std::endl;
    return 0;
  } else if (p->tipo == 2 && escolha == 7) {
    // alterar a modalidade do atleta

    std::cout << "Digite a nova modalidade para " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::string novaModalidade;
    std::cin.ignore();
    getline(std::cin, novaModalidade);
    dynamic_cast<Atleta *>(gerenciamento[indice])->setModalidade(novaModalidade);
    std::cout << "Nova modalidade de " << gerenciamento[indice]->getNome() << " definida com sucesso!" << std::endl;
    return 0;
  }

  if (p->tipo == 2 && escolha == 6) {
    // alterar a modalidade do membro da comissao

    std::cout << "Digite a nova modalidade para " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::string novaModalidade;
    std::cin.ignore();
    getline(std::cin, novaModalidade);
    dynamic_cast<Comissao *>(gerenciamento[indice])->setModalidade(novaModalidade);
    std::cout << "Nova modalidade de " << gerenciamento[indice]->getNome() << " definida com sucesso!" << std::endl;
    return 0;
  } else if (p->tipo == 2 && escolha == 7) {
    // alterar a equipe do membro da comissao

    std::cout << "Digite a nova equipe da comissao para " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::string novaEquipeResponsavel;
    std::cin.ignore();
    getline(std::cin, novaEquipeResponsavel);
    dynamic_cast<Comissao *>(gerenciamento[indice])->setEquipeResponsavel(novaEquipeResponsavel);
    std::cout << "Nova equipe de " << gerenciamento[indice]->getNome() << " definida com sucesso!" << std::endl;
    return 0;
  }

  if (p->tipo == 3 && escolha == 6) {
    // alterar o statusVip do torcedor

    std::string vip;
    std::cout << "O torcedor " << gerenciamento[indice]->getNome();
    std::string retornoStatus = (dynamic_cast<Torcedor *>(gerenciamento[indice])->getStatusVIP()) ? " possui status VIP" : " nao possui status VIP";
    std::cout << retornoStatus;
    std::cout << "\nGostaria de alterar?\n\n->";
    std::getline(std::cin, vip);

    if ((vip.find("s") != -1) || (vip.find("S") != -1) ||
        (vip.find("y") != -1) || (vip.find("y") != -1)) {
      dynamic_cast<Torcedor *>(gerenciamento[indice])->setStatus(!dynamic_cast<Torcedor *>(gerenciamento[indice])->getStatusVIP());
      std::cout << "Status VIP de " << gerenciamento[indice]->getNome() << " alterado com sucesso!" << std::endl;
      return 0;
    }
  };
}

void GerenciamentoOlimpiadas::removerPessoa() {
  Pessoa *pessoaRemov = buscar();
  int indice = 0;
  if (pessoaRemov == nullptr) {
    std::cout << "Pessoa nao encontrada, logo, nao sera apagada" << std::endl;
    return;
  };
  for (auto p : gerenciamento) {
    if (p->getNome() == pessoaRemov->getNome())
      break;
    indice++;
  }
  gerenciamento.erase(gerenciamento.begin() + indice);
  // remover
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
    int erro = lerDadosPessoa();
    if (erro == 1)
      return 1;
    return 0;
  };
  case 2: {
    exibirTodos();
    break;
    // listar
  };
  case 3: {
    Pessoa *p = buscar();
    switch (p->tipo) {
      case 1:
        dynamic_cast<Atleta *>(p)->exibir();
        break;
      case 2:
        dynamic_cast<Comissao *>(p)->exibir();
        break;
      case 3:
        dynamic_cast<Torcedor *>(p)->exibir();
        break;
      }
    break;
  };
  case 4: {
    // alterar
    // falta tratar o retorno e acabar o metodo
    int erro = alterarPessoa();
    if (erro == 1)
      return 1;
    return 0;
  };
  case 5: {
    removerPessoa();
    return 0;
  };
  case 6: {
    gerarRelatorio();
    break;
  };
  case 7: {
    return 1;
    // sair
  };
  default:
    break;
  }
  return 0;
};

Pessoa *GerenciamentoOlimpiadas::buscar() {

  int count = 0;
  exibirTodos();

  std::cout << "\n\nEscolha o nome\n->";
  std::string nome;
  std::cin >> std::ws;
  getline(std::cin, nome);
  for (int i = 0; i < gerenciamento.size(); i++) {
    if (gerenciamento[i]->getNome() == nome) {
      std::cout << "Pessoa encontrada!\n"
                << gerenciamento[i]->getNome() << " - ";
      switch (gerenciamento[i]->tipo) {
      case 1:
        std::cout << "Atleta\n";
        break;
      case 2:
        std::cout << "Comissao\n";
        break;
      case 3:
        std::cout << "Torcedor\n";
        break;
      }
      return gerenciamento[i];
    }
  }
  // Adicionei o retorno nulo caso nao encontre nenhuma pessoa, alem de exibir uma mensagem
  std::cout << "Pessoa nao encontrada!" << std::endl;
  return nullptr;
}
