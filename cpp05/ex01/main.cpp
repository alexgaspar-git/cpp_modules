#include "Bureaucrat.hpp"

int main() {

    try {
        std::cout << "Try 1: ";
        Bureaucrat bill("Billy", 1);
        bill.promote();
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Try 2: ";
        Bureaucrat jeff("Jeff", 150);
        jeff.demote();
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Try 3: ";
        Bureaucrat bob("Bob", 75);
        for (int i = 0; i < 50; i++) {
            bob.promote();
            // bob.demote();
        }
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}