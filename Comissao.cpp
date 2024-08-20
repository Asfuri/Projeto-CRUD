#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Comissao.h"

Comissao::Comissao()
    : Pessoa() {
  this->modalidade = "";
  this->equipeResponsavel = "";
  this->tipo = 2;
}

Comissao::Comissao(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, std::string modalidade, std::string equipeResponsavel)
    : Pessoa(DataDeNascimento, Nome, Codigo, Nacionalidade, idade) {
  this->modalidade = modalidade;
  this->equipeResponsavel = equipeResponsavel;
  this->tipo = 2;
}

std::string Comissao::getModalidade() {
  return this->modalidade;
};

std::string Comissao::getEquipe() {
  return this->equipeResponsavel;
};

std::string Comissao::getTipo() {
  return "Membro da comissao";
};

void Comissao::setEquipe(std::string equipeResponsavel) {
  this->equipeResponsavel = equipeResponsavel;
}

void Comissao::exibir() {
  std::cout << "Membro da Comissao" << std::endl;
  Pessoa::exibir();
  std::cout << "Modalidade: " << this->modalidade << std::endl;
  std::cout << "Equipe responsavel: " << this->equipeResponsavel << std::endl;
}


void Comissao::setModalidade(std::string modalidade){
  this->modalidade = modalidade;
}