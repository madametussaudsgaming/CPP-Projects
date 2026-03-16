/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:14:31 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/08 17:19:48 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_SCAVPTRAP_HPP
# define EX03_SCAVPTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

 class ScavTrap: virtual public ClapTrap
 {
	private:
		bool guarding_gate;
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &og);
		ScavTrap(std::string name);
		ScavTrap &operator=(const ScavTrap &og);
		virtual ~ScavTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void guardGate();
 };

 #endif