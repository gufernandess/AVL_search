#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include <Windows.h> // Biblioteca para trabalhar no ambiente do sistema operacional Windows

#include "person/Person.h"
#include "avl_tree/avl.h"

using namespace std;

/**
 * Função implementada para 'splitar' os dados do arquivo CSV
 * em linhas.
*/

vector<string>split(const string& str, char delimiter) {
    vector<string> lines;
    string line;
    istringstream tokenStream(str);

    while (getline(tokenStream, line, delimiter)) {
        lines.push_back(line);
    }

    return lines;
}

int main() {
	system("chcp 65001 > nul"); // Define o encode para impressão correta das árvores
    SetConsoleOutputCP(CP_UTF8); // Define a codificação do console para UTF-8

	ifstream file("data.csv");
    string line;
    vector<Person> people;

    while(getline(file, line)) {
        vector<string> row = split(line, ',');
		
        Person person(row[0], row[1], row[2], row[3], row[4]);
        
        people.push_back(person);
    }

    file.close();

    avl_tree<string> t;

	for(int i = 0; i < people.size(); i++) {
	    t.add(people[i].getCpf());
	}

    t.bshow();

    return 0;
}