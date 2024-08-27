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
  virtual ~Comissao();
  Comissao(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, int tipo, std::string modalidade, std::string equipeResponsavel);
  std::string getModalidade();
  std::string getEquipe();
  void exibir();
  // Setters
  void setDataDeNascimento(Data DataDeNascimento);
  void setNome(std::string Nome);
  void setCodigo(std::string Codigo);
  void setNacionalidade(std::string Nacionalidade);
  void setIdade(int idade);
  void setModalidade(std::string modalidade);
  void setEquipeResponsavel(std::string equipeResponsavel);
};
#endif
