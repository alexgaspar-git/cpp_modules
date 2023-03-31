#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Mollusk") {
    std::cout << "Default AAnimal Constructor has been called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type) {
    std::cout << "AAnimal " << _type << " has been created via copy constructor." << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal " << _type << " has been destroyed." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
    _type = other._type;
    std::cout << "AAnimal " << _type << " has been created via assignment constructor." << std::endl;
    return *this;
}

std::string AAnimal::getType() const {
    return _type;
}
