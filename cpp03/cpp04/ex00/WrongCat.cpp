#include "WrongCat.hpp"

WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << "WrongCat has been created." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << "WrongCat has been created via copy constructor." << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat has been destroyed." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    WrongAnimal::operator=(other);
    std::cout << "WrongCat has been created via assignment operator." << std::endl;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "me-ow" << std::endl;
}
