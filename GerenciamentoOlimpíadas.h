#ifndef GERENCIAMENTO_OLIMP�ADAS_H
#define GERENCIAMENTO_OLIMP�ADAS_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Data.h"
#include "Pessoa.h"
#include "vector.h"

class GerenciamentoOlimp�adas {
private:
  Data DatadeIn�cio;

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
