/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:28:35 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/12 02:31:46 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{
	private:
	std::string type;

	public:
	const std::string &getType() const;
	void		setType(const std::string &newtype);
	Weapon();
	Weapon(const std::string &tbtype);
	~Weapon();
};

#endif