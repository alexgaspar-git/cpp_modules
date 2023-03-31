#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed {

private:
    int _rawBits;
    static int const _fracBits;

public:
    Fixed();
    Fixed ( const Fixed &other );
    Fixed &operator=( Fixed const &other );
    ~Fixed();

    int getRawBits() const;
    void    setRawBits( int const raw );
};

#endif