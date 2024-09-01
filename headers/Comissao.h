#ifndef COMISSAO_H
#define COMISSAO_H

#include "Pessoa.h"

/*
  -Header da classe Comissao-

  -> Aqui estão declarados os atributos da classe e as assinaturas dos métodos

  Comissao é uma subclasse de Pessoa, tendo os atributos modalidade e equipeResponsavel como adicional
  -> Com esses atributos extras possuímos métodos extras, os seus respectivos getters e setters
  -> Comissao também possui o método exibir() individual, que utiliza o exibir de Pessoa como molde
*/

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
