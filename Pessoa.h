#ifndef PESSOA_H
#define PESSOA_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Data.h"
#include "GerenciamentoOlimpíadas.h"

class Pessoa : public GerenciamentoOlimpíadas {
private:
  GerenciamentoOlimpíadas gerenciamentoOlimpíadas;

protected:
  Data DataDeNascimento;

  std::string Nome;

  std::string Código;

  std::string Nacionalidade;

  int idade;

public:
  Pessoa();

  void alterar();

  void operation5();
};
#endif
