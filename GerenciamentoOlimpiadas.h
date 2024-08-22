#ifndef GERENCIAMENTO_OLIMPIADAS_H
#define GERENCIAMENTO_OLIMPIADAS_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>

#include "Atleta.h"
#include "Comissao.h"
#include "Data.h"
#include "Pessoa.h"
#include "Torcedor.h"

class GerenciamentoOlimpiadas {
private:
  Data DatadeInicio;
  std::string Cidade;
  Data DataFinal;
  std::vector<Pessoa*> gerenciamento;
  std::string mascote;
  int posicao;

public:
  GerenciamentoOlimpiadas();
  void setOlimpiada(Data DatadeInicio, std::string Cidade, Data DataFinal, std::string mascote);
  void iniciarOlimpiada();
  void lerArquivoOlimpiadas();
  void lerArquivoPessoas();
  void salvarArquivo();
  int lerDadosPessoa();
  int alterarPessoa();
  void removerPessoa();
  void AdicionarPessoa(Pessoa *p);
  void gerarRelatorio();
  void exibirTodos();
  int menu();
  Pessoa* buscar();
};
#endif
