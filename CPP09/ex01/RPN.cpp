/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 22:38:26 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/30 08:48:45 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

rpn::rpn() {}

rpn::rpn(const rpn& other) : _rpnstack(other._rpnstack), str(other.str) {}

rpn& rpn::operator=(const rpn& other) {
	if (this != &other) {
		_rpnstack = other._rpnstack;
		str = other.str;
	}
	return (*this);
}

rpn::rpn(std::string str1) {
	this->str = str1;
	for (std::size_t i = 0; i < str1.size(); ++i)
	{
		unsigned char c = static_cast<unsigned char>(str1[i]);
		std::cout << _rpnstack.top() << std::endl;
		if (std::isspace(c))
				continue;
		else if (isdigit(c))
			_processDigit(c);
		else if (_isOperator(c))
			_processOperator(c);
		else
			throw ("INVALID CHARACTER");
	}
	if (_rpnstack.size() != 1)
		throw ("EXTRA DIGITS REMAINING");
	std::cout << _rpnstack.top() << std::endl;
}

rpn::~rpn() {}

bool rpn::_isOperator(char c) {
	if (c != '+' && c != '-' && c != '*' && c != '/')
		return (false);
	return (true);
}

void rpn::_processDigit(char c) {
	this->_rpnstack.push(c - '0');
}

void rpn::_processOperator(char c) {
	int val1 = _rpnstack.top();
	_rpnstack.pop();
	int val2 = _rpnstack.top();
	_rpnstack.pop();
	switch (c) {
		case '+':
			_rpnstack.push(val1 + val2);
			break;
		case '-':
			_rpnstack.push(val1 - val2);
			break;
		case '*':
			_rpnstack.push(val1 * val2);
			break;
		case '/':
			_rpnstack.push(val1 / val2);
			break;
		default:
			throw ("UNKNOWN OPERATOR");
	}
}