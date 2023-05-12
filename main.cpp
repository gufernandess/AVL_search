#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include <Windows.h> // Biblioteca para trabalhar no ambiente do sistema operacional Windows.

#include "person/Person.h"
#include "avl_tree/avl.h"

using namespace std;

/**
 * Função implementada para 'splitar' os dados do arquivo CSV
 * em linhas.
*/

vector<string> split(const string& str, char delimiter) {
    vector<string> lines;
    string line;
    istringstream tokenStream(str);

    while (getline(tokenStream, line, delimiter)) {
        lines.push_back(line);
    }

    return lines;
}

/**
 * Função para ler o arquivo CSV e retornar um vetor com os objetos
 * Person contidos no arquivo.
*/

vector<Person> read_csv(string file_name) {
    ifstream file(file_name);
    string line;

    vector<Person> people;

    while(getline(file, line)) {
        vector<string> row = split(line, ',');

        Date date = Date::to_date(row[3]);

        /**
         * Removendo os pontos e o traço do CPF para transformá-lo em inteiro
        */

        row[0].erase(remove(row[0].begin(), row[0].end(), '.'), row[0].end());
        row[0].erase(remove(row[0].begin(), row[0].end(), '-'), row[0].end());

        unsigned long long int cpf = static_cast<unsigned long long int>(std::stoll(row[0]));
		
        Person person(cpf, row[1], row[2], date, row[4]);
        
        people.push_back(person);
    }

    file.close();

    return people;
}

int main() {
	system("chcp 65001 > nul"); // Define o encode para impressão correta das árvores (usado para a função bshow).
    SetConsoleOutputCP(CP_UTF8); // Define a codificação do console para UTF-8 (usado para reonhecer a codificação do CSV).

    vector<Person> people = read_csv("data.csv");

    avl_tree<unsigned long long int> avl_tree_cpf;

    avl_tree<string> avl_tree_name;

    avl_tree<Date> avl_tree_birthdate;

	for(Person person : people) {
	    avl_tree_cpf.add(person.getCpf());
        avl_tree_name.add(person.getName());
        avl_tree_birthdate.add(person.getBirthdate());
	}

    avl_tree_birthdate.bshow();

    return 0;
}