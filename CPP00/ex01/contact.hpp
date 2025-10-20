/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:29:25 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/08 00:58:36 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	private:
	std::string first;
	std::string last;
	std::string nickname;
	std::string	number;
	std::string secret;
	bool 		is_empty;

	public:
	Contact() : is_empty(true) {}

	void setContact(std::string fn, std::string ln, std::string nn,
					std::string num, std::string sec)
	{
		first = fn;
		last = ln;
		nickname = nn;
		number = num;
		secret = sec;
		is_empty = false;
	}

	std::string getFirst() const { return first; }
	std::string getLast() const { return last; }
	std::string getNick() const { return nickname; }
	bool		isEmpty() const { return is_empty; }
};
