#include <vector>

#include <Windows.h> // Biblioteca para trabalhar no ambiente do sistema operacional Windows.

#include "person/Person.h"
#include "avl_tree/avl.h"
#include "read/csv.h"

using namespace std;

int main() {
	system("chcp 65001 > nul"); // Define o encode para impressão correta das árvores (usado para a função bshow).
    SetConsoleOutputCP(CP_UTF8); // Define a codificação do console para UTF-8 (usado para reonhecer a codificação do CSV).

    static vector<Person> people = read_csv("data.csv");

    avl_tree<CPF> avl_tree_cpf;

    avl_tree<string> avl_tree_name;

    avl_tree<Date> avl_tree_birthdate;

	for(Person person : people) {
	    avl_tree_cpf.add(person.getCpf());
        avl_tree_name.add(person.getName() + " " + person.getSurname());
        avl_tree_birthdate.add(person.getBirthdate());
	}

    avl_tree_birthdate.bshow();

    return 0;
}