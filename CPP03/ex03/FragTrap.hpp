/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:04:54 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/08 17:19:30 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_FRAGPTRAP_HPP
# define EX03_FRAGPTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	private:
	public:
		FragTrap();
		FragTrap(const FragTrap &og);
		FragTrap(std::string name);
		FragTrap &operator=(const FragTrap &og);
		virtual ~FragTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void highFivesGuys(void);
};

#endif