/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:20:12 by rpadasia          #+#    #+#             */
/*   Updated: 2025/11/26 16:34:31 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║   EXERCISE 00: Testing ClapTrap        ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	std::cout << "=== ClapTrap Basic Tests ===" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("training dummy");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.displayStats();

	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║   EXERCISE 01: Testing ScavTrap        ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	std::cout << "=== ScavTrap Default Constructor ===" << std::endl;
	ScavTrap scav1;

	std::cout << "\n=== ScavTrap Parameterized Constructor ===" << std::endl;
	ScavTrap scav("Scavvy");
	scav.attack("enemy");
	scav.takeDamage(20);
	scav.beRepaired(10);

	std::cout << "\n=== ScavTrap Special Ability ===" << std::endl;
	scav.guardGate();
	scav.guardGate(); // Try again

	std::cout << "\n=== ScavTrap Copy Constructor ===" << std::endl;
	ScavTrap scav2(scav);
	scav2.attack("another enemy");

	std::cout << "\n=== ScavTrap Assignment Operator ===" << std::endl;
	ScavTrap scav3("Temporary");
	scav3 = scav;
	scav3.attack("yet another enemy");

	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║   EXERCISE 02: Testing FragTrap        ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	std::cout << "=== FragTrap Default Constructor ===" << std::endl;
	FragTrap frag1;

	std::cout << "\n=== FragTrap Parameterized Constructor ===" << std::endl;
	FragTrap frag("Fraggy");
	frag.attack("target");
	frag.takeDamage(40);
	frag.beRepaired(25);

	std::cout << "\n=== FragTrap Special Ability ===" << std::endl;
	frag.highFivesGuys();

	std::cout << "\n=== FragTrap Copy Constructor ===" << std::endl;
	FragTrap frag2(frag);
	frag2.attack("boss");

	std::cout << "\n=== FragTrap Assignment Operator ===" << std::endl;
	FragTrap frag3("TempFrag");
	frag3 = frag;
	frag3.highFivesGuys();

	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║   EXERCISE 03: Testing DiamondTrap     ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	std::cout << "=== DiamondTrap Default Constructor ===" << std::endl;
	DiamondTrap diamond1;
	diamond1.whoAmI();

	std::cout << "\n=== DiamondTrap Parameterized Constructor ===" << std::endl;
	DiamondTrap diamond("Diamondy");
	diamond.whoAmI();

	std::cout << "\n=== DiamondTrap Attack (uses ScavTrap) ===" << std::endl;
	diamond.attack("mega boss");

	std::cout << "\n=== DiamondTrap Stats Verification ===" << std::endl;
	std::cout << "Taking 50 damage..." << std::endl;
	diamond.takeDamage(50);
	std::cout << "Repairing 30 HP..." << std::endl;
	diamond.beRepaired(30);

	std::cout << "\n=== DiamondTrap Copy Constructor ===" << std::endl;
	DiamondTrap diamond2(diamond);
	diamond2.whoAmI();
	diamond2.attack("copy target");

	std::cout << "\n=== DiamondTrap Assignment Operator ===" << std::endl;
	DiamondTrap diamond3("TempDiamond");
	diamond3 = diamond;
	diamond3.whoAmI();
	diamond3.attack("assigned target");

	std::cout << "\n=== DiamondTrap Inherited Abilities ===" << std::endl;
	diamond3.guardGate();  // From ScavTrap
	diamond3.highFivesGuys();  // From FragTrap

	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║   Testing Polymorphism with Pointers   ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	std::cout << "=== Creating Robots via Base Pointer ===" << std::endl;
	ClapTrap* robots[4];
	robots[0] = new ClapTrap("ClapBot");
	robots[1] = new ScavTrap("ScavBot");
	robots[2] = new FragTrap("FragBot");
	robots[3] = new DiamondTrap("DiamondBot");

	std::cout << "\n=== Attacking Through Base Pointers ===" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\nRobot " << i << ":" << std::endl;
		robots[i]->attack("polymorphic target");
	}

	std::cout << "\n=== Cleaning Up Pointers ===" << std::endl;
	for (int i = 0; i < 4; i++)
		delete robots[i];

	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║   Testing Destruction Chain            ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	std::cout << "All objects will now be destroyed..." << std::endl;
	return 0;
}