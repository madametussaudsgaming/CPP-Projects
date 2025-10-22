/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:26:27 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/10 00:42:48 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class	Zombie{
	private:
	std::string name;
	public:

	Zombie();
	Zombie(std::string n);
	~Zombie();
	void announce(void);
	void setName(std::string n);
};

Zombie* zombieHorde( int N, std::string name );
