#ifndef GERENCIAMENTO_OLIMPIADAS_H
#define GERENCIAMENTO_OLIMPIADAS_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Atleta.h"
#include "Comissao.h"
#include "Data.h"
#include "Pessoa.h"
#include "Torcedor.h"

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
  void iniciarOlimpiada();
  int menu();
  void salvarArquivo();
  GerenciamentoOlimpiadas();
};
#endif
