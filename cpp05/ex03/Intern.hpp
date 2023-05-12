#ifndef INTERN_HPP
#define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
private:

public:
    Intern();
    Intern(Intern const &other);
    Intern &operator=(Intern const &other);
    ~Intern();

    class FormNotFoundException : public std::exception {
        virtual const char *what() const throw();
    };

    int get_form(std::string const &form) const;
    AForm *makeForm(std::string const &form, std::string const &name) const;
};

#endif