#ifndef COMISS�O_H
#define COMISS�O_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Pessoa.h"

class Comissao : public Pessoa {
protected:
  std::string modalidade;

  std::string equipeRespons�vel;

public:
  Comissao();
};
#endif
