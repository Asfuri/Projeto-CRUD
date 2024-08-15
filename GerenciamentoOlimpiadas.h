#ifndef GERENCIAMENTO_OLIMPIADAS_H
#define GERENCIAMENTO_OLIMPIADAS_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Data.h"
#include "Pessoa.h"

class GerenciamentoOlimpiadas {
private:
  Data DatadeInicio;

  std::string Cidade;

  Data DataFinal;

  std::vector<Pessoa> gerenciamento;

  std::string mascote;

public:
  GerenciamentoOlimpiadas();

  void AdicionarPessoa();

  void gerarRelatorio();

  void exibirTodos();

  Pessoa buscar();
};
#endif
