#ifndef PESSOA_H
#define PESSOA_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Data.h"

class Pessoa {
protected:
  Data DataDeNascimento;

  std::string Nome;

  std::string Codigo;

  std::string Nacionalidade;

  int idade;

public:
  Pessoa();

  Pessoa(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade);

  Data getDataDeNascimento();

  std::string getNome();

  std::string getCodigo();

  std::string getNacionalidade();

  int getIdade();

  void setPessoa(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade);

  void alterar();

  void operation5();
};
#endif
