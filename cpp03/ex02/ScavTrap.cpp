#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
    std::cout << "Default ScavTrap " << _name << " created." << std::endl;

}

ScavTrap::ScavTrap( const std::string &name ) : ClapTrap(name) {
    std::cout << "ScavTrap " << _name << " created." << std::endl;

}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other) {
    std::cout << "ScavTrap " << _name << " has been copied via copy constructor." << std::endl;

}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " has been destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &other ) {
    ClapTrap::operator=(other);
    std::cout << "ScavTrap " << _name << " has been copied via assignment operator." << std::endl;
    return *this;
}

void ScavTrap::attack( const std::string &target ) {
    if (_energyPoints > 0) {
        _energyPoints--;
        std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " damage." << std::endl;
    }
    else {
        std::cout << "ScavTrap " << _name << " has no energy." << std::endl;
    }
}

void ScavTrap::guardGate() {
	if (_hitPoints > 0)
    	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode!" << std::endl;
	else
		std::cout << "Scavtrap " << _name << " is no longer with us..." << std::endl;
}
