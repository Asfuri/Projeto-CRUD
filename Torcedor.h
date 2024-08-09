#ifndef TORCEDOR_H
#define TORCEDOR_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Pessoa.h"

class Torcedor : public Pessoa {
private:
  int Status;

  Pessoa pessoa;

public:
  Torcedor();
};
#endif
