#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

void show_menu(short int option) {
    system("cls"); // Limpa a tela do console a cada iteração.

    cout << "========== AVL_SEARCH ==========" << endl;

    cout << "\n";

    /**
     * Para cada valor possível de option, é exibido uma seta ">" para indicar a opção na qual
     * o cursor está em cima.
    */

    cout << (option == 1 ? "> " : "  ") << "1. Exibir árvore por CPF" << endl;
    cout << (option == 2 ? "> " : "  ") << "2. Exibir árvore por nome" << endl;
    cout << (option == 3 ? "> " : "  ") << "3. Exibir árvore por data de nascimento" << endl;
    cout << (option == 4 ? "> " : "  ") << "4. Pesquisar por CPF" << endl;
    cout << (option == 5 ? "> " : "  ") << "5. Pesquisar por nome" << endl;
    cout << (option == 6 ? "> " : "  ") << "6. Pesquisar por intervalo de data" << endl;
    cout << (option == 7 ? "> " : "  ") << "7. Sair" << endl;

    cout << "\n";

    cout << "================================" << endl;

    cout << "\n";

    cout << "Use as setas para cima e para baixo para navegar e pressione Enter para selecionar uma opção." << endl;
}