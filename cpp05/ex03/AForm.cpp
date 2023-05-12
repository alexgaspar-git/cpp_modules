#include "AForm.hpp"

AForm::AForm() :
    _name("AForm"), _isSigned(false), _minGradeSign(75), _minGradeExec(75) {
    check_grade();
}

AForm::AForm(const AForm &other) :
    _name(other._name), _isSigned(other._isSigned), _minGradeSign(other._minGradeSign), _minGradeExec(other._minGradeExec) {
    check_grade();
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
    _isSigned = other._isSigned;
    return *this;
}

AForm::AForm(const std::string name, const unsigned int minGradeSign, const unsigned int minGradeExec) :
    _name(name), _isSigned(false), _minGradeSign(minGradeSign), _minGradeExec(minGradeExec) {
    check_grade();
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() <= _minGradeSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

std::string const AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _isSigned;
}

unsigned int AForm::getMinGradeSign() const {
    return _minGradeSign;
}

unsigned int AForm::getMinGradeExec() const {
    return _minGradeExec;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "grade too low";
}

const char *AForm::FormUnsignedException::what() const throw() {
    return "form unsigned";
}

void AForm::check_grade() const {
    if (_minGradeSign > 150 || _minGradeExec > 150)
        throw GradeTooLowException();
    if (_minGradeSign < 1 || _minGradeExec < 1)
        throw GradeTooHighException();
}

std::ostream &operator<<(std::ostream &output, AForm const &obj) {
    output << "name: " << obj.getName() << std::endl
    << "signed: " << obj.getSigned() << std::endl
    << "min grade to sign: " << obj.getMinGradeSign() << std::endl
    << "min grade to exec: " << obj.getMinGradeExec() << std::endl;
    return output;
}
