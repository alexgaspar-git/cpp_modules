#include "Cat.hpp"
#include "Dog.hpp"

int	main() {

	Animal *animal[10];

	for (int i = 0; i < 5; i++) {
		std::cout << "[" << i + 1 << "] "; 
		animal[i] = new Dog;
		animal[i]->makeSound();
		std::cout << "----------------------" << std::endl;
	}
	for (int i = 5; i < 10; i++) {
		std::cout << "[" << i + 1 << "] "; 
		animal[i] = new Cat;
		animal[i]->makeSound();
		std::cout << "----------------------" << std::endl;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << "[" << i + 1 << "] "; 
		delete animal[i];
		std::cout << "----------------------" << std::endl; 
	}

	return 0;
}