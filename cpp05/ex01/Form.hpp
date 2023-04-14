#ifndef FORM_HPP
#define FORM_HPP

# include "Bureaucrat.hpp"

class Form {

private:
    const std::string _name;
    bool _isSigned;
    const unsigned int _minGradeSign;
    const unsigned int _minGradeExec;

public:
    //OCC
    Form();
    Form(const Form &other);
    ~Form();
    Form &operator=(const Form &other);

    Form(const std::string name, const unsigned int minGradeSign, const unsigned int minGradeExec);
    void beSigned(const Bureacrat &b);
    const std::string getName();
    const bool getSigned();
    const unsigned int getMinGradeSign();
    const unsigned int getMinGradeExec();

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    }
    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    }
};

std::ostream &operator<<(std::ostream &output, const Form &obj);

#endif