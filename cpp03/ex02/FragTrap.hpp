#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap( void );
        FragTrap( const std::string &name );
        FragTrap( const FragTrap &other );
        ~FragTrap();

        FragTrap &operator=( const FragTrap &other );

        void attack( const std::string &target );
        void highFivesGuys(void);
};

#endif
