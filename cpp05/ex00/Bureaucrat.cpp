#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, unsigned int grade) : _name(name), _grade(grade) {
    check_grade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    _grade = other._grade;
    return *this;
}

std::string Bureaucrat::getName() const {
    return _name;
}

unsigned int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::promote() {
    _grade--;
    check_grade();
}

void Bureaucrat::demote() {
    _grade++;
    check_grade();
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &obj) {
    output << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return output;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "grade too low";
}

void Bureaucrat::check_grade() {
    if (_grade > 150) {
        throw GradeTooLowException();
    }
    if (_grade < 1) {
        throw GradeTooHighException();
    }
}