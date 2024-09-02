#include "../headers/Comissao.h"

/*
  -Corpo dos métodos de Comissao-

  Comissao é uma subclasse de Pessoa, tendo os atributos modalidade e equipeResponsavel como adicional
  -> Com esses atributos extras possuímos métodos extras, os seus respectivos getters e setters
  -> Comissao também possui o método exibir() individual, que utiliza o exibir de Pessoa como molde
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
  std::cout << "Membro da Comissão" << std::endl;
  Pessoa::exibir();
  std::cout << "Modalidade: " << this->modalidade << std::endl;
  std::cout << "Equipe responsável: " << this->equipeResponsavel << std::endl;
};

void Comissao::setModalidade(std::string modalidade) {
  this->modalidade = modalidade;
};

void Comissao::setEquipeResponsavel(std::string equipeResponsavel) {
  this->equipeResponsavel = equipeResponsavel;
};
