#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {

public:
     Person(string cpf, string name, string surname, string birthdate, string hometown) 
           : cpf(cpf), name(name), surname(surname), 
             birthdate(birthdate), hometown(hometown) {}

    string getCpf() const { return cpf; }
    string getName() const { return name; }
    string getSurname() const { return surname; }
    string getBirthdate() const { return birthdate; }
    string getHometown() const { return hometown; }

private:

	string cpf; // Não é possível que o CPF seja do tipo inteiro (Problema do valor octal)
    string name;
    string surname;
    string birthdate; // Usando a biblioteca ctime para a contrução de datas
    string hometown;
};

#endif
