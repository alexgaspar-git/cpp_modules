#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap") {
    std::cout << "Default FragTrap " << _name << " created." << std::endl;
}

FragTrap::FragTrap( const std::string &name ) : ClapTrap(name) {
    std::cout << "FragTrap " << _name << " created." << std::endl;
}

FragTrap::FragTrap( const FragTrap &other ) : ClapTrap(other) {
    std::cout << "FragTrap " << _name << " has been copied via copy constructor." << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " has been destroyed." << std::endl;
}

FragTrap &FragTrap::operator=( const FragTrap &other ) {
    ClapTrap::operator=(other);
    std::cout << "FragTrap " << _name << " has been copied via assignment operator." << std::endl;
    return *this;
}

void FragTrap::attack( const std::string &target ) {
    if (_energyPoints > 0) {
        _energyPoints--;
        std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " damage." << std::endl;
    }
    else {
        std::cout << "FragTrap " << _name << " has no energy." << std::endl;
    }
}

void FragTrap::highFivesGuys() {
	if (_hitPoints > 0)
    	std::cout << "FragTrap " << _name << " is requesting a high five." << std::endl;
	else
		std::cout << "FragTrap " << _name << " is no longer with us..." << std::endl;
}
