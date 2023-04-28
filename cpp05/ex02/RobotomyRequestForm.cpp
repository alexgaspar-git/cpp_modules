#include "RobotomyRequestForm.hpp"

int const RobotomyRequestForm::_gradeSign    = 72;
int const RobotomyRequestForm::_gradeExec = 45;

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", _gradeSign, _gradeExec) {}
RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", _gradeSign, _gradeExec), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :  AForm(other), _target(other._target) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    AForm::operator=(other);
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (getSigned() == false)
        throw (AForm::FormUnsignedException());
    if (executor.getGrade() > _gradeExec)
        throw (AForm::GradeTooLowException());
    std::cout << "*drilling noise*" << std::endl;
    if (std::rand() % 2) {
        std::cout << _target << " has been robotomized" << std::endl;
    } else {
        std::cout << _target << " hasn't been robotomized" << std::endl;
    }
}
