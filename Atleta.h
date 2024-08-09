#ifndef ATLETA_H
#define ATLETA_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Pessoa.h"

class Atleta : public Pessoa {
protected:
  int medalha;

  std::string modalidade;

public:
  Atleta();
};
#endif
