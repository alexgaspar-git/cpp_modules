#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

	ScavTrap jeff("Jeff");
    ScavTrap guy("Guy");
	ScavTrap slavtrap;
	ScavTrap copy(jeff);

	slavtrap = jeff;
    for (int i = 0; i < 10; i++) {
	    guy.attack("Jeff");
    }
	jeff.takeDamage(99);
	jeff.guardGate();
	jeff.beRepaired(5);
	jeff.takeDamage(6);
	jeff.guardGate();

    return 0;
}