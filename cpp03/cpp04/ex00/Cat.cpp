#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << "Cat has been created." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat has been created via copy constructor." << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat has been destroyed." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    Animal::operator=(other);
    std::cout << "Cat has been created via assignment operator." << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meowww" << std::endl;
}
