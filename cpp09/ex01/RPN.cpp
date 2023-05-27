#include "RPN.hpp"

// #############################

RPN::RPN() {};

RPN::RPN(const RPN &other) {
    (void)other;
}

RPN::~RPN() {};

RPN &RPN::operator=(const RPN &other) {
    (void)other;
    return *this;
}

// #############################

bool isOperator(const char &c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

static int execOp(char sign, int op1, int op2) {
    switch (sign) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
    }
    return INT_MIN;
}

void RPN::execRPN(const char *arg) {
    int i = 0;
    int digits = 0;
    int op1, op2;
    while (arg[i]) {
        if (isOperator(arg[i])) {
            if (_stack.size() < 2)
                throw TooManyOperatorsException();
            digits = 0;
            op2 = _stack.top();
            _stack.pop();
            op1 = _stack.top();
            _stack.pop();
            if (arg[i] == '/' && op2 == 0)
                throw DivisionByZeroException();
            _result = execOp(arg[i], op1, op2);
            _stack.push(_result);
            i++;
        } else if (isdigit(arg[i])) {
            digits++;
            if (digits > 1)
                throw NumberTooBigException();
            _stack.push(arg[i] - '0');
            i++;
        } else if (arg[i] == ' ') {
            digits = 0;
            i++;
        } else {
            throw InvalidCharacterException();
        }
    }
    if (_stack.size() != 1) {
        throw NotEnoughOperatorsException();
    }
}

int RPN::getResult() {
    return _result;
}

const char *RPN::InvalidCharacterException::what() const throw() {
    return "invalid character detected, only 0-9 and +-*/";
}

const char *RPN::NumberTooBigException::what() const throw() {
    return "please only use values between 0 and 9";
}

const char *RPN::TooManyOperatorsException::what() const throw() {
    return "there are too many operators";
}

const char *RPN::DivisionByZeroException::what() const throw() {
    return "nice try";
}

const char *RPN::NotEnoughOperatorsException::what() const throw() {
    return "not enough operators";
}