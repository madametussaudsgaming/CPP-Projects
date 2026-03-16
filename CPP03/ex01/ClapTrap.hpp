/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:20:10 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/08 17:15:19 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_CLAPTRAP_HPP
# define EX01_CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
	std::string name;
	unsigned int			hit_points;
	int			energy_points;
	int			attack_damage;

	public:
	ClapTrap();
	ClapTrap(std::string tbname);
	ClapTrap(const ClapTrap& variables);
	ClapTrap& operator=(const ClapTrap& variables);
	virtual ~ClapTrap();

	virtual void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);
	void displayStats(void);
};

#endif