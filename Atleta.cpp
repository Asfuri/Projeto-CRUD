#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Atleta.h"

Atleta::Atleta()
   : Pessoa() { 
  this->medalha = 0;
  this->modalidade = "";
  this->tipo = 1;
  
}

Atleta::Atleta(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, int medalha, std::string modalidade)
    : Pessoa(DataDeNascimento, Nome, Codigo, Nacionalidade, idade) {

  this->medalha = medalha;
  this->modalidade = modalidade;
  this->tipo = 1;

};

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
  else {
        return "Participacao";
  }
};

int Atleta::getMedalhaNum() {
  return medalha;
};

std::string getTipo() {
  return "Atleta";
};

void Atleta::exibir() {
  std::cout << "Atleta" << std::endl;
  Pessoa::exibir();
  std::cout << "Modalidade: " << this->modalidade << std::endl;
  std::cout << "Medalha: " << getMedalha() << std::endl;
}
