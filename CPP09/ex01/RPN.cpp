/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 22:38:26 by rpadasia          #+#    #+#             */
/*   Updated: 2026/07/02 13:04:26 by rpadasia         ###   ########.fr       */
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
	if (_rpnstack.size() == 0)
		throw ("EMPTY STACK");
	if (_rpnstack.size() < 2)
		throw ("NOT ENOUGH OPERANDS");
	int val1 = _rpnstack.top();
	_rpnstack.pop();
	int val2 = _rpnstack.top();
	_rpnstack.pop();
	switch (c) {
		case '+':
			_rpnstack.push(val2 + val1);
			break;
		case '-':
			_rpnstack.push(val2 - val1);
			break;
		case '*':
			_rpnstack.push(val2 * val1);
			break;
		case '/':
			if (val1 == 0)
				throw ("CANNOT DIVIDE BY 0");
			_rpnstack.push(val2 / val1);
			break;
		default:
			throw ("UNKNOWN OPERATOR");
	}
}