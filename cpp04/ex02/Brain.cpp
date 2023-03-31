#include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; i++) {
        _ideas[i] = "empty";
    }
    std::cout << "Brain constructed." << std::endl;
}

Brain::Brain(const Brain &other) {
    for (int i = 0; i < 100; i++) {
        _ideas[i] = other._ideas[i];
    }
    std::cout << "Brain copy constructed." << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
    for (int i = 0; i < 100; i++) {
        _ideas[i] = other._ideas[i];
    }
    std::cout << "Brain copy operator assigned." << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destroyed." << std::endl;
}