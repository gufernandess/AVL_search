#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>
#include <vector>

class Date {

public:
     Date() = default;
     Date(unsigned short int month, unsigned short int day, unsigned short int year) 
           : month(month), day(day), year(year) {}

    /**
     * Implementei o método to_date para resgatar as datas do CSV (que são strings)
     * para convertê-las em Date, assim tornando possível criar o objeto Person.
    */

    static Date to_date(std::string date_str) {
        std::istringstream str(date_str);
        std::string word;
        std::vector<unsigned short int> date_values;

        while(std::getline(str, word, '/')) {
            date_values.push_back(static_cast<unsigned short int>(std::stoi(word)));
        }

        return Date(date_values[0], date_values[1], date_values[2]);
    }

    // Sobrecarga de operadores (==, >, <, >=, <=).

    bool operator==(const Date& date) const {
    return month == date.month && day == date.day && year == date.year;
}

    bool operator>(const Date& date) const {
        if(year > date.year) return true;

        else if(year == date.year) {
            if(month > date.month) return true;

                else if(month == date.month) {
                if(day > date.day) return true;
            }
        }

        return false;
    }

    bool operator<(const Date& date) const {
        if(year < date.year) return true;

        else if(year == date.year) {
            if(month < date.month) return true;

                else if(month == date.month) {
                if(day < date.day) return true;
            }
        }

        return false;
    }

    bool operator>=(const Date& date) const {
    return !(*this < date);
  }

  bool operator<=(const Date& date) const {
    return (*this == date) || (*this < date);
  }

    unsigned short int getMonth() const { return month; }
    unsigned short int getDay() const { return day; }
    unsigned short int getYear() const { return year; }

private:

    // Decidi usar unsigned short int, visto o tamanho dos dados de mês, dia e ano.

	unsigned short int month;
    unsigned short int day;
    unsigned short int year;
};

/**
 * Sobrecarreguei o operador de saída para Date, assim consigo retornar
 * um objeto Date no formato correto (mm/dd/yyyy).
 * 
 * Além disso, usei algumas verificações para inserir um zero na frente do mês ou ano,
 * caso seja necessário para convergir com o formato proposto (mm/dd/yyyy).
*/

std::ostream& operator<<(std::ostream& output, const Date& date) {
    if(date.getMonth() < 10) output << "0" << date.getMonth();

    else output << date.getMonth();

    output << "/";
    
    if(date.getDay() < 10) output << "0" << date.getDay();

    else output << date.getDay();

    output << "/" << date.getYear();
    
    return output;
}


#endif