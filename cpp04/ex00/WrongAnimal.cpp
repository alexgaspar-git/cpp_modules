#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Mollusk") {
    std::cout << "Default WrongAnimal Constructor has been called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
    std::cout << "WrongAnimal " << _type << "has been created via copy constructor." << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal " << _type << " has been destroyed." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    _type = other._type;
    std::cout << "WrongAnimal " << _type << " has been created via assignment constructor." << std::endl;
    return *this;
}

std::string WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::makeSound() const {
    std::cout << "rawr" << std::endl;
};
