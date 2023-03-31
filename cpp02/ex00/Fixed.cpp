#include "Fixed.hpp"

int const Fixed::_fracBits = 8;

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &other ) : _rawBits( other._rawBits ) {
    std::cout << "Copy constructor" << std::endl;
}

Fixed &Fixed::operator=( Fixed const &other ) {
    std::cout << "Copy assignment operator called" << std::endl;
    _rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const { 
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void    Fixed::setRawBits( int const raw ) {
    _rawBits = raw;
}