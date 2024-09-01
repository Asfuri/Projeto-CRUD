#ifndef GERENCIAMENTO_OLIMPIADAS_H
#define GERENCIAMENTO_OLIMPIADAS_H

#include <fstream>

#include "Atleta.h"
#include "Comissao.h"
#include "Data.h"
#include "Torcedor.h"

/*
  -Header da classe GerenciamentoOlimpiadas-

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

  -> Comentários internos dos métodos no arquivo .cpp da classe
*/

class GerenciamentoOlimpiadas {
private:
  Data dataInicio;
  std::string cidade;
  Data dataFinal;
  std::vector<Pessoa *> gerenciamento;
  std::vector<Pessoa *> filtroPessoasIndice;
  std::string mascote;

  // Métodos privados
  void setOlimpiada(Data dataInicio, std::string cidade, Data dataFinal, std::string mascote);
  void AdicionarPessoa(Pessoa *p);
  void lerArquivoOlimpiadas();
  void lerArquivoPessoas();
  void lerDadosPessoa();
  void exibirTodos();
  Pessoa *buscar();
  void gerarRelatorio();
  int alterarPessoa();
  void removerPessoa();

public:
  // Métodos Públicos
  void iniciarOlimpiada();
  int menu();
  void salvarArquivo();
  GerenciamentoOlimpiadas();
};
#endif
