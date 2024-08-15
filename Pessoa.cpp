#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Pessoa.h"

Pessoa::Pessoa() {
  this->DataDeNascimento = Data();
  this->Nome = "";
  this->Codigo = "";
  this->Nacionalidade = "";
  this->idade = 0;
}

Pessoa::Pessoa(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade) {
  this->DataDeNascimento = DataDeNascimento;
  this->Nome = Nome;
  this->Codigo = Codigo;
  this->Nacionalidade = Nacionalidade;
  this->idade = idade;
};

Data Pessoa::getDataDeNascimento() {
  return this->DataDeNascimento;
};

std::string Pessoa::getNome() {
  return this->Nome;
};

std::string Pessoa::getCodigo() {
  return this->Codigo;
};

std::string Pessoa::getNacionalidade() {
  return this->Nacionalidade;
};

int Pessoa::getIdade() {
  return this->idade;
};

void Pessoa::setPessoa(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade) {
  this->DataDeNascimento = DataDeNascimento;
  this->Nome = Nome;
  this->Codigo = Codigo;
  this->Nacionalidade = Nacionalidade;
  this->idade = idade;
};

void Pessoa::alterar() {
}

void Pessoa::operation5() {
}
