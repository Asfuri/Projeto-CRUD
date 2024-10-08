#include "../headers/Torcedor.h"

/*
  -Corpo dos m�todos de Torcedor-

  Torcedor � uma subclasse de Pessoa, tendo o atributo StatusVIP como adicional
  -> Com esse atributo extra possu�mos m�todos extras, seu get e seu get
  -> Torcedor tamb�m possui o m�todo exibir() individual, que utiliza o exibir de Pessoa como molde
*/

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
  std::string resposta = this->statusVIP ? "Sim\n" : "N�o\n";
  std::cout << resposta;
};

void Torcedor::setStatusVIP(bool statusVIP) {
  this->statusVIP = statusVIP;
};