#ifndef DATA_H
#define DATA_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

class Data {
private:
  int dia;
  int mes;
  int ano;

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
