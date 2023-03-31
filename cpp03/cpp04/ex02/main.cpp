#include "Cat.hpp"
#include "Dog.hpp"

int	main() {

	// AAnimal *mittens = new AAnimal();

	AAnimal *mittens = new Cat();
	AAnimal *rex = new Dog();

	mittens->makeSound();
	rex->makeSound();

	delete mittens;
	delete rex;

	return 0;
}