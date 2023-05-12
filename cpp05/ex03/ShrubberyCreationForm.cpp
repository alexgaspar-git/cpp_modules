#include "ShrubberyCreationForm.hpp"

int const ShrubberyCreationForm::_gradeSign    = 145;
int const ShrubberyCreationForm::_gradeExec = 137;
std::string const ShrubberyCreationForm::_ascii
    = "  (ooo ooooo)\n"
      " (ooooo oo0oo)\n"
      "  (oo0o0o0oo)\n"
      "      ||\n"
      "      /|\n"
      "    _/||\\_\n";


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", _gradeSign, _gradeExec) {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", _gradeSign, _gradeExec), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :  AForm(other), _target(other._target) {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    AForm::operator=(other);
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (getSigned() == false)
        throw (AForm::FormUnsignedException());
    else if (executor.getGrade() > _gradeExec)
        throw (AForm::GradeTooLowException());
    else {
        std::ofstream oFile( ( _target + "_shrubbery" ).c_str() );
        if ( !oFile ) {
            throw std::runtime_error( _target + "_shrubbery" + ": unable to open" );
    }
        oFile << _ascii;
        oFile.close();
    }
}
