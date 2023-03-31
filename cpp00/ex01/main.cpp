#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main() {

	std::string line;
	PhoneBook phoneBook;

	while (1) {
		std::cout << "Commands: ADD | SEARCH | EXIT > ";
		std::getline(std::cin, line);
		if (line == "ADD")
			phoneBook.addContact();
		else if (line == "SEARCH")
			phoneBook.searchContact();
		else if (line == "EXIT")
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}