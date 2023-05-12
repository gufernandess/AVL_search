#ifndef PERSON_H
#define PERSON_H

#include <string>

#include "../date/Date.h"
class Person {

public:
     Person(std::string cpf, std::string name, std::string surname, Date birthdate, std::string hometown) 
           : cpf(cpf), name(name), surname(surname), 
             birthdate(birthdate), hometown(hometown) {};

    std::string getCpf() const { return cpf; }
    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }
    Date getBirthdate() const { return birthdate; }
    std::string getHometown() const { return hometown; }

private:

	std::string cpf; // Não é possível que o CPF seja do tipo inteiro (Problema do valor octal).
    std::string name;
    std::string surname;
    Date birthdate;
    std::string hometown;
};

#endif
