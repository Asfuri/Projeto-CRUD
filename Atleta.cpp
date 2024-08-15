#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Atleta.h"

Atleta::Atleta() {
}

void Atleta::setMedalha(int medalha) {
  this->medalha = medalha;
}

int Atleta::getMedalha() {
  return this->medalha;
}

void Atleta::setModalidade(std::string modalidade) {
  this->modalidade = modalidade;
}

std::string Atleta::getModalidade() {
  return this->modalidade;
}
