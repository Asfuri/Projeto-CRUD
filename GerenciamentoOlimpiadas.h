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
  void lerArquivoOlimpiadas();
  void lerArquivoPessoas();
  int lerDadosPessoa();
  int alterarPessoa();
  void removerPessoa();
  void AdicionarPessoa(Pessoa *p);
  void gerarRelatorio();
  void exibirTodos();
  Pessoa* buscar();

public:
  void iniciarOlimpiada();
  int menu();
  void salvarArquivo();
  GerenciamentoOlimpiadas();
  
};
#endif
