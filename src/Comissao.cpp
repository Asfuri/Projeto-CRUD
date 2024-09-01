#include "../headers/Comissao.h"

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
  std::cout << "Membro da Comissao" << std::endl;
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
