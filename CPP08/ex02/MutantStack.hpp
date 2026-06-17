/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:09:28 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/17 16:45:13 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "MutantStack.tpp"

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
	MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack& operator=(const MutantStack &other);
	~MutantStack();

	typedef typename C::iterator iter;

	iter begin();
	iter end();
};

#endif