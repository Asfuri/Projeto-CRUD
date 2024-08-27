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

  // Metodos privados
  void setOlimpiada(Data DatadeInicio, std::string Cidade, Data DataFinal, std::string mascote);
  void AdicionarPessoa(Pessoa *p);
  void lerArquivoOlimpiadas();
  void lerArquivoPessoas();
  int lerDadosPessoa(); // Falta documentar
  void exibirTodos();
  Pessoa* buscar();
  void gerarRelatorio();
  int alterarPessoa(); // Falta documentar
  void removerPessoa(); // Falta documentar

public:
  void iniciarOlimpiada();
  int menu(); // Falta documentar
  void salvarArquivo(); // Falta documentar
  GerenciamentoOlimpiadas();
  
};
#endif
