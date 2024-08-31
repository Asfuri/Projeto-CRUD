#ifndef ATLETA_H
#define ATLETA_H

#include "Pessoa.h"
#include <iostream>
#include <string>
#include <vector>

class Atleta : public Pessoa {
protected:
  int medalha;
  std::string modalidade;

public:
  Atleta();
  virtual ~Atleta();
  Atleta(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, int tipo, int medalha, std::string modalidade);
  std::string getModalidade();
  std::string getMedalha();
  int getMedalhaNum();
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
