#ifndef COMISSAO_H
#define COMISSAO_H

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
  std::string getEquipeResponsavel();
  void exibir();
  // Setters
  void setModalidade(std::string modalidade);
  void setEquipeResponsavel(std::string equipeResponsavel);
};
#endif
