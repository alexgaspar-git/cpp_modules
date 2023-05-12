#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat {

private:
    const std::string _name;
    unsigned int _grade;
public:
    Bureaucrat(std::string const &name, unsigned int grade);

    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &other);

    std::string getName() const;
    unsigned int getGrade() const;

    void promote();
    void demote();

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

    void check_grade();
    bool signForm(AForm &f);
    void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &obj);

#endif