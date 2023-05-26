#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <exception>

typedef struct Date {
    int year;
    int month;
    int day;

    Date(int y, int m, int d);
    Date operator--(int);
} t_date;

class BitcoinExchange {
private:
    std::map<std::string, std::pair<double, bool> > _data;
    std::string _date;
    double _rateVal;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &other);

    bool parseRate(std::string &line);
    bool parseDate(std::string &line);
    void parseLine(std::string &line);
    std::string getLowestDate(std::string &date);
    void calculateValue(std::ifstream &input);

    class InvalidDateException : public std::exception {
        const char *what() const throw();
    };

    class InvalidRateValueException : public std::exception {
        const char *what() const throw();
    };

    class InvalidFormatException : public std::exception {
        const char *what() const throw();
    };
};


#endif