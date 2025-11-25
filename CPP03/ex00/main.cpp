/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:20:12 by rpadasia          #+#    #+#             */
/*   Updated: 2025/11/24 23:11:39 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap John = ClapTrap("Johny");
	John.attack("jeff");
	John.beRepaired(30);
	John.takeDamage(20);
	John.displayStats();
}