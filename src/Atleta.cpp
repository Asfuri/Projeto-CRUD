#include "../headers/Atleta.h"

/*
  -Corpo dos m�todos de Atleta-

  Atleta � uma subclasse de Pessoa, tendo os atributos medalha e modalidade como adicional
  -> Com esses atributos extras possu�mos m�todos extras, os seus respectivos getters e setters
  -> Atleta tamb�m possui o m�todo exibir() individual, que utiliza o exibir de Pessoa como molde
*/

Atleta::Atleta()
    : Pessoa() {
  this->medalha = 0;
  this->modalidade = "";
}

Atleta::~Atleta() {
}

Atleta::Atleta(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, int tipo, int medalha, std::string modalidade)
    : Pessoa(DataDeNascimento, Nome, Codigo, Nacionalidade, idade, tipo) {

  this->medalha = medalha;
  this->modalidade = modalidade;
};

std::string Atleta::getModalidade() {
  return this->modalidade;
};

std::string Atleta::getMedalha() {

  if (this->medalha == 1)
    return "Ouro";
  else if (this->medalha == 2)
    return "Prata";
  else if (this->medalha == 3)
    return "Bronze";
  else {
    return "Participa��o";
  }
};

int Atleta::getMedalhaNum() {
  return medalha;
};

void Atleta::exibir() {
  std::cout << "Atleta" << std::endl;
  Pessoa::exibir();
  std::cout << "Modalidade: " << this->modalidade << std::endl;
  std::cout << "Medalha: " << getMedalha() << std::endl;
};

void Atleta::setMedalha(int medalha) {
  this->medalha = medalha;
};

void Atleta::setModalidade(std::string modalidade) {
  this->modalidade = modalidade;
};
