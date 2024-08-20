#ifndef GERENCIAMENTO_OLIMPIADAS_H
#define GERENCIAMENTO_OLIMPIADAS_H

#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>

#include "Atleta.h"
#include "Comissao.h"
#include "Data.h"
#include "Pessoa.h"
#include "Torcedor.h"

class GerenciamentoOlimpiadas {
private:
  Data DatadeInicio;
  std::string Cidade;
  Data DataFinal;
  std::vector<Pessoa*> gerenciamento;
  std::string mascote;
  int posicao;

public:
  GerenciamentoOlimpiadas();
  GerenciamentoOlimpiadas(Data DatadeInicio, std::string Cidade, Data DataFinal, std::string mascote);
  void lerArquivo();
  void salvarArquivo();
  void AdicionarPessoa(Pessoa *p);
  void gerarRelatorio();
  void exibirTodos();
  int menu();
  Pessoa* buscar();
};
#endif
