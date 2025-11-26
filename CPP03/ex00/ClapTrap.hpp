/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:20:10 by rpadasia          #+#    #+#             */
/*   Updated: 2025/11/25 20:37:04 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap
{
	private:
	std::string name;
	int			hit_points;
	int			energy_points;
	int			attack_damage;

	public:
	ClapTrap();
	ClapTrap(std::string tbname);
	ClapTrap(const ClapTrap& variables);
	ClapTrap& operator=(const ClapTrap& variables);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void displayStats(void);
};