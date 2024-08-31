#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "../headers/Torcedor.h"

Torcedor::Torcedor()
    : Pessoa() {
  this->statusVIP = false;
};

Torcedor::~Torcedor() {
}

Torcedor::Torcedor(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, int tipo, bool statusVIP)
    : Pessoa(DataDeNascimento, Nome, Codigo, Nacionalidade, idade, tipo) {
  this->statusVIP = statusVIP;
};

bool Torcedor::getStatusVIP() {
  return this->statusVIP;
};

void Torcedor::exibir() {
  std::cout << "Torcedor" << std::endl;
  Pessoa::exibir();
  std::cout << "VIP: ";
  std::string resposta = this->statusVIP ? "Sim\n" : "Nao\n";
  std::cout << resposta;
};

void Torcedor::setDataDeNascimento(Data DataDeNascimento) {
  Pessoa::setDataDeNascimento(DataDeNascimento);
};

void Torcedor::setNome(std::string Nome) {
  Pessoa::setNome(Nome);
};

void Torcedor::setCodigo(std::string Codigo) {
  Pessoa::setCodigo(Codigo);
};

void Torcedor::setNacionalidade(std::string Nacionalidade) {
  Pessoa::setNacionalidade(Nacionalidade);
};

void Torcedor::setIdade(int idade) {
  Pessoa::setIdade(idade);
};

void Torcedor::setStatusVIP(bool statusVIP) {
  this->statusVIP = statusVIP;
};