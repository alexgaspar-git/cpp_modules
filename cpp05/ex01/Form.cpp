#include "Form.hpp"

Form::Form() :
    _name("Form"), _isSigned(false), _minGradeSign(75), _minGradeExec(75) {
    check_grade();
}

Form::Form(const Form &other) :
    _name(other._name), _isSigned(other._isSigned), _minGradeSign(other._minGradeSign), _minGradeExec(other._minGradeExec) {
    check_grade();
}

Form::~Form() {}

Form &Form::operator=(const Form &other) {
    _isSigned = other._isSigned;
    return *this;
}

Form::Form(const std::string name, const unsigned int minGradeSign, const unsigned int minGradeExec) :
    _name(name), _isSigned(false), _minGradeSign(minGradeSign), _minGradeExec(minGradeExec) {
    check_grade();
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() <= _minGradeSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

std::string const Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _isSigned;
}

unsigned int Form::getMinGradeSign() const {
    return _minGradeSign;
}

unsigned int Form::getMinGradeExec() const {
    return _minGradeExec;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "grade too low";
}

void Form::check_grade() {
    if (_minGradeSign > 150 || _minGradeExec > 150)
        throw GradeTooLowException();
    if (_minGradeSign < 1 || _minGradeExec < 1)
        throw GradeTooHighException();
}

std::ostream &operator<<(std::ostream &output, Form const &obj) {
    output << "name: " << obj.getName() << std::endl
    << "signed: " << obj.getSigned() << std::endl
    << "min grade to sign: " << obj.getMinGradeSign() << std::endl
    << "min grade to exec: " << obj.getMinGradeExec() << std::endl;
    return output;
}
