#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <cctype>
#include <limits.h>
#include <exception>
#include <cstring>

class RPN {
private:
    std::stack<int> _stack;
    int _result;
public:
    RPN(std::string const &string);

    RPN();
    RPN(const RPN &other);
    ~RPN();
    RPN &operator=(const RPN &other);

    void execRPN(const char *arg);
    int getResult();

    class DivisionByZeroException : public std::exception {
        const char *what() const throw();
    };

    class InvalidCharacterException : public std::exception {
        const char *what() const throw();
    };

    class TooManyOperatorsException : public std::exception {
        const char *what() const throw();
    };

    class NumberTooBigException : public std::exception {
        const char *what() const throw();
    };

    class NotEnoughOperatorsException : public std::exception {
        const char *what() const throw();
    };
};

bool isOperator(const char &c);

#endif