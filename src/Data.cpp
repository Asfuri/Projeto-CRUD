#include "../headers/Data.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>

Data::Data() {
}

Data::Data(int dia, int mes, int ano) {
  this->dia = dia;
  this->mes = mes;
  this->ano = ano;
  validacaoData();
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
  if (this->dia >= 10 && this->mes >= 10)
    std::cout << this->dia << "/" << this->mes << "/" << this->ano << std::endl;
  else if (this->dia >= 10 && this->mes < 10)
    std::cout << this->dia << "/0" << this->mes << "/" << this->ano << std::endl;
  else if (this->dia < 10 && this->mes >= 10)
    std::cout << "0" << this->dia << "/" << this->mes << "/" << this->ano << std::endl;
  else if (this->dia < 10 && this->mes < 10)
    std::cout << "0" << this->dia << "/0" << this->mes << "/" << this->ano << std::endl;
};

int Data::getDataInt() {
  std::string data = std::to_string(this->ano) + std::to_string(this->mes) + std::to_string(this->dia);
  return std::stoi(data);
}

void Data::validacaoData() {
  while (true) {
    if (this->mes < 1 || this->mes > 12) {
      std::cout << "Digite um mês válido! (1-12)\n\n-> ";
      int mesAux;

      while (true) {
        std::cin >> mesAux;
        std::cout << "\n";
        if (std::cin.fail() || std::cin.peek() != '\n' || mesAux < 1 || mesAux > 12) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Digite um mês válido! (1-12)\n\n-> ";
        } else {
          break;
        }
      }

      setMes(mesAux);
      continue; // Reinicia o loop para validar o mês novamente
    }

    int maxDias;
    if (this->mes == 2) {
      if (this->ano % 4 == 0 && (this->ano % 100 != 0 || this->ano % 400 == 0)) {
        maxDias = 29; // Ano bissexto
      } else {
        maxDias = 28;
      }
    } else if (this->mes == 4 || this->mes == 6 || this->mes == 9 || this->mes == 11) {
      maxDias = 30;
    } else {
      maxDias = 31;
    }

    if (this->dia < 1 || this->dia > maxDias) {
      std::cout << "Digite um dia válido! (1-" << maxDias << ")\n\n-> ";
      int diaAux;

      while (true) {
        std::cin >> diaAux;
        std::cout << "\n";
        if (std::cin.fail() || std::cin.peek() != '\n' || diaAux < 1 || diaAux > maxDias) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Digite um dia válido! (1-" << maxDias << ")\n\n-> ";
        } else {
          break;
        }
      }
      setDia(diaAux);
    } else {
      break;
    }
  }
}