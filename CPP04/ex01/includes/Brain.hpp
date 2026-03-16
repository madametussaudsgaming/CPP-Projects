/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 18:06:28 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 20:05:31 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &ori);
		Brain &operator=(const Brain &ori);
		~Brain();
	void RandomIdeas();
};

#endif