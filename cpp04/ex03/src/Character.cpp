#include "Character.hpp"

Character::Character(std::string const &name) : _name(name) {
    for (int i = 0; i < MAX_MATERIA; ++i) {
        _inventory[i] = NULL;
    }
}

Character::~Character() {
    for (int i = 0; i < MAX_MATERIA; ++i) {
        if (_inventory[i] != NULL) {
            delete _inventory[i];
        }
    }
}

Character::Character(const Character &other) {
    _name = other._name;
    for (int i = 0; i < MAX_MATERIA; ++i) {
        if (other._inventory[i] != NULL) {
            _inventory[i] = other._inventory[i]->clone();
        } else {
            _inventory[i] = NULL;
        }
    }
}

Character &Character::operator=(const Character &other) {
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < MAX_MATERIA; ++i) {
            if (_inventory[i] != NULL) {
                delete _inventory[i];
            }
            if (other._inventory[i] != NULL) {
                _inventory[i] = other._inventory[i]->clone();
            } else {
                _inventory[i] = NULL;
            }
        }
    }
    return *this;
}

std::string const &Character::getName() const {
    return _name;
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < MAX_MATERIA; ++i) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < MAX_MATERIA && _inventory[idx] != NULL) {
        _inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < MAX_MATERIA && _inventory[idx] != NULL) {
        _inventory[idx]->use(target);
    }
}
