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

void Atleta::setModalidade(std::string modalidade) {
  this->modalidade = modalidade;
}

std::string Atleta::getModalidade() {
  return this->modalidade;
}

std::string Atleta::getMedalha() {

  if(this->medalha == 1) 
        return "Ouro";

  else if(this->medalha == 2) 
        return "Prata";

  else if(this->medalha == 3)
        return "Bronze";

  else if((this->medalha < 0) || (this->medalha > 3))
        return "Participacao";
  
};

void Atleta::exibir() {
  std::cout << "Atleta" << std::endl;
  Pessoa::exibir();
  std::cout << "Modalidade: " << this->modalidade << std::endl;
  std::cout << "Medalha: " << getMedalha() << std::endl;
}
