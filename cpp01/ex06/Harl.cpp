#include "Harl.hpp"

std::string Harl::_levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

void Harl::debug() {
	std::cout
		<< "I love having extra bacon for my "
		   "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You "
				 "didn't put "
				 "enough bacon in my burger! If you did, I wouldn't be asking "
				 "for more!"
			  << std::endl;
}

void Harl::warning() {
	std::cout
		<< "I think I deserve to have some extra bacon for free. I've been "
		   "coming for years whereas you started working here since last month."
		<< std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

Harl::Harl() {
    _functions[0] = &Harl::debug;
    _functions[1] = &Harl::info; 
    _functions[2] = &Harl::warning; 
    _functions[3] = &Harl::error; 
}

int Harl::get_level_index( std::string const &level ) {
    for ( int i = 0; i < 4; i++ ) {
        if (level == _levels[i]) { 
			return i;
		}
    }
    return -1;
}

void Harl::complainFilter(std::string const &level) {
    switch (get_level_index(level)) {
    case 0:
        debug();
    case 1:
        info();
    case 2:
        warning();
    case 3:
        error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]"
                  << std::endl;
    }
}
