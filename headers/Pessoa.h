#ifndef PESSOA_H
#define PESSOA_H

#include "Data.h"

/*
  -Header da classe Pessoa-

  -> Aqui estão declarados os atributos da classe e as assinaturas dos métodos

  Pessoa é uma superclasse, possuindo os atributos:
    Data DataDeNascimento
    std::string Nome
    std::string Codigo
    std::string Nacionalidade
    int idade
    int tipo

  -> Todos esses atributos são comuns entre suas subclasses e cada atributo possui getters e setters
  -> Pessoa também possui o método exibir(), sendo este sobrescrito por cada subclasse, mas que utiliza esse método como molde
*/

class Pessoa {
protected:
  Data DataDeNascimento;
  std::string Nome;
  std::string Codigo;
  std::string Nacionalidade;
  int idade;
  int tipo;

public:
  Pessoa();
  virtual ~Pessoa();
  Pessoa(Data DataDeNascimento, std::string Nome, std::string Codigo, std::string Nacionalidade, int idade, int tipo);
  Data getDataDeNascimento();
  virtual std::string getNome();
  std::string getCodigo();
  std::string getNacionalidade();
  int getTipo();
  int getIdade();
  void exibir();
  // Setters
  void setDataDeNascimento(Data DataDeNascimento);
  void setNome(std::string Nome);
  void setCodigo(std::string Codigo);
  void setNacionalidade(std::string Nacionalidade);
  void setIdade(int idade);
};
#endif
