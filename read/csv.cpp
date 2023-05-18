#ifndef CSV_H
#define CSV_H

#include <vector>
#include <fstream>

#include "../person/Person.h"

/**
 * Função implementada para 'splitar' os dados do arquivo CSV
 * em linhas.
*/

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> lines;
    std::string line;
    std::istringstream tokenStream(str);

    while (getline(tokenStream, line, delimiter)) {
        lines.push_back(line);
    }

    return lines;
}

/**
 * Função para ler o arquivo CSV e retornar um vetor com os objetos
 * Person contidos no arquivo.
*/

static std::vector<Person> read_csv(std::string file_name) {
    std::ifstream file(file_name);
    std::string line;

    std::vector<Person> people;

    while(getline(file, line)) {
        std::vector<std::string> row = split(line, ',');

        Date date = Date::to_date(row[3]);
        CPF cpf = CPF::ulli(row[0]);
		
        Person *person = new Person(cpf, row[1], row[2], date, row[4]);
        
        people.push_back(*person);
    }

    file.close();

    return people;
}

#endif