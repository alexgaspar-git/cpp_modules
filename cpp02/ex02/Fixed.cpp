#include "Fixed.hpp"

int const Fixed::_fracBits = 8;

Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed( int const nb ) : _rawBits( nb << _fracBits ) {}

Fixed::Fixed( float const nb ) : _rawBits( roundf(nb * (1 << _fracBits)) ) {}

Fixed::Fixed( Fixed const &other ) : _rawBits( other._rawBits ) {}

Fixed &Fixed::operator=( Fixed const &other ) {
    _rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

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

bool Fixed::operator>( Fixed const &other ) const {
    return _rawBits > other._rawBits;
}

bool Fixed::operator<( Fixed const &other ) const {
    return _rawBits < other._rawBits;
}

bool Fixed::operator>=( Fixed const &other ) const {
    return _rawBits >= other._rawBits;
}

bool Fixed::operator<=( Fixed const &other ) const {
    return _rawBits <= other._rawBits;
}

bool Fixed::operator==( Fixed const &other ) const {
    return _rawBits == other._rawBits;
}

bool Fixed::operator!=( Fixed const &other ) const {
    return _rawBits != other._rawBits;
}

Fixed Fixed::operator+( Fixed const &other ) const {
    return Fixed( toFloat() + other.toFloat() );
}

Fixed Fixed::operator-( Fixed const &other ) const {
    return Fixed( toFloat() - other.toFloat() );
}

Fixed Fixed::operator*( Fixed const &other ) const {
    return Fixed( toFloat() * other.toFloat() );
}

Fixed Fixed::operator/( Fixed const &other ) const {
    return Fixed( toFloat() / other.toFloat() );
}

Fixed Fixed::operator++() {
    _rawBits++;
    return *this;
}

Fixed Fixed::operator--() {
    _rawBits--;
    return *this;
}

Fixed Fixed::operator++( int ) {
    Fixed copy( *this );
    _rawBits++;
    return copy;
}

Fixed Fixed::operator--( int ) {
    Fixed copy( *this );
    _rawBits--;
    return copy;
}

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs) {
	if (lhs < rhs)
		return (lhs);
    return (rhs);
}

Fixed const &Fixed::min(Fixed const &lhs, Fixed const &rhs) {
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs) {
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

std::ostream &operator<<( std::ostream &o, const Fixed &f ) {
    o << f.toFloat();
    return o;
}
