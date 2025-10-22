/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:57:06 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/12 18:50:55 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

std::string replaceWord(std::string line, std::string target, std::string replace)
{
	std::string	result;
	size_t		pos = 0;
	size_t		found = 0;

	while ((found = line.find(target, pos)) != std::string::npos)
	{
		result += line.substr(pos, found - pos);
		result += replace;
		pos = found + target.length();
	}
	result += line.substr(pos);
	return (result);
}