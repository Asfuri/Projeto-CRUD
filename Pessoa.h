#ifndef PESSOA_H
#define PESSOA_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Data.h"
#include "GerenciamentoOlimp�adas.h"

class Pessoa : public GerenciamentoOlimp�adas {
private:
  GerenciamentoOlimp�adas gerenciamentoOlimp�adas;

protected:
  Data DataDeNascimento;

  std::string Nome;

  std::string C�digo;

  std::string Nacionalidade;

  int idade;

public:
  Pessoa();

  void alterar();

  void operation5();
};
#endif
