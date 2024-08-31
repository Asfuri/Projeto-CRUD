#ifndef TORCEDOR_H
#define TORCEDOR_H

#include "Pessoa.h"
#include <iostream>
#include <string>
#include <vector>

class Torcedor : public Pessoa {
protected:
  bool statusVIP;

public:
  Torcedor();
  virtual ~Torcedor();
  Torcedor(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, int tipo, bool statusVIP);
  bool getStatusVIP();
  void exibir();
  // Setters
  void setDataDeNascimento(Data DataDeNascimento);
  void setNome(std::string Nome);
  void setCodigo(std::string Codigo);
  void setNacionalidade(std::string Nacionalidade);
  void setIdade(int idade);
  void setStatusVIP(bool statusVIP);
};
#endif
