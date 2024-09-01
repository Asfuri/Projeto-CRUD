#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <vector>

/*
  -Header da classe Data-

  Data é uma classe responsável por representar as datas como nós utilizamos no cotidiano
  (Calendário gregoriano), possui os atributos:
    int dia
    int mes
    int ano

  -> Com esses atributos possuímos métodos que nos auxiliam em suas manipulações, seus respectivos getters e setters

  -> Data também possui o método validacaoData(), que, sendo chamada dentro do construtor, irá validar se os valores dos atributos atribuidos são válidos. Tendo em vista uma entrada de Data do usuário (Tomando como pressuposto que todos os dados no .txt estão corretos), o método irá pedir na entrada padrão (std::cin) que o usuário digite valores válidos para o método validar a instância de Data
*/

class Data {
private:
  int dia;
  int mes;
  int ano;
  void validacaoData();

public:
  // construtor para inicializar
  Data();
  Data(int dia, int mes, int ano);
  virtual ~Data();
  void exibir();
  int getDia();
  int getMes();
  int getAno();
  void setDia(int dia);
  void setMes(int mes);
  void setAno(int ano);
};
#endif
