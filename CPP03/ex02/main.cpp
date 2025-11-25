/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:20:12 by rpadasia          #+#    #+#             */
/*   Updated: 2025/11/25 21:32:50 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "=== Testing ClapTrap ===" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("target");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.displayStats();

	std::cout << "\n=== Testing ScavTrap ===" << std::endl;
	ScavTrap scav("Scavvy");
	scav.attack("enemy");
	scav.takeDamage(20);
	scav.beRepaired(20);
	scav.guardGate();
	scav.guardGate(); // Try again to test the already guarding message

	std::cout << "\n=== Testing FragTrap ===" << std::endl;
	FragTrap frag("Faggy");
	frag.attack("enemy");
	frag.takeDamage(30);
	frag.beRepaired(20);
	frag.displayStats();

	std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
	ScavTrap scav2(scav);
	scav2.attack("another enemy");

	std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
	ScavTrap scav3("Temporary");
	scav3 = scav;
	scav3.attack("yet another enemy");

	std::cout << "\n=== Testing Destruction Chain ===" << std::endl;
	return 0;
}