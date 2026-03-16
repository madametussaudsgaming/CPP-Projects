/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:26:51 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 17:54:39 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &ori);
		WrongCat &operator=(const WrongCat &ori);
		virtual ~WrongCat();
		//see what happens if shit aint virtual
	void makeSound() const;
};

#endif