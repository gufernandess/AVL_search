<div align="center">
    <h1>AVL Search</h1>
    <p>
        Consulte dados de forma rápida e otimizada utilizando árvores balanceadas!
    </p>
</div>

<div align="justify">
    <h2>Introdução</h2>
    <p>
        Este projeto foi implementado para a disciplina de Estrutura de Dados Avançada (EDA), visando o estudo e aprofundamento em árvores balanceadas e suas aplicações práticas na resolução de problemas do dia-a-dia.
    </p>
    <p>
        O projeto consiste em, dado um determinado banco de dados com informações de centenas de pessoas, usar árvores balanceadas para a disposição e consulta destes dados, com o principal objetivo de realizar consultas sob esses dados em complexidade de tempo O(log n), garantindo eficiência na resposta às consultas.
    </p>
    <p>
        Para a implementação deste projeto foi utilizado a linguagem de programação C++, junto do paradigma de Orientação a Objetos e de templates para a construção da árvore e das demais entidades necessárias. A IDE/editor de código utilizado para a implementação foi o VScode.
    </p>
</div>

## 📋 Sumário

   * [Introdução](#)
   * [Sumário](#)
   * [Como executar a aplicação](#)
   * [Requisitos](#)
   * [Autor](#)

## Como executar a aplicação

<div align="justify">
    <p>
        Antes de tudo, é necessário verificar se a sua máquina possui o compilador para C++ instalado, só desta forma será possível executar a aplicação. Sistemas operacionais baseados em Ubuntu/Debian/Arch possuem o compilador em seu sistema por padrão, e o MacOS possui o compilador equivalente Clang para o padrão C++, logo a verificação só é necessária em sistemas Windows.
    </p>
    <p>
        Para verificar se o compilador está instalado em sua máquina, execute o seguinte código:
    </p>

```shell
    g++ --version
```
<p>
    Caso o terminal retorne a versão requisitada do compilador, significa que o mesmo está instalado. Caso contrário, será necessário instalá-lo, para isso consulte o <a href="https://www.freecodecamp.org/news/how-to-install-c-and-cpp-compiler-on-windows/">manual de instalação do g++ no Windows</a> da Freecodecamp ou semelhantes.
</p>

<p>
        Feita a instalação correta do g++, a primeira tarefa a ser feita é a de clonar o repositório para a sua máquina. Para isso, execute o seguinte código em seu terminal:
    </p>

```shell
    git clone git@github.com:gufernandess/AVL_search.git
```
<p>
    Após clonar o repositório, entre no diretório do projeto:        
</p>

```shell
    cd AVL_search
```
<p>Compile e execute: </p>

```shell
    g++ main.cpp -o main
```
```shell
    main
```
<p>
    E pronto! Se tudo correr bem, a aplicação será inicializada dentro do terminal e você poderá testar todas as funcionalidades do sistema!
    </p>
</div>

## Requisitos
- [x] Consultar pessoa pelo CPF e exibir seus dados na tela;
- [x] Consultar pessoas pelo nome e exibir seus dados na tela;
- [x] Consultar pessoas por intervalo de datas de nascimento e exibir seus dados na tela.

## Autor
<b><i>[Gustavo Fernandes](https://github.com/gufernandess)<i>
