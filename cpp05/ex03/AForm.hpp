#ifndef AFORM_HPP
#define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private:
    const std::string _name;
    bool _isSigned;
    const unsigned int _minGradeSign;
    const unsigned int _minGradeExec;

public:
    AForm();
    AForm(const AForm &other);
    virtual ~AForm() = 0;
    AForm &operator=(const AForm &other);

    AForm(const std::string name, const unsigned int minGradeSign, const unsigned int minGradeExec);
    void beSigned(const Bureaucrat &b);
    std::string const getName() const;
    bool getSigned() const;
    unsigned int getMinGradeSign() const;
    unsigned int getMinGradeExec() const;
    void check_grade() const;
    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };
    class FormUnsignedException : public std::exception {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &output, AForm const &obj);

#endif