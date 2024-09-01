#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <vector>

/*
  -Header da classe Data-

  Data � uma classe respons�vel por representar as datas como n�s utilizamos no cotidiano
  (Calend�rio gregoriano), possui os atributos:
    int dia
    int mes
    int ano

  -> Com esses atributos possu�mos m�todos que nos auxiliam em suas manipula��es, seus respectivos getters e setters

  -> Data tamb�m possui o m�todo validacaoData(), que, sendo chamada dentro do construtor, ir� validar se os valores dos atributos atribuidos s�o v�lidos. Tendo em vista uma entrada de Data do usu�rio (Tomando como pressuposto que todos os dados no .txt est�o corretos), o m�todo ir� pedir na entrada padr�o (std::cin) que o usu�rio digite valores v�lidos para o m�todo validar a inst�ncia de Data
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
