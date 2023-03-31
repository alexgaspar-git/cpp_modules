#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
	_name = "DiamondTrap";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "Default DiamondTrap " << _name << " created." << std::endl;
}

DiamondTrap::DiamondTrap( const std::string &name ) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
    _name = name;
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " created." << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    std::cout << "DiamondTrap " << _name << " has been copied via copy constructor." << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " has been destroyed." << std::endl;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &other ) {
    ClapTrap::operator=(other);
    std::cout << "DiamondTrap " << _name << " has been created via assignment operator." << std::endl;
    return *this;
}

void DiamondTrap::attack( const std::string &target ) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}