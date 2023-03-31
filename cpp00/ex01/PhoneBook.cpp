#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(-1) {};

void PhoneBook::addContact() {
	Contact contact;

	_index++;
	if (_index > 7)
		_index = 0;
	contact = contact.getInfo();
	_contact[_index] = contact;
}

void	PhoneBook::searchContact() {

	std::string input;
	char	*endptr;
	long	index = 0;

	for (int i = 0; i < 8; i++) {
		std::cout << std::setw(10) << std::right << "[" << i + 1 << "]" << "|";
		_contact[i].showShort();
	}
	while (1) {
		std::cout << "Enter an index number: ";
		std::getline(std::cin, input);
		index = std::strtol(input.c_str(), &endptr, 10);
		if (index > 0 && index < 9 && *endptr == '\0')
			break;
		std::cout << "Invalid input." << std::endl;
	}
	_contact[index - 1].showInfo();
}	