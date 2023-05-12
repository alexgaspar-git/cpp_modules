#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    static int const _gradeSign;
    static int const _gradeExec;
    std::string const _target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    void execute (Bureaucrat const &executor) const;
};

#endif