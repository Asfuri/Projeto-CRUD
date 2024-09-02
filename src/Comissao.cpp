#include "../headers/Comissao.h"

/*
  -Corpo dos m�todos de Comissao-

  Comissao � uma subclasse de Pessoa, tendo os atributos modalidade e equipeResponsavel como adicional
  -> Com esses atributos extras possu�mos m�todos extras, os seus respectivos getters e setters
  -> Comissao tamb�m possui o m�todo exibir() individual, que utiliza o exibir de Pessoa como molde
*/

Comissao::Comissao()
    : Pessoa() {
  this->modalidade = "";
  this->equipeResponsavel = "";
}

Comissao::~Comissao() {
}

Comissao::Comissao(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, int tipo, std::string modalidade, std::string equipeResponsavel)
    : Pessoa(DataDeNascimento, Nome, Codigo, Nacionalidade, idade, tipo) {

  this->modalidade = modalidade;
  this->equipeResponsavel = equipeResponsavel;
}

std::string Comissao::getModalidade() {
  return this->modalidade;
};

std::string Comissao::getEquipeResponsavel() {
  return this->equipeResponsavel;
};

void Comissao::exibir() {
  std::cout << "Membro da Comiss�o" << std::endl;
  Pessoa::exibir();
  std::cout << "Modalidade: " << this->modalidade << std::endl;
  std::cout << "Equipe respons�vel: " << this->equipeResponsavel << std::endl;
};

void Comissao::setModalidade(std::string modalidade) {
  this->modalidade = modalidade;
};

void Comissao::setEquipeResponsavel(std::string equipeResponsavel) {
  this->equipeResponsavel = equipeResponsavel;
};
