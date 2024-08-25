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
  virtual ~Pessoa();
  Pessoa(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade);
  int tipo;
  Data getDataDeNascimento();
  virtual std::string getNome();
  std::string getCodigo();
  std::string getNacionalidade();
  virtual std::string getTipo();
  int getIdade();
  void exibir();
  // Setters
  void setDataDeNascimento(Data DataDeNascimento);
  void setNome(std::string Nome);
  void setCodigo(std::string Codigo);
  void setNacionalidade(std::string Nacionalidade);
  void setIdade(int idade);
};
#endif
