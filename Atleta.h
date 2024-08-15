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
  void setMedalha(int medalha);
  int getMedalha();
  void setModalidade(std::string modalidade);
  std::string getModalidade();
  Atleta();
};
#endif
