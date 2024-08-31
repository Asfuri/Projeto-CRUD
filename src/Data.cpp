#include "../headers/Data.h"
#include <iostream>
#include <string>
#include <vector>

Data::Data() {
}

Data::Data(int dia, int mes, int ano) {
  this->dia = dia;
  this->mes = mes;
  this->ano = ano;
}

Data::~Data() {
}

int Data::getDia() {
  return this->dia;
}

int Data::getMes() {
  return this->mes;
}

int Data::getAno() {
  return this->ano;
}

void Data::setDia(int dia) {
  this->dia = dia;
}

void Data::setMes(int mes) {
  this->mes = mes;
}

void Data::setAno(int ano) {
  this->ano = ano;
}

void Data::exibir() {
  std::cout << this->dia << "/" << this->mes << "/" << this->ano << std::endl;
};