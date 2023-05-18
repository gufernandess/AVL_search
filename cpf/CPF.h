#ifndef CPF_H
#define CPF_H

#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

/**
 * Criei uma classe CPF para, em suma, armazenar métodos para conversão e
 * sobrecarregar operadores para possibilitar a comparação de CPF´s.
*/

class CPF {

public:

    CPF(unsigned long long int cpf) : cpf(cpf) {}

    /**
     * Aqui converto uma string CFP para unsigned long long int.
    */

    static unsigned long long int ulli(std::string cpf) {

        cpf.erase(remove(cpf.begin(), cpf.end(), '.'), cpf.end());
        cpf.erase(remove(cpf.begin(), cpf.end(), '-'), cpf.end());

        unsigned long long int converted_cpf = static_cast<unsigned long long int>(std::stoll(cpf));

        return converted_cpf;
    }

    /**
     * Sobrecarregando o operador << para retornar o CPF formatado corretamente.
    */

    friend std::ostream& operator<<(std::ostream& output, const CPF& cpf) {
        std::string str_cpf = std::to_string(cpf.getCPF());

        output << str_cpf.substr(0, 3) << "." << str_cpf.substr(3, 3) << "."
           << str_cpf.substr(6, 3) << "-" << str_cpf.substr(9, 2);

        return output;
    }

    /**
     * Sobrecarga de operadores de comparação.
    */

    bool operator==(const CPF& cpf) const {
        return this->cpf == cpf.getCPF();
    }

    bool operator<(const CPF& cpf) const {
        return this->cpf < cpf.getCPF();
    }
    bool operator>(const CPF& cpf) const {
        return this->cpf > cpf.getCPF();
    }

    bool operator<=(const CPF& cpf) const {
        return this->cpf <= cpf.getCPF();
    }
    bool operator>=(const CPF& cpf) const {
        return this->cpf >= cpf.getCPF();
    }

    unsigned long long int getCPF() const { return cpf; }

private:

/**
 * Um adendo importnte: Técnicamente o CPF não pode ser armazenado como um inteiro, pois o mesmo
 * pode começar com 0, e o 0 é ignorado quando armazenado como inteiro, o que caracteriza
 * um valor octal (números que começam em 0 e possuem apenas os dígitos de 0 a 7).
*/

    unsigned long long int cpf;

};

#endif