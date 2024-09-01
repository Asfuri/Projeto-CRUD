#ifndef ATLETA_H
#define ATLETA_H

#include "Pessoa.h"

/*
  -Header da classe Atleta-

  -> Aqui est�o declarados os atributos da classe e as assinaturas dos m�todos

  Atleta � uma subclasse de Pessoa, tendo os atributos medalha e modalidade como adicional
  -> Com esses atributos extras possu�mos m�todos extras, os seus respectivos getters e setters
  -> Atleta tamb�m possui o m�todo exibir() individual, que utiliza o exibir de Pessoa como molde
*/

class Atleta : public Pessoa {
protected:
  int medalha;
  std::string modalidade;

public:
  Atleta();
  virtual ~Atleta();
  Atleta(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, int tipo, int medalha, std::string modalidade);
  std::string getModalidade();
  std::string getMedalha();
  int getMedalhaNum();
  void exibir();
  // Setters
  void setMedalha(int medalha);
  void setModalidade(std::string modalidade);
};
#endif
