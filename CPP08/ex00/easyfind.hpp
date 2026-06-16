/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:09:28 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/16 21:41:02 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class notFound : public std::exception {
  const char *what() const throw();
};

const char *notFound::what() const throw() {
  return "Value not found in this container!";
}

template <typename T> void easyfind(T& c, int i) {
	typename T::iterator iter;
	iter = std::find(c.begin(), c.end(), i);
	if (iter == c.end())
		throw (notFound());
	std::cout << "Found value ("<< i << ") in position (" << std::distance(c.begin(), iter) << ")\n";
}

#endif