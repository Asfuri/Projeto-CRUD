#ifndef COMISSAO_H
#define COMISSAO_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Pessoa.h"

class Comissao : public Pessoa {
protected:
  std::string modalidade;

  std::string equipeResponsavel;

public:
  Comissao();

  Comissao(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, std::string modalidade, std::string equipeResponsavel);

  void setModalidade(std::string modalidade);

  void setEquipe(std::string equipeResponsavel);

  std::string getModalidade();

  std::string getEquipe();
};
#endif
