#include "Animal.hpp"

Animal::Animal() : _type("Mollusk") {
    std::cout << "Default Animal Constructor has been called." << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << "Animal " << _type << " has been created via copy constructor." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal " << _type << " has been destroyed." << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    _type = other._type;
    std::cout << "Animal " << _type << " has been created via assignment constructor." << std::endl;
    return *this;
}

std::string Animal::getType() const {
    return _type;
}

void Animal::makeSound() const {
    std::cout << "rawr" << std::endl;
};
