#include "Form.hpp"

Form::Form() : _name("Form"), _isSigned(false), _minGradeSign(75), _minGradeExec(75) {}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _minGradeSign(other.minGradeSign), _minGradeExec(other.minGradeExec) {}

Form::~Form() {}

Form &Form::operator=(const &Form &other) {
    _name = other._name;
    _isSigned = other._isSigned;
    return *this;
}

Form::Form(const std::string name, const unsigned int minGradeSign, const unsigned int minGradeExec) : _name(name), _isSigned(false), _minGradeSign(minGradeSign), _minGradeExec(minGradeExec) {}

void Form::beSigned()