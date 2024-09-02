#include "../headers/GerenciamentoOlimpiadas.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
// #include <typeinfo>
#include <unistd.h>
#include <vector>

/*
  -Corpo dos métodos de GerenciamentoOlimpiadas-

  GerenciamentoOlimpiadas é a principal classe do sistema, possuindo os atributos:
  
    Data dataInicio
    std::string Cidade
    Data dataFinal
    vector<Pessoa*> gerenciamento
    vector<Pessoa*> filtroPessoasIndice
    std::string Mascote

  -> Essa classe possui métodos principais e auxiliares, sendo eles comentados em seu corpo com a sua utilidade e funcionamento
  -> Possui métodos que interagem com os arquivos .txt e com o usuário

  -> Alguns métodos principais são privados, pois são chamados a partir do menu(), que é um método público
  -> Apenas 4 métodos são públicos:
    void iniciarOlimpiada();   -> Inicia todo o processamento dos dados salvos em .txt
    int menu();                -> Imprimir o menu que interage com o usuário
    void salvarArquivo();      -> Responsável por salvar o arquivo periodicamente
    GerenciamentoOlimpiadas(); -> Construtor

*/

/*
  COMENTÁRIO DESTAQUE - VALIDAÇÃO DE ENTRADAS DO TIPO INTEIRO

  -> Para a verificação da entrada de inteiros foi utilizado o seguinte código:

  while (1) {                                                               // loop infinito
    std::cin >> VARIÁVEL TIPO INT;                                          // entrada do usuário
    if (std::cin.fail() || std::cin.peek() != '\n') {                       // verifica erro ou entrada incompleta
        std::cin.clear();                                                   // limpa o estado de erro
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpa buffer de entrada
        std::cout << "\nDigite um número válido! \n\n-> ";                  // mensagem de erro
    } else {
        break;                                                              // entrada válida, sai do loop
    }
  }

  -> std::cin.fail() -> Verifica se a operação de entrada falhou. Isso ocorre se o valor inserido não puder ser convertido corretamente para o tipo inteiro (por exemplo, se o usuário inserir letras em vez de um número).

  -> std::cin.peek() != '\n' -> olha o próximo caractere no buffer de entrada sem removê-lo. Se o próximo caractere não for uma nova linha (\n), significa que há algo mais na entrada que não foi consumido, indicando que a entrada era inválida ou incompleta.

  -> std::cin.clear() -> Em caso de uma entrada não válida, limpa o estado de erro da entrada para permitir que novas operações de entrada sejam realizadas. Sem isso, std::cin ficaria em estado de erro e nenhuma nova leitura poderia ser realizada.

  -> std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  -> Esta linha ignora (descarta - a partir do .ignore()) o restante da linha de entrada até encontrar um caractere de nova linha (\n), ou até atingir um número máximo de caracteres (determinado por std::numeric_limits<std::streamsize>::max())
  -> Basicamente, isso limpa qualquer entrada residual que possa estar no buffer, garantindo que na próxima iteração do loop a entrada esteja limpa para uma nova tentativa.

  -> Se a entrada foi bem-sucedida (ou seja, não houve falha e o buffer de entrada está limpo), o else é executado, interrompendo o loop com a instrução break.
  Isso significa que o loop só será interrompido quando o usuário inserir um valor numérico válido seguido de uma nova linha.
*/

GerenciamentoOlimpiadas::GerenciamentoOlimpiadas() {
  /*
    Construtor padrão -> Será utilizado na inicialização do programa,
    a única instância dessa classe deverá ser inicializada sem os dados armazenados,
    para então serem 'setados' todos os seus dados com "setOlimpiadas", método esse que
    é chamado no momento de leitura dos dados das olimpíadas, seja do arquivo, seja diretamente
    do terminal
  */
  this->dataInicio = Data();
  this->cidade = "";
  this->dataFinal = Data();
  this->mascote = "";
}

void GerenciamentoOlimpiadas::setOlimpiada(Data dataInicio, std::string cidade, Data dataFinal, std::string mascote) {
  /*
    Método para atribuir os dados das olimpíadas na instância da classe, é chamado após
    a leitura de dados, ou do arquivo ou do terminal
  */
  this->dataInicio = dataInicio;
  this->cidade = cidade;
  this->dataFinal = dataFinal;
  this->mascote = mascote;
}

void GerenciamentoOlimpiadas::AdicionarPessoa(Pessoa *p) {
  /*
    Esse método é responsável por acrescentar um ponteiro de Pessoa ao vector "gerenciamento"
    Esse método é chamado diversas vezes por outros métodos, tendo em vista que ele é método responsável por inserir Pessoas no vector (interação direta), sendo a chave do CREATE do sistema
  */
  gerenciamento.push_back(p);
}

void GerenciamentoOlimpiadas::lerArquivoOlimpiadas() {
  /*
    Esse método é responsável por fazer a leitura dos dados das Olimpiadas, que filtra,
    de acordo com o êxito da abertura do arquivo .txt, "dadosOlimpiadas", se os dados devem
    ser lidos do próprio .txt, caso esse exista, ou do terminal.

    -> Utiliza do setter da classe

    Execução ideal:
      -> Primeira execução:
        Os dados devem ser lidos do terminal e salvos no .txt para as próximas execuções
      -> As sucessivas execuções:
        Os dados devem ser lidos diretamente do arquivo, podendo ser consultado pelo usuário
        utilizando da opção 6 do menu

    OBS.: Para alteração dos dados, o usuário deverá apagar o .txt do ambiente em que o
    programa está sendo executado
  */
  std::fstream arqOlimpiada;
  arqOlimpiada.open("dadosOlimpiadas.txt", std::ios_base::in);

  if (arqOlimpiada.is_open()) {
    /*
      Testa se o arquivo foi devidamente aberto
      -> Caso sim : Irá ler as informações pelo arquivo
      -> Caso não : Irá ler as informações pelo terminal
    */
    int diaAux, mesAux, anoAux;
    std::string cidade, mascote;

    arqOlimpiada >> diaAux >> mesAux >> anoAux;
    Data dataInicioAux(diaAux, mesAux, anoAux);
    arqOlimpiada.ignore();

    getline(arqOlimpiada, cidade);
    arqOlimpiada >> diaAux >> mesAux >> anoAux;

    Data dataFinalAux(diaAux, mesAux, anoAux);
    arqOlimpiada.ignore();

    getline(arqOlimpiada, mascote);

    setOlimpiada(dataInicioAux, cidade, dataFinalAux, mascote);
    arqOlimpiada.close();

  } else {
    arqOlimpiada.close();

    /*
      Imprime algumas coisas sobre o projeto na tela
      -> Lê do usuário as informações sobre as olimpíadas, verificando sempre se a entrada é válida
      -> Grava no arquivo as informações que o usuário digitou
    */

    std::cout << "**********************************************\n";
    std::cout << "*                                            *\n";
    std::cout << "*     Bem-vindo ao nosso projeto de CRUD     *\n";
    std::cout << "*         com tema de Olimpíadas!            *\n";
    std::cout << "*                                            *\n";
    std::cout << "**********************************************\n\n\n";

    std::cout
        << "    \033[34m********         \033[30m*******         \033[31m********    \n"
        << "  \033[34m**        **    \033[30m***       ***    \033[31m**        **  \n"
        << " \033[34m*           **  \033[30m**           **  \033[31m**           * \n"
        << "\033[34m**            *  \033[30m*             *  \033[31m*            **\n"
        << "\033[34m*           \033[33m***\033[34m*\033[33m*\033[30m*\033[33m***        \033[32m****\033[30m*\033[32m****           \033[31m*\n"
        << " \033[34m**        \033[33m** \033[34m**  \033[30m**  \033[33m*     \033[32m* \033[30m**   \033[31m** \033[32m**       \033[31m**\n"
        << "  \033[34m**      \033[33m*  \033[34m**    \033[30m**  \033[33m*   \033[32m* \033[30m**     \033[31m**  \033[32m*     \033[31m** \n"
        << "   \033[34m*****\033[33m*\033[34m***        \033[30m**\033[33m**\033[30m*\033[32m**\033[30m**        \033[31m***\033[32m*\033[31m*****   \n"
        << "        \033[33m**            ** \033[32m**            **        \n"
        << "         \033[33m**           *   \033[32m*           **         \n"
        << "          \033[33m**        **     \033[32m**        **          \n"
        << "            \033[33m********         \033[32m********    \n\n";

    std::cout << "\033[0m" << "Desenvolvedores do projeto:\n";
    std::cout << "----------------------------------------------\n";
    std::cout << "* Eduardo Asfuri Carvalho                    * \n";
    std::cout << "* Lucas Henrique Vieira da Silva             * \n";
    std::cout << "* Marco Antonio de Vasconcelos Souza Filho   * \n";

    std::cout << "----------------------------------------------\n";
    std::cout << "Professor Responsável:\n";
    std::cout << "* Derzu Omaia                                *\n";
    std::cout << "----------------------------------------------\n\n";
    sleep(1);
    int diaAux, mesAux, anoAux, anoFinal;
    std::string cidade, mascote;
    std::cout << "Digite a cidade sede " << std::endl;
    std::cout << "\n-> ";
    getline(std::cin, cidade);
    std::cout << "\n";

    std::cout << "Digite o ano das olimpíadas de " << cidade << std::endl;
    std::cout << "\n-> ";
    while (1) {
      std::cin >> anoAux;
      if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nDigite um número válido! \n\n-> ";
      } else {
        break;
      }
    }
    std::cout << "\n";

    std::cout << "Digite o mês de " << anoAux << " que começam as olimpíadas de " << cidade << std::endl;
    std::cout << "\n-> ";
    while (1) {
      std::cin >> mesAux;
      if (std::cin.fail() || std::cin.peek() != '\n' || mesAux < 1 || mesAux > 12) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nDigite um número válido! \n\n-> ";
      } else {
        break;
      }
    }
    std::cout << "\n";

    std::cout << "Digite dia do mês de " << mesAux << "/" << anoAux << " que começam as olimpíadas de " << cidade << std::endl;
    std::cout << "\n-> ";
    while (1) {
      std::cin >> diaAux;
      if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nDigite um número válido! \n\n-> ";
      } else {
        break;
      }
    }
    std::cout << "\n";

    Data dataInicioAux(diaAux, mesAux, anoAux);

    std::cout << "Digite o ano que acabam as olimpíadas de " << cidade << std::endl;
    std::cout << "\n-> ";
    while (1) {
      std::cin >> anoFinal;
      if (std::cin.fail() || std::cin.peek() != '\n' || anoFinal < anoAux) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nDigite um número válido! \n\n-> ";
      } else {
        break;
      }
    }
    std::cout << "\n";

    std::cout << "Digite o mês de " << anoFinal << " que acabam as olimpíadas de " << cidade << std::endl;
    std::cout << "\n-> ";
    while (1) {
      std::cin >> mesAux;
      if (std::cin.fail() || std::cin.peek() != '\n' || (anoFinal == anoAux && mesAux < dataInicioAux.getMes()) || mesAux > 12 || mesAux < 1) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nDigite um mês válido! \n\n-> ";
      } else {
        break;
      }
    }
    std::cout << "\n";

    std::cout << "Digite dia do mês de " << mesAux << "/" << anoFinal << " que acabam as olimpíadas de " << cidade << std::endl;
    std::cout << "\n-> ";
    while (1) {
      std::cin >> diaAux;
      if (std::cin.fail() || std::cin.peek() != '\n' || (anoFinal == anoAux && mesAux == dataInicioAux.getMes() && diaAux < dataInicioAux.getDia()) || diaAux < 1) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nDigite um número válido! \n\n-> ";
      } else {
        break;
      }
    }
    std::cout << "\n";

    Data dataFinalAux(diaAux, mesAux, anoFinal);

    std::cout << "Digite o nome do mascote das olimpíadas de " << cidade << " " << anoAux << std::endl;
    std::cout << "\n-> ";
    std::cin.ignore();
    getline(std::cin, mascote);
    std::cout << "\n";

    setOlimpiada(dataInicioAux, cidade, dataFinalAux, mascote);

    // Começa a escrever no arquivo as informações sobre a olimpíada
    // O usuário so consegue "criar" outra olimpíada se apagar o arquivo "olimpiada.txt"
    // Isso deve ser documentado no README
    arqOlimpiada.open("dadosOlimpiadas.txt", std::ios_base::out);

    // Salvando a data inicial
    arqOlimpiada << dataInicioAux.getDia() << std::endl;
    arqOlimpiada << dataInicioAux.getMes() << std::endl;
    arqOlimpiada << dataInicioAux.getAno() << std::endl;

    // Salvando a cidade
    arqOlimpiada << cidade << std::endl;

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
  /*
    Esse método é responsável pela leitura do .txt "dadosPessoas", que deverá armazenar todas
    as pessoas da última execução (respeitando a decisão do usuário de inserir, alterar, e remover)
    Para articular a leitura de acordo com a subclasse de pessoa, o código deverá ler na seguinte ordem:
      - 1 . Tipo
      - 2 . Dia da data de nascimento
      - 3 . Mês da data de nascimento
      - 4 . Ano da data de nascimento
      - 5 . Nome
      - 6 . Código
      - 7 . Nacionalidade
      - 8 . Medalha     ||  Modalidade          ||  StatusVip
      - 9 . Modalidade  ||  Equipe Responsável  ||

    OBS.: Na primeira execução do código, o arquivo não deverá existir, tendo isso em vista, o mesmo não será lido e o método retorna

    -> Responsável por iniciar os índices do vector "gerenciamento", ou seja, iniciar os ponteiros de Pessoa com os construtores das subclasses (realizando polimorfismo)
    -> Também chama o método de inserir Pessoas no vector (AdicionarPessoa())
  */

  std::fstream arquivo;
  arquivo.open("dadosPessoas.txt", std::ios_base::in);
  if (!arquivo.is_open()) // Retorna caso o arquivo não seja aberto
    return;

  // Ler pessoa por pessoa do arquivo
  // Alocando ao vector de pessoas da superclasse

  // Declaração de variáveis auxiliares para receberem os valores salvos
  int tipoPessoa, diaAux, mesAux, anoAux;
  std::string pessoaNome, pessoaCodigo, pessoaNac;
  int idadeAux;

  while (arquivo >> tipoPessoa >> diaAux >> mesAux >> anoAux) {
    arquivo.ignore();
    Data dataAux = Data(diaAux, mesAux, anoAux);

    std::getline(arquivo, pessoaNome);
    std::getline(arquivo, pessoaCodigo);
    std::getline(arquivo, pessoaNac);
    arquivo >> idadeAux;

    if (tipoPessoa == 1) { // Atleta

      int auxMedalha;
      std::string auxMod;
      arquivo >> auxMedalha;
      arquivo.ignore();
      std::getline(arquivo, auxMod);
      Pessoa *pessoaAux = new Atleta(dataAux, pessoaNome, pessoaCodigo, pessoaNac, idadeAux, tipoPessoa, auxMedalha, auxMod);
      // Instanciando um atleta a partir dos dados do arquivo em PessoaAux

      // Alocando pessoa auxiliar no vector
      AdicionarPessoa(pessoaAux);

    } else if (tipoPessoa == 2) { // Membro da Comissão

      std::string auxMod, auxEquipResp;
      arquivo.ignore();
      std::getline(arquivo, auxMod);
      std::getline(arquivo, auxEquipResp);
      Pessoa *pessoaAux = new Comissao(dataAux, pessoaNome, pessoaCodigo, pessoaNac, idadeAux, tipoPessoa, auxMod, auxEquipResp);

      // Instanciando um membro da comissão a partir dos dados do arquivo em PessoaAux

      // Alocando pessoa auxiliar no vector
      AdicionarPessoa(pessoaAux);

    } else if (tipoPessoa == 3) { // Torcedor

      arquivo.ignore();
      int bitStatusVip;
      arquivo >> bitStatusVip;
      bool auxStatusVip = (bitStatusVip == 1) ? true : false;
      Pessoa *pessoaAux = new Torcedor(dataAux, pessoaNome, pessoaCodigo, pessoaNac, idadeAux, tipoPessoa, auxStatusVip);

      // Instanciando um torcedor a partir dos dados do arquivo em PessoaAux

      // Alocando pessoa auxiliar no vector
      AdicionarPessoa(pessoaAux);
    }
  };

  arquivo.close();
};

void GerenciamentoOlimpiadas::iniciarOlimpiada() {
  /*
    Esse método é responsável por chamar os métodos responsáveis pelo funcionamento sequencial
    das execuções do programa, sendo os mesmos responsáveis pelo READ do sistema.
  */

  lerArquivoOlimpiadas();
  lerArquivoPessoas();
}

void GerenciamentoOlimpiadas::lerDadosPessoa() {
  /*
    Esse método é responsável por ler diretamente do terminal todos os dados de uma determinada Pessoa
    que o usuário desejar inserir, ele vai iniciar um ponteiro de Pessoa com as informações utilizando
    o construtor da subclasse escolhida pelo usuário (tipo) e ao final do método irá chamar o método
    de adicionar a pessoa no vector "gerenciamento"

    -> Esse método lê os dados específicos das subclasses, sendo a leitura filtrada pela escolha do usuário

    -> A partir desse método possuímos o CREATE do sistema
  */
  Pessoa *pessoaAux;
  std::string nome, codigo, nacionalidade;
  int dia, mes, ano, idade, tipoPessoa;

  std::cout << "\nDigite o nome da pessoa a ser adicionada" << "\n\n-> ";
  std::getline(std::cin, nome);
  std::cout << "\n";

  std::cout << "Digite o dia do nascimento de " << nome << "\n\n-> ";
  while (1) {
    std::cin >> dia;
    if (std::cin.fail() || std::cin.peek() != '\n') {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "\nDigite um número válido! \n\n-> ";
    } else {
      break;
    }
  }
  std::cout << "\n";
  std::cout << "Digite o mes do nascimento de " << nome << "\n\n-> ";
  while (1) {
    std::cin >> mes;
    if (std::cin.fail() || std::cin.peek() != '\n') {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "\nDigite um número válido! \n\n-> ";
    } else {
      break;
    }
  }
  std::cout << "\n";
  std::cout << "Digite o ano do nascimento de " << nome << "\n\n-> ";

  while (1) {
    std::cin >> ano;
    std::cout << "\n";
    if (std::cin.fail() || std::cin.peek() != '\n' || dataInicio.getAno() < ano) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Digite um ano válido! \n\n-> ";
    } else {
      break;
    }
  }

  idade = dataInicio.getAno() - ano;
  Data dataNasc(dia, mes, ano);

  std::cin.ignore();
  std::cout << "Digite o código de " << nome << "\n\n-> ";
  getline(std::cin, codigo);
  std::cout << "\n";

  std::cout << "Digite a nacionalidade de " << nome << "\n\n-> ";
  std::getline(std::cin, nacionalidade);
  std::cout << "\n";

  std::cout << "Digite o tipo\n"
            << std::endl;
  std::cout << "-> \033[36m1\033[0m Atleta\t-> \033[36m2\033[0m Membro da comissão\n-> \033[36m3\033[0m Torcedor\t-> \033[36m4\033[0m Cancelar operação\n\n-> ";
  while (1) {
    std::cin >> tipoPessoa;
    std::cout << "\n";
    if (std::cin.fail() || std::cin.peek() != '\n') {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Digite um número válido! \n\n-> ";
    } else {
      break;
    }
  }

  if (tipoPessoa == 1) {

    std::cin.ignore();
    int medalha;
    std::string modalidade;
    std::cout << "Digite a modalidade do atleta\n\n-> ";
    std::getline(std::cin, modalidade);
    std::cout << "\n";
    std::cout << "Digite a colocação de " << nome << " em " << modalidade << "\n\n-> ";

    while (1) {
      std::cin >> medalha;
      std::cout << "\n";
      if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nDigite um número válido! \n\n-> ";
      } else {
        break;
      }
    }
    pessoaAux = new Atleta(dataNasc, nome, codigo, nacionalidade, idade, tipoPessoa, medalha, modalidade);

  } else if (tipoPessoa == 2) {

    std::cin.ignore();
    std::string modalidade, equipeResponsavel;
    std::cout << "Digite a modalidade de atuação do membro da comissão:\n\n-> ";
    std::getline(std::cin, modalidade);
    std::cout << "\n";
    std::cout << "Dentro de " << modalidade << ", digite a equipe de atuação de " << nome << "\n\n-> ";
    std::getline(std::cin, equipeResponsavel);
    std::cout << "\n";

    pessoaAux = new Comissao(dataNasc, nome, codigo, nacionalidade, idade, tipoPessoa, modalidade, equipeResponsavel);

  } else if (tipoPessoa == 3) {

    std::cin.ignore();
    bool vipBool;
    std::string vip;
    std::cout << "O torcedor " << nome << " possui acesso vip? (Sim/Nao)\n\n-> ";
    std::getline(std::cin, vip);
    std::cout << "\n";

    if ((vip.find("s") != -1) || (vip.find("S") != -1) ||
        (vip.find("y") != -1) || (vip.find("y") != -1))
      vipBool = true;
    else
      vipBool = false;

    pessoaAux = new Torcedor(dataNasc, nome, codigo, nacionalidade, idade, tipoPessoa, vipBool);
  } else {
    std::cout << "Operação cancelada! \n";
    return;
  }
  AdicionarPessoa(pessoaAux);
  std::cout << "Pessoa \033[32mregistrada\033[0m com sucesso!" << std::endl;
  return;
}

void GerenciamentoOlimpiadas::exibirTodos() {
  /*
    Esse método é responsável por exibir no terminal todos os índices do vector "gerenciamento" de maneira otimizada, imprimindo o valor ordinal do elemento no vector, o tipo da Pessoa (de qual subclasse é uma instância), seguido do nome. Ex.:

    1o - Atleta : Michael Phelps
    2o - Comissao : Bernardo Rocha
  */
  if (gerenciamento.size() == 0) {
    std::cout << "Não há pessoas registradas" << std::endl;
    return;
  } else {
    std::cout << "\nPessoas registradas:\n"
              << std::endl;
    int contador = 1;
    for (int i = 0; i < gerenciamento.size(); i++) {
      std::cout << "\033[36m" << contador << "°\033[0m";
      contador++;
      if (gerenciamento[i]->getTipo() == 1)
        std::cout << " - Atleta\t";
      if (gerenciamento[i]->getTipo() == 2)
        std::cout << " - Comissão\t";
      if (gerenciamento[i]->getTipo() == 3)
        std::cout << " - Torcedor\t";
      std::cout << " : " << gerenciamento[i]->getNome() << std::endl;
    }
  }
}
std::string paraMinusculo(const std::string &stringComMaiusculo) {
  std::string stringMinuscula = stringComMaiusculo;
  std::transform(stringMinuscula.begin(), stringMinuscula.end(), stringMinuscula.begin(), ::tolower);
  return stringMinuscula;
}

Pessoa *GerenciamentoOlimpiadas::buscar() {
  /*
    Esse método é responsável por realizar a busca por determinada Pessoa no vector, chamando primeiramente o método de exibição dos índices (exibirTodos()), após isso, o usuário deverá digitar um nome que coincide com uma das pessoas registradas, podendo ser completamente coincidente ou parcialmente. Em caso do usuário digitar uma entrada que coincide parcialmente com mais de uma pessoa registrada, o usuário será apresentado a uma nova lista de índices válidos para as pessoas que coincidem parcialmente com o que ele digitou anteriormente

    -> Esse método retorna a Pessoa encontrada (que é um ponteiro), retorno esse que deve ser tratado na chamada
    -> Esse método é chamado nos métodos de exibir (exibir com detalhe apenas uma Pessoa), alterar e remover
  */
  int count = 0;
  exibirTodos();
  std::cout << "\n\nEscolha o nome\n\n-> ";
  std::string nome;
  std::cin >> std::ws;
  getline(std::cin, nome);
  std::transform(nome.begin(), nome.end(), nome.begin(), ::tolower);
  std::cout << "\n";
  int contador = 0, indice;

  // Testar quantas pessoas tem com o nome digitado
  for (int i = 0; i < gerenciamento.size(); i++) {
    if (paraMinusculo(gerenciamento[i]->getNome()).find(nome) != -1) {
      contador++;

      indice = i;
    }
  }

  // No caso do nome ser incompatível com pelo menos um dos nomes no vector, o retorno será
  // um nullptr (ponteiro vazio), esse retorno deverá ser tratado no local de chamada
  if (contador == 0) {
    std::cout << "Pessoa não encontrada!" << std::endl;
    return nullptr;
  }

  if (contador == 1)
    return gerenciamento[indice];

  /* Quando ocorre de mais de uma pessoa possuir a mesma substring, essas pessoas serão
     adicionadas a um novo vector de Pessoas, onde será exibido o índice de cada uma e
     pedir ao usuário pra escolher de acordo com o índice.
     Detalhe --> O vector é apagado depois de cada interação, garantindo que nao terá um
     lixo de memória de execuções*/
  int indiceEscolha;
  // Imprimir a lista de pessoas que coincidem com o nome digitado pelo usuário
  // filtrando a partir das letras minusculas (normalização) dos nomes utilizando o método .find()
  for (int i = 0; i < gerenciamento.size(); i++) {

    if (paraMinusculo(gerenciamento[i]->getNome()).find(nome) != -1) {
      filtroPessoasIndice.push_back(gerenciamento[i]);
      std::cout << "\033[36m" << filtroPessoasIndice.size() - 1 << "\033[0m";

      if (gerenciamento[i]->getTipo() == 1)
        std::cout << " - Atleta\t";

      if (gerenciamento[i]->getTipo() == 2)
        std::cout << " - Comissão\t";

      if (gerenciamento[i]->getTipo() == 3)
        std::cout << " - Torcedor\t";

      std::cout << gerenciamento[i]->getNome() << std::endl;
    }
  }
  std::cout << "\n";
  std::cout << "Escolha o índice" << std::endl;
  std::cout << "\n-> ";
  while (1) {
    std::cin >> indiceEscolha;
    std::cout << "\n";
    if (std::cin.fail() || std::cin.peek() != '\n' || indiceEscolha < 0 || indiceEscolha >= filtroPessoasIndice.size()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Digite um número válido! \n\n-> ";
    } else {
      break;
    }
  }
  Pessoa *retornoPessoa = filtroPessoasIndice[indiceEscolha];
  filtroPessoasIndice.clear();
  return retornoPessoa;
}

void GerenciamentoOlimpiadas::gerarRelatorio() {
  /*
    -> Esse método é responsável por imprimir no terminal as informações gerais das Olimpíadas, sendo elas:
      - cidade e ano
      - Data de Inicio
      - Data Final
      - Nome do Mascote

    -> E é responsável também por imprimir no terminal as informações das Pessoas que estão cadastradas no sistema, sendo esses dados brutos e comparativos. Caso não haja Pessoas cadastradas, ele irá imprimir e retornar
  */
  std::cout << "\n";
  std::cout << "Olimpiadas de \033[33m" << cidade << " " << dataInicio.getAno() << "\033[0m" << std::endl;
  std::cout << "Data de Inicio: \033[33m";
  dataInicio.exibir();
  std::cout << "\033[0mData Final: \033[33m";
  dataFinal.exibir();
  std::cout << "\033[0mMascote dos jogos: \033[33m" << mascote << "\n\n\033[0m";

  int countTotal = 0, countTorcedor = 0, countComissao = 0, countAtleta = 0;

  // Conta pessoas e os tipos
  for (auto p : gerenciamento) {
    if (p->getTipo() == 1)
      countAtleta++;
    else if (p->getTipo() == 2)
      countComissao++;
    else if (p->getTipo() == 3)
      countTorcedor++;
    countTotal++;
  }

  if (countTotal == 0) {
    // Caso o vector seja vazio, ele imprime esse fato e retorna
    std::cout << "\033[0mNão há pessoas cadastradas\033[33m" << std::endl;
    return;
  } else {
    // Imprime os dados brutos e comparativos das Pessoas
    float porcAtleta = 100 * (float)countAtleta / (float)countTotal;
    float porcComissao = 100 * (float)countComissao / (float)countTotal;
    float porcTorcedor = 100 * (float)countTorcedor / (float)countTotal;

    std::cout << "Quantidade total de Pessoas: \033[33m" << countTotal << "\033[0m" << std::endl;
    std::cout << "Quantidade total de Atletas: \033[33m" << countAtleta << " (" << porcAtleta << "%)\033[0m" << std::endl;
    std::cout << "Quantidade total de Membros da Comissão: \033[33m" << countComissao << " (" << porcComissao << "%)\033[0m" << std::endl;
    std::cout << "Quantidade total de Torcedores: \033[33m" << countTorcedor << " (" << porcTorcedor << "%)\033[0m" << std::endl;
  }
}

int GerenciamentoOlimpiadas::alterarPessoa() {
  /*
    Esse método é responsável por alterar as informações de uma determinada Pessoa que já está registrada,
    alterando o elemento do vector, sendo o método de salvar o arquivo ao final da execução responsável por alterar no arquivo

    -> Primeiramente permite ao usuário selecionar o elemento do vector, utilizando do método "buscar()"
    -> Após o êxito em selecionar a Pessoa a ser alterada (ele compara o código e o nome para ter acesso ao índice do vector), o método irá ler qual propriedade, de acordo com o tipo, o usuário quer alterar
    -> Considerando as propriedades de Pessoa, que são comuns entre as subclasses, essas podem ser
    alterados diretamente sem precisar consultar o tipo

    OBS -> Esse método não irá interagir com o

    -> Esse método é responsável pelo EDIT do sistema

  */

  Pessoa *p = buscar();
  if (p == nullptr) {
    return 0;
  };

  int indice = 0;

  for (auto busca : gerenciamento) {
    if (busca->getNome() == p->getNome() && busca->getCodigo() == p->getCodigo())
      break;

    indice++;
  }

  if (indice > gerenciamento.size())
    return 1;

  std::cout << "Digite o que será alterado" << std::endl;
  std::cout << "-> \033[36m1\033[0m Data de Nascimento" << std::endl;
  std::cout << "-> \033[36m2\033[0m Nome" << std::endl;
  std::cout << "-> \033[36m3\033[0m Código" << std::endl;
  std::cout << "-> \033[36m4\033[0m Nacionalidade" << std::endl;

  if (p->getTipo() == 1) {
    std::cout << "-> \033[36m5\033[0m Medalha" << std::endl;
    std::cout << "-> \033[36m6\033[0m Modalidade" << std::endl;

  } else if (p->getTipo() == 2) {
    std::cout << "-> \033[36m5\033[0m Modalidade" << std::endl;
    std::cout << "-> \033[36m6\033[0m Equipe de atuação" << std::endl;

  } else if (p->getTipo() == 3) {
    std::cout << "-> \033[36m5\033[0m Status VIP" << std::endl;
  }
  
  std::cout << "-> \033[31mOutro\033[0m Cancelar operação\n\n-> " << std::endl;
  std::cin >> std::ws;
  std::string strEscolha;
  getline(std::cin, strEscolha);

  if (strEscolha.size() > 1) {
    std::cout << "\nOperação cancelada" << std::endl;
    return 0;
  }

  const char *arrayEscolha = strEscolha.c_str();
  char escolha = arrayEscolha[0];

  switch (escolha) {
  case '1': {
    // Para alterar a data de nascimento
    int diaAux, mesAux, anoAux;
    std::cout << "Digite o dia da nova data de nascimento de " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    while (1) {
      std::cin >> diaAux;
      if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nDigite um número válido! \n\n-> ";
      } else {
        break;
      }
    }
    std::cout << "\n";
    std::cout << "Digite o mês da nova data de nascimento de " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    while (1) {
      std::cin >> mesAux;
      if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nDigite um número válido! \n\n-> ";
      } else {
        break;
      }
    }
    std::cout << "\n";
    std::cout << "Digite o ano da nova data de nascimento de " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    while (1) {
      std::cin >> anoAux;
      if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nDigite um número válido! \n\n-> ";
      } else {
        break;
      }
    }
    std::cout << "\n";
    Data novaDataDeNascimento(diaAux, mesAux, anoAux);
    gerenciamento[indice]->setDataDeNascimento(novaDataDeNascimento);
    std::cout << "Nova data de nascimento de " << gerenciamento[indice]->getNome() << " \033[35mdefinida\033[0m com sucesso!" << std::endl;

    int idade = dataInicio.getAno() - anoAux;
    gerenciamento[indice]->setIdade(idade);
    std::cout << "Nova idade de " << gerenciamento[indice]->getNome() << " \033[35mdefinida\033[0m com sucesso!" << std::endl;
    return 0;
  } break;
  case '2': {
    // Para alterar o nome
    std::cout << "Digite o novo nome para alterar " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::string novoNome;
    std::cin.ignore();
    getline(std::cin, novoNome);
    std::cout << "\n";
    gerenciamento[indice]->setNome(novoNome);
    std::cout << "Novo nome \033[35mdefinido\033[0m com sucesso!" << std::endl;
    return 0;
  } break;
  case '3': {
    // Para alterar o codigo
    std::cout << "Digite o novo código para " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::string novoCodigo;
    std::cin >> std::ws;
    getline(std::cin, novoCodigo);
    std::cout << "\n";
    gerenciamento[indice]->setCodigo(novoCodigo);
    std::cout << "Novo código de " << gerenciamento[indice]->getNome() << " \033[35mdefinido\033[0m com sucesso!" << std::endl;
    return 0;
  } break;
  case '4': {
    // Para alterar a nacionalidade
    std::cout << "Digite a nova nacionalidade para " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::string novaNacionalidade;
    std::cin.ignore();
    getline(std::cin, novaNacionalidade);
    std::cout << "\n";
    gerenciamento[indice]->setNacionalidade(novaNacionalidade);
    std::cout << "Nova nacionalidade de " << gerenciamento[indice]->getNome() << " \033[35mdefinida\033[0m com sucesso!" << std::endl;
    return 0;
  } break;
  default:
    break;
  }

  if (p->getTipo() == 1 && escolha == '5') {
    // alterar a medalha do atleta

    int medalha;
    std::cout << "Digite a nova colocação de " << gerenciamento[indice]->getNome() << " em " << dynamic_cast<Atleta *>(gerenciamento[indice])->getModalidade() << std::endl;
    std::cout << "\n-> ";
    while (1) {
      std::cin >> medalha;
      std::cout << "\n";
      if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Digite um número válido! \n\n-> ";
      } else {
        break;
      }
    }
    dynamic_cast<Atleta *>(gerenciamento[indice])->setMedalha(medalha);
    std::cout << "Nova medalha de " << gerenciamento[indice]->getNome() << " \033[35mdefinida\033[0m com sucesso!" << std::endl;
    return 0;
  } else if (p->getTipo() == 1 && escolha == '6') {
    // alterar a modalidade do atleta

    std::cout << "Digite a nova modalidade para " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::string novaModalidade;
    std::cin >> std::ws;
    getline(std::cin, novaModalidade);
    std::cout << "\n";
    dynamic_cast<Atleta *>(gerenciamento[indice])->setModalidade(novaModalidade);
    std::cout << "Nova modalidade de " << gerenciamento[indice]->getNome() << " \033[35mdefinida\033[0m com sucesso!" << std::endl;
    return 0;
  }

  if (p->getTipo() == 2 && escolha == '5') {
    // alterar a modalidade do membro da comissão

    std::cout << "Digite a nova modalidade para " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::string novaModalidade;
    // std::cin.ignore();
    std::cin >> std::ws;
    getline(std::cin, novaModalidade);
    std::cout << "\n";
    dynamic_cast<Comissao *>(gerenciamento[indice])->setModalidade(novaModalidade);
    std::cout << "Nova modalidade de " << gerenciamento[indice]->getNome() << " \033[35mdefinida\033[0m com sucesso!" << std::endl;
    return 0;
  } else if (p->getTipo() == 2 && escolha == '6') {
    // alterar a equipe do membro da comissão

    std::cout << "Digite a nova equipe da comissão para " << gerenciamento[indice]->getNome() << std::endl;
    std::cout << "\n-> ";
    std::string novaEquipeResponsavel;
    std::cin >> std::ws;
    // std::cin.ignore();
    getline(std::cin, novaEquipeResponsavel);
    std::cout << "\n";
    dynamic_cast<Comissao *>(gerenciamento[indice])->setEquipeResponsavel(novaEquipeResponsavel);
    std::cout << "Nova equipe de " << gerenciamento[indice]->getNome() << " \033[35mdefinida\033[0m com sucesso!" << std::endl;
    return 0;
  }

  if (p->getTipo() == 3 && escolha == '5') {
    // alterar o statusVip do torcedor

    std::string vip;
    std::cout << "O torcedor " << gerenciamento[indice]->getNome();
    std::string retornoStatus = (dynamic_cast<Torcedor *>(gerenciamento[indice])->getStatusVIP()) ? " possui status VIP" : " nao possui status VIP";
    std::cout << retornoStatus;
    std::cout << "\nGostaria de alterar?\n\n-> ";
    std::cin >> std::ws;
    std::getline(std::cin, vip);
    std::cout << "\n";

    if ((vip.find("s") != -1) || (vip.find("S") != -1) ||
        (vip.find("y") != -1) || (vip.find("y") != -1)) {
      dynamic_cast<Torcedor *>(gerenciamento[indice])->setStatusVIP(!dynamic_cast<Torcedor *>(gerenciamento[indice])->getStatusVIP());
      std::cout << "Status VIP de " << gerenciamento[indice]->getNome() << " \033[35malterado\033[0m com sucesso!" << std::endl;
      return 0;
    } else {
      std::cout << "Não será alterado! \n";
      return 0;
    }
  };

  std::cout << "Operação Cancelada! " << std::endl;
  return 0;
}

void GerenciamentoOlimpiadas::removerPessoa() {
  /*
    Esse método é responsável por remover o registro de uma Pessoa, tendo em vista que o arquivo só será salvo ao final da execução, ele exclui diretamente do registro do vector "gerenciamento", deixando a alteração no arquivo para o método, caso já tenha dados salvos dessa instância, por responsabilidade do método de salvar o arquivo

    -> Primeiramente permite ao usuário selecionar o elemento do vector, utilizando do método "buscar()"
    -> Após o êxito em selecionar a Pessoa a ser removida, o método irá remover e comunicar no terminal se a operação foi bem sucedida

    -> Esse método é responsável pelo DELETE do sistema
  */
  Pessoa *pessoaRemov = buscar();
  int indice = 0;
  if (pessoaRemov == nullptr) {
    std::cout << "Pessoa nao encontrada, logo, nao sera apagada" << std::endl;
    sleep(1);
    return;
  };
  for (auto p : gerenciamento) {
     if (p->getNome() == pessoaRemov->getNome() && p->getCodigo() == pessoaRemov->getCodigo())
      break;
    indice++;
  }
  gerenciamento.erase(gerenciamento.begin() + indice);
  std::cout << "Pessoa \033[31mremovida\033[0m com sucesso!" << std::endl;
  // remover
}

int GerenciamentoOlimpiadas::menu() {
  /*
    Esse método é responsável pela principal exibição no terminal, mostrando ao usuário suas opções de gerenciamento do registro das Pessoas.

    -> Responsável por dar nível de autonomia ao usuário, já que, a partir desse método, o próprio usuário irá coordenar o fluxo da execução do programa

    -> Responsável por chamar os principais grandes métodos a partir da escolha do usuário
  */
  std::cout << "\n\n";
  std::cout << "\033[36m1\033[0m. Inserir pessoa" << std::endl;
  std::cout << "\033[36m2\033[0m. Listar pessoas" << std::endl;
  std::cout << "\033[36m3\033[0m. Exibir pessoa" << std::endl;
  std::cout << "\033[36m4\033[0m. Alterar pessoa" << std::endl;
  std::cout << "\033[36m5\033[0m. Remover pessoa" << std::endl;
  std::cout << "\033[36m6\033[0m. Exibir Relatório" << std::endl;
  std::cout << "\033[36m7\033[0m. Sair" << std::endl;
  std::cout << "\n-> ";

  std::cin >> std::ws;
  std::string strOpcao;
  getline(std::cin, strOpcao);
  std::cout << "\n";

  if (strOpcao.size() > 1) {
    if(strOpcao == "7777777"){
      std::cout << "Querido programador:\nQuando eu escrevi este código,\napenas eu e Deus sabíamos como\nele funcionava. Agora, apenas Deus sabe!"  << std::endl;
      sleep(4);
      std::cout << "\nPortanto, se estiver tentando\nmelhorar este código porque está com bug...\ne com certeza está, por favor, aumente este contador\ncomo um aviso para o próximo programador:" << std::endl;
      sleep(4);
      std::cout << "\ntotal_de_horas_gastas_aqui: 79 horas" << std::endl;
      sleep(2);
      return 0;
    }
    std::cout << "Entrada inválida! " << std::endl;
    return 0;
  }

  const char *arrayOpcao = strOpcao.c_str();
  char opcao = arrayOpcao[0];

  switch (opcao) {
  case '1': {
    lerDadosPessoa();
    return 0;
  };
  case '2': {
    if (gerenciamento.size() == 0) {
      std::cout << "Não possui pessoas registradas" << std::endl;
      sleep(1);
      break;
    }
    exibirTodos();
    sleep(1);
    break;
    // listar
  };
  case '3': {
    if (gerenciamento.size() == 0) {
      std::cout << "Não possui pessoas registradas" << std::endl;
      return 0;
    }
    Pessoa *p = buscar();
    if (p == nullptr) {
      return 0;
    };
    switch (p->getTipo()) {
    case 1:
      dynamic_cast<Atleta *>(p)->exibir();
      sleep(1);
      break;
    case 2:
      dynamic_cast<Comissao *>(p)->exibir();
      sleep(1);
      break;
    case 3:
      dynamic_cast<Torcedor *>(p)->exibir();
      sleep(1);
      break;
    }
    break;
  };
  case '4': {
    // alterar
    if (gerenciamento.size() == 0) {
      std::cout << "Não possui pessoas registradas" << std::endl;
      sleep(1);
      break;
    }
    int erro = alterarPessoa();
    return 0;
  };
  case '5': {
    if (gerenciamento.size() == 0) {
      std::cout << "Não possui pessoas registradas" << std::endl;
      sleep(1);
      break;
    }
    removerPessoa();
    sleep(1);
    return 0;
  };
  case '6': {
    gerarRelatorio();
    sleep(1);
    break;
  };
  case '7': {
    return 1;
    // sair
  };
  default:
    std::cout << "Entrada inválida! " << std::endl;
    sleep(1);
    return 0;
    break;
  }
  return 0;
}

void GerenciamentoOlimpiadas::salvarArquivo() {
  /*
    Esse método é responsável por salvar todos os dados do vector "gerenciamento" no arquivo "dadosPessoas.txt", salvando, em ordem, as Pessoas salvas no vector. O salvamento dos dados devem ser feitos na mesma ordem de que são lidos, que é:
      - 1 . Tipo
      - 2 . Dia da data de nascimento
      - 3 . Mês da data de nascimento
      - 4 . Ano da data de nascimento
      - 5 . Nome
      - 6 . Código
      - 7 . Nacionalidade
      - 8 . Medalha     ||  Modalidade          ||  StatusVip
      - 9 . Modalidade  ||  Equipe Responsavel  ||

    -> Esse método é responsável por manter todos os dados da execução na memória rígida da máquina, permitindo a execução sequencial do programa, tendo em vista que para os dados serem lidos, elem precisam ser salvos.

    -> Esse método é chamado apenas no final da execução do programa, permitindo que as modificações só sejam "carimbadas" ao final da execução
  */

  std::fstream arquivo;
  arquivo.open("dadosPessoas.txt", std::ios_base::out);

  if (!arquivo.is_open())
    std::cout << "Erro na abertura do arquivo para escrita!" << std::endl;

  for (auto pessoa : gerenciamento) {
    int tipoPessoa = pessoa->getTipo(), diaAux, mesAux, anoAux, idadeAux;

    arquivo << tipoPessoa << std::endl;
    arquivo << pessoa->getDataDeNascimento().getDia() << std::endl;
    arquivo << pessoa->getDataDeNascimento().getMes() << std::endl;
    arquivo << pessoa->getDataDeNascimento().getAno() << std::endl;
    arquivo << pessoa->getNome() << std::endl;
    arquivo << pessoa->getCodigo() << std::endl;
    arquivo << pessoa->getNacionalidade() << std::endl;
    arquivo << pessoa->getIdade() << std::endl;

    switch (tipoPessoa) {
    case 1:
      arquivo << dynamic_cast<Atleta *>(pessoa)->getMedalhaNum() << std::endl;
      arquivo << dynamic_cast<Atleta *>(pessoa)->getModalidade() << std::endl;
      break;

    case 2:
      arquivo << dynamic_cast<Comissao *>(pessoa)->getModalidade() << std::endl;
      arquivo << dynamic_cast<Comissao *>(pessoa)->getEquipeResponsavel() << std::endl;
      break;

    case 3:
      if (arquivo << dynamic_cast<Torcedor *>(pessoa)->getStatusVIP())
        arquivo << 1 << std::endl;
      else
        arquivo << 0 << std::endl;
      break;
    default:
      break;
    }
  }
}