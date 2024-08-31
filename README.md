# :medal_sports: Projeto CRUD - Jogos Olímpicos

- ### [:dart: Objetivo](#dart-objetivo)
- ### [:handball_person: Diagrama de Classes](#handball_person-diagrama-de-classes)
- ### [:person_fencing: Dependências](#person_fencing-dependências)
- ### [:bicyclist: Como rodar](#bicyclist-como-rodar)
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

O projeto tem como objetivo desenvolver um sistema que consiga proporcionar ao usuário, de maneira eficiente, a partir de entradas no terminal e utilizando C++, a possibilidade de gerir dados de uma competição olímpica. O gerenciamento do registro das pessoas completamente autonoma por parte do usuário e o gerenciamento dos dados da competição. O sistema tem requisitos de desenvolvimento estabelecidos pelas especificações determinadas pelo docente, sendo eles[^1][^2]:

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

## :bicyclist: Como rodar

***Requisitos***
- Um compilador c++, recomendamos o `clang++` ou o `g++`
- Um terminal de linha de comando
<br>
{c:red}Lembre de baixar o projeto e extrai-lo devidamente do .zip{/c} 

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

**OBS.:** Utilizamos de barra normal('/') considerando um ambiente como Git Bash, WSL e PowerShell, considere utilizar de barra invertida ('\\') em caso de não compilar
