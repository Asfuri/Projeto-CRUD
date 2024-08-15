#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Torcedor.h"

Torcedor::Torcedor()
    : Pessoa() {
  this->statusVIP = false;
};

Torcedor::Torcedor(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, bool statusVIP)
    : Pessoa(DataDeNascimento, Nome, Codigo, Nacionalidade, idade) {
  this->statusVIP = statusVIP;
};

bool Torcedor::getStatusVIP() {
  return this->statusVIP;
};

void Torcedor::setTorcedor(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, bool statusVIP) {
  setPessoa(DataDeNascimento, Nome, Codigo, Nacionalidade, idade);
  this->statusVIP = statusVIP;
};
