#ifndef TORCEDOR_H
#define TORCEDOR_H

#include "Pessoa.h"

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
  void setStatusVIP(bool statusVIP);
};
#endif
