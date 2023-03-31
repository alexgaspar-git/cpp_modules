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

    bool operator>( Fixed const &other ) const;
    bool operator<( Fixed const &other ) const;
    bool operator>=( Fixed const &other ) const;
    bool operator<=( Fixed const &other ) const;
    bool operator==( Fixed const &other ) const;
    bool operator!=( Fixed const &other ) const;

    Fixed operator+ ( Fixed const &other ) const; 
    Fixed operator- ( Fixed const &other ) const; 
    Fixed operator* ( Fixed const &other ) const; 
    Fixed operator/ ( Fixed const &other ) const; 

    Fixed operator++ ( void ); 
    Fixed operator-- ( void ); 
    Fixed operator++ ( int nb ); 
    Fixed operator-- ( int nb ); 
    
    static Fixed &min( Fixed &lhs, Fixed &rhs );
    static Fixed const &min( Fixed const &lhs, Fixed const &rhs );
    static Fixed &max( Fixed &lhs, Fixed &rhs );
    static Fixed const &max( Fixed const &lhs, Fixed const &rhs );
};

std::ostream &operator<<( std::ostream &o, const Fixed &f );

#endif