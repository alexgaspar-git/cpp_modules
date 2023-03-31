#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << "Dog has been created." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog has been created via copy constructor." << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog has been destroyed." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    Animal::operator=(other);
    std::cout << "Dog has been created via assignment operator." << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "w00f" << std::endl;
}
