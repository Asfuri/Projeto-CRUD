#ifndef GERENCIAMENTO_OLIMPIADAS_H
#define GERENCIAMENTO_OLIMPIADAS_H

#include <fstream>

#include "Atleta.h"
#include "Comissao.h"
#include "Data.h"
#include "Torcedor.h"

/*
  -Header da classe GerenciamentoOlimpiadas-

  GerenciamentoOlimpiadas � a principal classe do sistema, possuindo os atributos:
  
    Data dataInicio
    std::string Cidade
    Data dataFinal
    vector<Pessoa*> gerenciamento
    vector<Pessoa*> filtroPessoasIndice
    std::string Mascote

  -> Essa classe possui m�todos principais e auxiliares, sendo eles comentados em seu corpo com a sua utilidade e funcionamento
  -> Possui m�todos que interagem com os arquivos .txt e com o usu�rio

  -> Alguns m�todos principais s�o privados, pois s�o chamados a partir do menu(), que � um m�todo p�blico
  -> Apenas 4 m�todos s�o p�blicos:
    void iniciarOlimpiada();   -> Inicia todo o processamento dos dados salvos em .txt
    int menu();                -> Imprimir o menu que interage com o usu�rio
    void salvarArquivo();      -> Respons�vel por salvar o arquivo periodicamente
    GerenciamentoOlimpiadas(); -> Construtor

  -> Coment�rios internos dos m�todos no arquivo .cpp da classe
*/

class GerenciamentoOlimpiadas {
private:
  Data dataInicio;
  std::string cidade;
  Data dataFinal;
  std::vector<Pessoa *> gerenciamento;
  std::vector<Pessoa *> filtroPessoasIndice;
  std::string mascote;

  // M�todos privados
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
  // M�todos P�blicos
  void iniciarOlimpiada();
  int menu();
  void salvarArquivo();
  GerenciamentoOlimpiadas();
};
#endif
