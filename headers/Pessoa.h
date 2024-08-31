#ifndef PESSOA_H
#define PESSOA_H

#include "Data.h"
#include <iostream>
#include <string>
#include <vector>

class Pessoa {
protected:
  Data DataDeNascimento;
  std::string Nome;
  std::string Codigo;
  std::string Nacionalidade;
  int idade;
  int tipo;

public:
  Pessoa();
  virtual ~Pessoa();
  Pessoa(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, int tipo);
  Data getDataDeNascimento();
  virtual std::string getNome();
  std::string getCodigo();
  std::string getNacionalidade();
  int getTipo();
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
