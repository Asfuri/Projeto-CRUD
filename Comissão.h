#ifndef COMISSÃO_H
#define COMISSÃO_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Pessoa.h"

class Comissao : public Pessoa {
protected:
  std::string modalidade;

  std::string equipeResponsável;

public:
  Comissao();
};
#endif
