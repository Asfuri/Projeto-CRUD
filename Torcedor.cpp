#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Torcedor.h"

Torcedor::Torcedor()
    : Pessoa() {
  this->statusVIP = false;
  this->tipo = 3;
};

Torcedor::~Torcedor(){
  
};

Torcedor::Torcedor(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, bool statusVIP)
    : Pessoa(DataDeNascimento, Nome, Codigo, Nacionalidade, idade) {
  this->statusVIP = statusVIP;
  this->tipo = 3;
};

bool Torcedor::getStatusVIP() {
  return this->statusVIP;
};

std::string Torcedor::getTipo() {
  return "Torcedor";
};

void Torcedor::exibir(){
  std::cout << "Torcedor" << std::endl;
  Pessoa::exibir();
  std::cout << "VIP: ";
  std::cout << (this->statusVIP) ? "Sim\n" : "Nao\n";
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

void Torcedor::setStatus(bool statusVIP) {
  this->statusVIP = statusVIP;
};