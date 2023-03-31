#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;

	MateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	MateriaSource* src3 = new MateriaSource();
	*src3 = *src2;
	me = new Character("me");
	tmp = src3->createMateria("ice");
	me->equip(tmp);
	tmp = src3->createMateria("cure");
	me->equip(tmp);
	bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src2;
	delete src3;

	return 0;
}