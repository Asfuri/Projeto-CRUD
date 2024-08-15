#ifndef TORCEDOR_H
#define TORCEDOR_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Pessoa.h"

class Torcedor : public Pessoa {
protected:
  bool statusVIP;

public:
  Torcedor();

  Torcedor(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, bool statusVIP);

  bool getStatusVIP();

  void setTorcedor(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, bool statusVIP);
};
#endif
