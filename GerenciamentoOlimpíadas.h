#ifndef GERENCIAMENTO_OLIMPÍADAS_H
#define GERENCIAMENTO_OLIMPÍADAS_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Data.h"
#include "Pessoa.h"
#include "vector.h"

class GerenciamentoOlimpíadas {
private:
  Data DatadeInício;

  std::string Cidade;

  Data DataFinal;

  vector<Pessoa> gerenciamento;

  std::string mascote;

public:
  void AdicionarPessoa();

  void gerarRelatorio();

  void exibirTodos();

  Pessoa buscar();
};
#endif
