#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

private:
    int _rawBits;
    static int const _fracBits;

public:
    Fixed();
    Fixed( int const nb );
    Fixed( float const nb );
    Fixed ( const Fixed &other );
    Fixed &operator=( Fixed const &other );
    ~Fixed();

    int getRawBits() const;
    void    setRawBits( int const raw );

    int toInt() const;
    float toFloat() const;
};

std::ostream &operator<<( std::ostream &o, const Fixed &f );

#endif