#include "Fixed.hpp"

int const Fixed::_fracBits = 8;

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const nb ) : _rawBits( nb << _fracBits ) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const nb ) : _rawBits( roundf(nb * (1 << _fracBits)) ) {
    std::cout << "Float constructor called" << std::endl;
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
    return _rawBits;
}

void    Fixed::setRawBits( int const raw ) {
    _rawBits = raw;
}

int Fixed::toInt() const {
    return _rawBits >> _fracBits;
}

float Fixed::toFloat() const {
    return (float)_rawBits / (1 << _fracBits);
}

std::ostream &operator<<( std::ostream &o, const Fixed &f ) {
    o << f.toFloat();
    return o;
}
