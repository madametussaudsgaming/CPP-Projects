/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:59:11 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/12 02:15:46 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA{
	private:
	Weapon &hA_weapon;
	std::string name;

	public:
	void	attack();
	HumanA(std::string tbname, Weapon& type);
	~HumanA();
};

#endif