#ifndef ATLETA_H
#define ATLETA_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Pessoa.h"

class Atleta : public Pessoa {
protected:
  int medalha;
  std::string modalidade;

public:
  int tipo;
  Atleta();
  ~Atleta();
  Atleta(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, int medalha, std::string modalidade);
  std::string getModalidade();
  std::string getMedalha();
  int getMedalhaNum();
  std::string getTipo();
  void exibir();
  // Setters
  void setDataDeNascimento(Data DataDeNascimento);
  void setNome(std::string Nome);
  void setCodigo(std::string Codigo);
  void setNacionalidade(std::string Nacionalidade);
  void setIdade(int idade);
  void setMedalha(int medalha);
  void setModalidade(std::string modalidade);
};
#endif
