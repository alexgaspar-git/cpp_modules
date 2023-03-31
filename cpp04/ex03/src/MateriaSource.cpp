#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _nLearnedMaterias(0) {
    for (int i = 0; i < MAX_MATERIA; i++) {
        _learnedMaterias[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < _nLearnedMaterias; i++) {
        delete _learnedMaterias[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) : _nLearnedMaterias(0)
{
    for (int i = 0; i < MAX_MATERIA; i++) {
        _learnedMaterias[i] = NULL;
    }
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        for (int i = 0; i < _nLearnedMaterias; i++) {
            delete _learnedMaterias[i];
        }
        _nLearnedMaterias = 0;
        for (int i = 0; i < other._nLearnedMaterias; i++) {
            learnMateria(other._learnedMaterias[i]->clone());
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
    if (_nLearnedMaterias >= MAX_MATERIA || m == NULL) {
        return;
    }
    _learnedMaterias[_nLearnedMaterias] = m;
    _nLearnedMaterias++;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < _nLearnedMaterias; i++) {
        if (_learnedMaterias[i]->getType() == type) {
            return _learnedMaterias[i]->clone();
        }
    }
    return NULL;
}
