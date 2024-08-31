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
  void setMedalha(int medalha);
  void setModalidade(std::string modalidade);
};
#endif
