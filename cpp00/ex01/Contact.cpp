#include "Contact.hpp"

static bool isValid(const std::string& str) {
	if (str.empty())
		return false;
    for (std::string::size_type i = 0; i < str.length(); i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            return true;
        }
    }
    return false;
}

Contact	Contact::getInfo() {

	Contact contact;

	while (!isValid(contact._firstName)) {
		std::cout << "First name: ";
		std::getline(std::cin, contact._firstName);	
	}
	
	while (!isValid(contact._lastName)) {
		std::cout << "Last name: ";
		std::getline(std::cin, contact._lastName);
	}

	while (!isValid(contact._nickName)) {
		std::cout << "Nick name: ";
		std::getline(std::cin, contact._nickName);
	}

	while (!isValid(contact._phoneNumber)) {
		std::cout << "Phone number: ";
		std::getline(std::cin, contact._phoneNumber);
	}

	while (!isValid(contact._darkestSecret)) {
		std::cout << "Darkest secret: ";
		std::getline(std::cin, contact._darkestSecret);
	}

	return contact;
}

void	Contact::showInfo() {
	if (this->_firstName.empty())
	{
		std::cout << "Index is empty." << std::endl;
		return ;
	}
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nick name: " << this->_nickName << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}

std::string Contact::truncateString(const std::string& str) const {

    std::string trunc;

    if (str.length() > 10) {
        trunc = str;
        trunc.resize(10);
        trunc.replace(9, 1, ".");
    } else {
        trunc = str;
    }
    return trunc;
}

void Contact::showShort() {
	std::cout << std::setw(10) << std::right << truncateString(this->_firstName) << "|";
    std::cout << std::setw(10) << std::right << truncateString(this->_lastName) << "|";
    std::cout << std::setw(10) << std::right << truncateString(this->_nickName) << std::endl;
}
