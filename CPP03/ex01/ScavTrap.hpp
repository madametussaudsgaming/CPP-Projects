/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:14:31 by rpadasia          #+#    #+#             */
/*   Updated: 2025/11/25 13:33:43 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

 class ScavTrap: public ClapTrap
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
		void guardGate();
 };
