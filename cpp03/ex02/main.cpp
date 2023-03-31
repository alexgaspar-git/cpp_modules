#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

    FragTrap fragtrap;
	FragTrap fragtrap2 (fragtrap);
	fragtrap.attack("bird");
	fragtrap.takeDamage(5);
	for (int i = 0; i < 10; i++) {
		fragtrap.beRepaired(10);
	}
	fragtrap.attack("bird");
	fragtrap.takeDamage(200);
	fragtrap.beRepaired(10);
	fragtrap2.attack("bird");
	fragtrap2.highFivesGuys();
	fragtrap2 = fragtrap;
	fragtrap2.attack("bird");
	fragtrap2.highFivesGuys();

    return 0;
}