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
}

Comissao::Comissao(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, std::string modalidade, std::string equipeResponsavel)
    : Pessoa(DataDeNascimento, Nome, Codigo, Nacionalidade, idade) {
  this->modalidade = modalidade;
  this->equipeResponsavel = equipeResponsavel;
}

void Comissao::setEquipe(std::string equipeResponsavel) {
  this->equipeResponsavel = equipeResponsavel;
}
