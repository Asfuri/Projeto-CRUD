# :medal_sports: Projeto CRUD - Jogos Olímpicos

- ### [:dart: Objetivo](#dart-objetivo-1)
- ### [:handball_person: Diagrama de Classes](#handball_person-diagrama-de-classes-1)
- ### [:person_fencing: Dependências](#person_fencing-dependências-1)
- ### [:bicyclist: Como rodar](#bicyclist-como-rodar-1)
- ### [:arrow_down: Baixar o projeto](https://github.com/Asfuri/Projeto-CRUD/archive/refs/heads/main.zip)

## Disciplina de Linguagem de Programação I e Laboratório

Esse foi um projeto desenvolvido por discentes do curso de *Engenharia da Computação da Universidade Federal da Paraíba*, curso este que pertence ao *[Centro de Informática](http://ci.ufpb.br/)*, localizado na *[Rua dos Escoteiros S/N - Mangabeira - João Pessoa - Paraíba - Brasil](https://g.co/kgs/xobLzCE)*. O programa decorrente do desenvolvimento do código foi empregado com o objetivo de permitir ao docente, utilizando de métodos avaliativos, calcular e atribuir as respectivas notas dos participiantes do projeto. 

### :softball: Autores:

-  :martial_arts_uniform:  *[Eduardo Asfuri Carvalho](https://github.com/Asfuri)*
-  :ping_pong:  *[Lucas Henrique Vieira da Silva](https://github.com/hvslucas)*
-  :boxing_glove:  *[Marco Antonio de Vasconcelos Souza Filho](https://github.com/MarcoFilho1)*

###  :volleyball: Docente:

-  	:skateboard: *[Derzu Omaia](https://github.com/derzu)*
<br>
<br>
<br>
<br>
<br>

[![olimpiada-101](https://github.com/user-attachments/assets/c4a37856-d934-4f63-867c-e3f9f500bf49)](#medal_sports-projeto-crud---jogos-olímpicos)

## :dart: Objetivo:

O projeto tem como objetivo desenvolver um sistema que consiga proporcionar ao usuário, de maneira eficiente, a partir de entradas no terminal e utilizando C++, a possibilidade de gerir dados de uma competição olímpica. O processo de gerenciamento do registro das pessoas é completamente autônomo por parte do usuário, enquanto o gerenciamento dos dados da competição é parcial, permitindo a inserção dos dados somente quando não houverem dados registrados. O sistema tem requisitos de desenvolvimento estabelecidos pelas especificações determinadas pelo docente, sendo eles[^1][^2]:

1. Ser um sistema CRUD que possua menu e tenha opões para gerir
2. Ter um diagrama de classes bem estabelecido que concorde com o código
3. Possuir composição na superclasse
4. Utilizar de herença e polimorfismo
5. Gerar relatório como uma das opções do menu
6. Ter todos os dados salvos em arquivo para que seja possível execuções sequenciais do programa

**Sendo destaque utilizar de POO e ser um CRUD**

[^1]: Requisitos 1 e 6 -> O Projeto se propõe a ter execuções dependentes (sequenciais) a partir dos dados salvos nos arquivos criados/alterados nas execuções antecedentes, fazendo com que os dados não se percam, utilizando do famoso acrônimo ***[CRUD](https://developer.mozilla.org/pt-BR/docs/Glossary/CRUD)*** para o gerenciamento dos dados.

[^2]: Requisitos 3 e 4 -> O Projeto deve ser feito utilizando ***[POO](https://www.techtarget.com/searchapparchitecture/definition/object-oriented-programming-OOP)*** e na linguagem ***[C++](https://www.w3schools.com/cpp/cpp_intro.asp)***

![gifRepositorio](https://github.com/user-attachments/assets/18712b30-aedb-4b4c-85d7-bcd5c2435313)

## :handball_person: Diagrama de Classes

![DIAGRAMAOLIMPIADAS](https://github.com/user-attachments/assets/97a85095-5bbf-4587-9232-73ead8a1ebb5)

## :person_fencing: Dependências

Este projeto foi desenvolvido utilizando apenas bibliotecas padrões do C++ e do sistema operacional[^3], ou seja, nenhuma biblioteca externa foi incluída no código. Abaixo, dissertamos sobre a utilidade de cada uma das bibliotecas implementadas, e exemplos de sua utilidade dentro do projeto:

### Bibliotecas Padrão

- **`<iostream>`**: Usada para operações básicas de entrada e saída, como leitura de dados do teclado (`std::cin`) e escrita de dados na tela (`std::cout`).
  - **Implementação:** Em interações direta com um usuário, via terminal.

- **`<string>`**: Fornece suporte à manipulação de strings, permitindo o uso da classe `std::string` para trabalhar com cadeias de caracteres de maneira mais conveniente a partir dos métodos fornecidos pela classe.
  - **Implementação:** Em validações de entradas do tipo `std::string` pelo usuário, em comparações utilizando `.find()` e em conversões entre tipos utilizando dos métodos `.toString()` e `.stoi`.

- **`<vector>`**: Fornece a classe `std::vector`, facilitando armazenar e manipular coleções de dados dinâmicos em formato de lista. A classe `std::vector` permite criar arrays dinâmicos que podem redimensionar automaticamente à medida que novos elementos são adicionados, que tornam sua utilização, a priori, intuitiva com os métodos da classe.
  - **Implementação:** Em compor o Objeto de GerencimentoOlimpada com dois arrays dinâmicos primordiais para o funcionamento de todo o CRUD, que teve como auxílio métodos como `push_back()` e `erase()`

- **`<fstream>`**: Fornece as classes para leitura e escrita em arquivos, como `std::fstream`, e seus respectivos métodos.
  - **Implementação:** Ao ler e escrever os dados em arquivos `.txt`, ou seja, é primordial para a execução sequencial do programa, utilizando os métodos `.open()` e `.close` para a disposição do arquivo.

- **`<limits>`**: Fornece informações sobre os limites das variáveis numéricas (como o valor máximo e mínimo que um tipo de dado pode armazenar) usando a classe `std::numeric_limits`.
  - **Implementação:** Ao tratar as entradas númericas do usuário, como ao utilizar o código `std::numeric_limits<std::streamsize>::max()` para receber no `cin.ignore()` valores irrelevantes.

- **`<algorithm>`**: Inclui uma variedade de algoritmos genéricos, como ordenação (`std::sort`), busca (`std::find`), entre outros, que podem ser aplicados a contêineres como vetores.
  - **Implementação:** Ao converter os ìndices (`char`) de uma determinada `std::string` em minúsculo utilizando do método `std::transform`.

- **`<locale>`**: Usada para trabalhar com diferentes configurações regionais, como formatos de números, datas, e outros parâmetros que podem variar conforme a localidade. A classe `std::locale` permite adaptar o comportamento do programa ao ambiente cultural do usuário.
  - **Implementação:** Ao formatar todo nosso código para o idioma Português brasileiro, para assim utilizar de acentos e caracteres especifícos do idioma `ç, ~`, utilizamos do método `std::setlocale()`.

### Bibliotecas Específicas de Plataforma
- O uso de `<unistd.h>` e `<windows.h>` depende da plataforma em que o programa está sendo compilado.

- **`<unistd.h>`** (Linux/Unix): Usada para acessar várias funcionalidades do sistema operacional POSIX, como chamadas de sistema para manipulação de arquivos, gerenciamento de processos, e manipulação de diretórios. Esta biblioteca é exclusiva para sistemas Unix-like.
  - **Implementação:** Ao decorar o terminal com uma pequena pausa utilizando do método `.sleep()`
  
- **`<windows.h>`** (Windows): Inclui funcionalidades específicas para o sistema operacional Windows, como manipulação de janelas, interação com hardware, gerenciamento de processos e threads, e muito mais. Esta biblioteca é exclusiva para o sistema operacional Windows.
  - **Implementação:** Ao decorar o terminal com uma pequena pausa utilizando do método `.sleep()`

## :bicyclist: Como rodar

***Requisitos***
- Um compilador c++, recomendamos o `clang++` ou o `g++`
- Um terminal de linha de comando

[**Atenção:** Lembre de baixar o projeto e extraí-lo devidamente do `.zip`.](#medal_sports-projeto-crud---jogos-olímpicos)

### Bash

Utilizando `g++` para compilar

```sh
cd /path/to/Projeto-CRUD
g++ main.cpp -I include/ src/*.cpp -o olimpiadas.out
```

Utilizando `clang++` para compilar

```sh
cd /path/to/Projeto-CRUD
clang++ main.cpp -I include/ src/*.cpp -o olimpiadas.out
```

Para rodar

```sh
./olimpiadas.out
```

### No Windows

Utilizando `g++` para compilar

```sh
cd /path/to/Projeto-CRUD
g++ main.cpp -I include/ src/*.cpp -o olimpiadas.exe
```

Utilizando `clang++` para compilar

```sh
cd /path/to/Projeto-CRUD
clang++ main.cpp -I include/ src/*.cpp -o olimpiadas.exe
```

Para rodar

```sh
./olimpiadas.exe
```

### Atenção
Para warnings referentes a codificação, recomendamos o uso da seguinte flag na compilação (válido para clang++)
```sh
-Wno-invalid-source-encoding
```

**OBS.:** Utilizamos de barra normal ('/') considerando um ambiente como Git Bash, WSL e PowerShell, considere utilizar de barra invertida ('\\') em caso de não compilar
