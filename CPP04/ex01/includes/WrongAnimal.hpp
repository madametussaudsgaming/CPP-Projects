/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:21:02 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 17:54:34 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string.h>

class WrongAnimal
{
	protected:
		std::string type;
	public:
	// explicit implies constructor cannot be implicitly called (through inheritance chain)
		explicit WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& ori);
		WrongAnimal& operator=(const WrongAnimal& ori);
		virtual ~WrongAnimal();

	void makeSound() const;
	std::string getType() const;
};

#endif