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
  int getDia();
  int getMes();
  int getAno();
  void setDia(int d);
  void setMes(int m);
  void setAno(int a);
  void operation0();

  // construtor para inicializar
  Data();
  Data(int d, int m, int a);
};
#endif
