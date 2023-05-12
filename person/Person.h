#ifndef PERSON_H
#define PERSON_H

#include <string>

#include "../date/Date.h"
class Person {

public:
     Person(unsigned long long int cpf, std::string name, std::string surname, Date birthdate, std::string hometown) 
           : cpf(cpf), name(name), surname(surname), 
             birthdate(birthdate), hometown(hometown) {};

    unsigned long long int getCpf() const { return cpf; }
    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }
    Date getBirthdate() const { return birthdate; }
    std::string getHometown() const { return hometown; }

private:

	unsigned long long int cpf; // Não é possível que o CPF seja do tipo inteiro (Problema do valor octal).
    std::string name;
    std::string surname;
    Date birthdate;
    std::string hometown;
};

/**
 * Também sobrecarreguei o operador de saída para Person, para uma melhor disposição
 * dos dados no terminal.
*/

std::ostream& operator<<(std::ostream& output, const Person& person) {
    output << "Nome Completo: " << person.getName() << " " << person.getSurname() << "\n"
              "CPF: " << person.getCpf() << "\n"
              "Data de Nascimento: " << person.getBirthdate() << "\n"
              "Cidade de Origem: " << person.getHometown() << "\n";
    
    return output;
}

#endif
