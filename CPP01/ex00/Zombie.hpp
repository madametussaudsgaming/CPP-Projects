/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:26:27 by rpadasia          #+#    #+#             */
/*   Updated: 2025/11/21 16:34:56 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie{
	private:
	std::string name;
	public:

	Zombie();
	Zombie(std::string n);
	Zombie(Zombie& variables);
	Zombie& operator=(const Zombie& variables);
	~Zombie();
	void announce(void);
	void setName(std::string n);
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif