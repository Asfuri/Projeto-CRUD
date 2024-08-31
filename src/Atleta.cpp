#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "../headers/Atleta.h"

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
    return "Participacao";
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

void Atleta::setDataDeNascimento(Data DataDeNascimento) {
  Pessoa::setDataDeNascimento(DataDeNascimento);
};

void Atleta::setNome(std::string Nome) {
  Pessoa::setNome(Nome);
};

void Atleta::setCodigo(std::string Codigo) {
  Pessoa::setCodigo(Codigo);
};

void Atleta::setNacionalidade(std::string Nacionalidade) {
  Pessoa::setNacionalidade(Nacionalidade);
};

void Atleta::setIdade(int idade) {
  Pessoa::setIdade(idade);
};

void Atleta::setMedalha(int medalha) {
  this->medalha = medalha;
};

void Atleta::setModalidade(std::string modalidade) {
  this->modalidade = modalidade;
};
