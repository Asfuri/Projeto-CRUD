#ifndef PESSOA_H
#define PESSOA_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Data.h"
#include "GerenciamentoOlimpiadas.h"

class Pessoa : public GerenciamentoOlimpiadas {
private:
  GerenciamentoOlimpiadas gerenciamentoOlimpiadas;

protected:
  Data DataDeNascimento;

  std::string Nome;

  std::string Codigo;

  std::string Nacionalidade;

  int idade;

public:
  Pessoa();

  void alterar();

  void operation5();
};
#endif
