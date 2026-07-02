/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 22:16:09 by rpadasia          #+#    #+#             */
/*   Updated: 2026/07/02 13:10:23 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <list>
#include <deque>
#include <ctime>
#include <map>
#include <exception>

#include <stack>
#include <cstdlib>
#include <cctype>

class rpn {
	private:
		std::stack<int, std::list<int> > _rpnstack;
		std::string str;

		void _processOperator(char);
		void _processDigit(char);
		bool _isOperator(char);
		// bool _isDigit(char);

	public:
		rpn();
		rpn(std::string str1);
		rpn(const rpn& other);
		rpn& operator=(const rpn& other);
		~rpn();

};

#endif