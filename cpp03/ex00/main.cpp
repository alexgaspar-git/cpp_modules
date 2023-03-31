#include "ClapTrap.hpp"

int main() {

    ClapTrap empty;
    ClapTrap jimmy("Jimmy");
    ClapTrap test(jimmy);
    ClapTrap timmy("Timmy");

    empty = timmy;
    
    empty.attack("Timmy");
    timmy.takeDamage(9);
    timmy.beRepaired(999);
    for (int i = 0; i < 10; i++) {
        empty.attack("Timmy");
    }
    timmy.takeDamage(11);
    timmy.attack("Jimmy");
    empty.takeDamage(999);
    empty.beRepaired(50);

    return 0;
}