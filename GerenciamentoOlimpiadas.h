#ifndef GERENCIAMENTO_OLIMPIADAS_H
#define GERENCIAMENTO_OLIMPIADAS_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

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

  std::vector<Pessoa> gerenciamento;

  std::string mascote;

  int posicao;

public:
  GerenciamentoOlimpiadas();

  void AdicionarPessoa(Pessoa p);

  void gerarRelatorio();

  void exibirTodos();

  void menu();

  Pessoa buscar();
};
#endif
