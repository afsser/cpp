#include "ClapTrap.hpp"

#include <cstdlib>

int	main(void) {
	ClapTrap ed = ClapTrap("Ed");
	ClapTrap rob = ClapTrap("Rob");
	ClapTrap rud = ClapTrap("Rud");
	// Rud attacks Ed
	ed.attack(rud.getName());
	// Ed takes damage
	ed.takeDamage(rud.getAtkDmg());

	return (EXIT_SUCCESS);
}