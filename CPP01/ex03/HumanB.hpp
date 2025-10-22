/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:41:02 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/12 02:28:34 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB{
	private:
	Weapon *hB_weapon;
	std::string name;

	public:
	void	attack();
	void	setWeapon(Weapon &tbset);
	HumanB(std::string name, Weapon *type);
	HumanB(std::string name);
	~HumanB();
};

#endif