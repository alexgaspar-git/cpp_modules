#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &other) {
    (void)other;
}

Intern &Intern::operator=(Intern const &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

const char *Intern::FormNotFoundException::what() const throw() {
    return "form type does not exist";
}

int Intern::get_form(std::string const &form) const {
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3; i++) {
        if (form == forms[i]) 
            return i;
    }
    return -1;
}

AForm *Intern::makeForm(std::string const &form, std::string const &name) const {
    int i = get_form(form);

    switch (i) {
        case 0:
            return new ShrubberyCreationForm(name);
        case 1:
            return new RobotomyRequestForm(name);
        case 2:
            return new PresidentialPardonForm(name);
        default:
            throw FormNotFoundException();
    }
}