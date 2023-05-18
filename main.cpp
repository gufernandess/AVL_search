#include <vector>
#include <iostream>
#include <Windows.h> // Biblioteca para trabalhar no ambiente do sistema operacional Windows.

#include "person/Person.h"
#include "date/Date.h"
#include "avl_tree/avl.h"
#include "read/csv.cpp"
#include "menu/menu.cpp"

using namespace std;

int main() {
    cin .tie(0) -> sync_with_stdio(0); // Desativa a sincronização com o C e C++ para melhorar a performance de leitura e escrita de dados.
	system("chcp 65001 > nul"); // Define o encode para impressão correta das árvores (usado para a função bshow).
    SetConsoleOutputCP(CP_UTF8); // Define a codificação do console para UTF-8 (usado para reconhecer a codificação do CSV).

    static vector<Person> people = read_csv("data.csv");

    avl_tree<CPF> avl_tree_cpf;
    avl_tree<string> avl_tree_name;
    avl_tree<Date> avl_tree_birthdate;

	for(int i = 0; i < people.size(); i++) {
	    avl_tree_cpf.add(people[i].getCpf(), &people[i]);
        avl_tree_name.add(people[i].getName() + " " + people[i].getSurname(), &people[i]);
        avl_tree_birthdate.add(people[i].getBirthdate(), &people[i]);
	}

    short int option = 1;
    int key; // Variável para armazenar o código da tecla pressionada.

    unsigned long long int cpf;
    string name, initial_date, final_date;

    while(true) {
        show_menu(option);

        key = getch(); // Captura a tecla pressionada.

        switch(key) {
            case 72: // 72 é o código da tecla "seta para cima".
                option = (option > 1) ? (option - 1) : 7;
                break;

            case 80: // 80 é o código da tecla "seta para baixo".
                option = (option < 7) ? (option + 1) : 1;
                break;

            case 13: // 13 é o código da tecla "enter".
                switch(option) {
                    case 1:
                        system("cls");

                        avl_tree_cpf.bshow();

                        cout << "\n";
                        cout << "Pressione qualquer tecla para continuar..." << endl;

                        getch();

                        break;

                    case 2:
                        system("cls");

                        avl_tree_name.bshow();

                        cout << "\n";
                        cout << "Pressione qualquer tecla para continuar..." << endl;
                        
                        getch();

                        break;

                    case 3:
                        system("cls");
                        avl_tree_birthdate.bshow();

                        cout << "\n";
                        cout << "Pressione qualquer tecla para continuar..." << endl;
                        
                        getch();

                        break;

                    case 4:
                        system("cls");

                        cout << "\n";

                        cout << "Digite o CPF procurado (Utilize apenas números): " << endl;
                        cin >> cpf;

                        cout << "\n";

                        cout << avl_tree_cpf.search_by_CPF(cpf) << endl;

                        cout << "\n";
                        cout << "Pressione qualquer tecla para continuar..." << endl;
                        
                        getch();

                        break;

                    case 5:
                        system("cls");

                        cout << "\n";

                        cout << "Digite o nome procurado: " << endl;
                        cin >> name;

                        cout << "\n";

                        for(Person person : avl_tree_name.search_by_name(name)) {
                            cout << person << endl;
                            cout << "\n";
                        }

                        cout << "Pressione qualquer tecla para continuar..." << endl;
                        
                        getch();

                        break;

                    case 6:
                        system("cls");

                        cout << "\n";

                        cout << "Insira a data inicial (insira no formato 'mm/dd/yyyy') " << endl;
                        cin >> initial_date;

                        cout << "\n";

                        cout << "Insira a data final (insira no formato 'mm/dd/yyyy') " << endl;
                        cin >> final_date;

                        cout << "\n";

                        for(Person person : avl_tree_birthdate.search_by_date(Date::to_date(initial_date), Date::to_date(final_date))) {
                            cout << person << endl;
                            cout << "\n";
                        }

                        cout << "Pressione qualquer tecla para continuar..." << endl;
                        
                        getch();

                        break;

                    case 7:
                        cout << "\n";
                        cout << "Encerrando o programa..." << endl;

                        return 0;
                }

                break;
        }
    }

    return 0;
}