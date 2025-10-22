/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:15:35 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/12 19:43:09 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr<<"Usage ./Sed 'filename' 'target' 'replacement'"<<std::endl;
		return (1);
	}
	std::string fileName = argv[1];
 	std::string target = argv[2];
	std::string replace = argv[3];
	std::string tbRead;
	std::ifstream infile(fileName.c_str());
	if (!infile.is_open())
		return (1);
	std::ofstream outfile((fileName + ".replace").c_str());
	if (!outfile.is_open())
		return (1);
	while (std::getline(infile, tbRead))
		outfile << replaceWord(tbRead, target, replace) << std::endl;
	infile.close();
	outfile.close();
	return (0);
}