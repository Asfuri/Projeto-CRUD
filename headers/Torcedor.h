#ifndef TORCEDOR_H
#define TORCEDOR_H

#include "Pessoa.h"

/*
  -Header da classe Torcedor-

  -> Aqui estão declarados os atributos da classe e as assinaturas dos métodos

  Torcedor é uma subclasse de Pessoa, tendo o atributo StatusVIP como adicional
  -> Com esse atributo extra possuímos métodos extras, seu get e seu get
  -> Torcedor também possui o método exibir() individual, que utiliza o exibir de Pessoa como molde
*/


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
