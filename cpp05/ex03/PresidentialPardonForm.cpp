#include "PresidentialPardonForm.hpp"

int const PresidentialPardonForm::_gradeSign = 72;
int const PresidentialPardonForm::_gradeExec = 45;

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", _gradeSign, _gradeExec) {}
PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", _gradeSign, _gradeExec), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :  AForm(other), _target(other._target) {}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    AForm::operator=(other);
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (getSigned() == false)
        throw (AForm::FormUnsignedException());
    if (executor.getGrade() > _gradeExec)
        throw (AForm::GradeTooLowException());
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
