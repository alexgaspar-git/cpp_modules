#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :  _name("Defaultman"),
                        _hitPoints(100),
                        _energyPoints(50),
                        _attackDamage(20)
{
    std::cout << "Default ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::ClapTrap( const std::string &name ) : _name(name),
                                                _hitPoints(100),
                                                _energyPoints(50),
                                                _attackDamage(20)
{
    std::cout << "ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other ) :   _name(other._name),
                                                _hitPoints(other._hitPoints),
                                                _energyPoints(other._energyPoints),
                                                _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << _name << " has been copied via copy constructor." << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " has been destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &other ) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "ClapTrap " << _name << " has been copied via assignment operator." << std::endl;
    return *this;
}

void ClapTrap::attack( const std::string &target) {
    if (_energyPoints > 0) {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " damage." << std::endl;
    }
    else {
        std::cout << "ClapTrap " << _name << " has no energy." << std::endl;
    }
}

void ClapTrap::takeDamage( unsigned int amount ) {
    if (_hitPoints > 0 && amount < _hitPoints) {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " has been damaged for " << amount << " hit points." << std::endl;
    }
    else if (amount >= _hitPoints && _hitPoints > 0) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " has been damaged for " << amount << " hit points and killed." << std::endl;
    }
    else {
        std::cout << "ClapTrap " << _name << " is no longer with us..." << std::endl;
    }
}

void ClapTrap::beRepaired( unsigned int amount ) {
    if (_hitPoints > 0) {
        if (_energyPoints > 0) {
            _hitPoints += amount;
            _energyPoints--;
            std::cout << "ClapTrap " << _name << " has been healed for " << amount << " hit points." << std::endl;
        }
        else {
            std::cout << "ClapTrap " << _name << " is out of energy." << std::endl;
        }
    }
    else {
        std::cout << "ClapTrap " << _name << " is no longer with us..." << std::endl;
    }
}