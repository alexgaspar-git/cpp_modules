#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {

private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    ClapTrap( void );
    ClapTrap( const std::string &name );
    ClapTrap( ClapTrap const &other );
    ~ClapTrap();

    ClapTrap &operator=( const ClapTrap &other );

    void attack( const std::string &target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );

};

#endif