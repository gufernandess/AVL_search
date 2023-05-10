#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>   

using namespace std;

class Person {

	string name;
    string surname;
	int cpf;
    string birthdate;
    string hometown;

    Person(string name, string surname, int cpf, string birthdate, string hometown) {
        this->name = name;
        this->surname = surname;
        this->cpf = cpf;
        this->birthdate = birthdate;
        this->hometown = hometown;
    }
};

#endif
