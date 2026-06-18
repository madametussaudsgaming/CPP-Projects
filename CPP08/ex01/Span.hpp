/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:09:28 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/18 17:33:23 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Span
{
	private:
		unsigned int size_;
		std::vector<int> intStore;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		void addRandomNumbers(unsigned int quantity);
		int		shortestSpan();
		int		longestSpan();

		template<typename InputIterator>
		void addNumbers(InputIterator first, InputIterator last) {
			if (intStore.size() + static_cast<unsigned int>(std::distance(first, last)) > size_)
				throw noSpace();
			intStore.insert(intStore.end(), first, last);
		}

		class noSpace : public std::exception {
			const char *what() const throw();
		};
		class noSpanFound : public std::exception {
			const char *what() const throw();
		};


};

#endif