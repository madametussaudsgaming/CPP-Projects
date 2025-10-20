/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 21:38:31 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/05 22:02:48 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string command;

	while (1)
	{
		std::cout<<"ENTER COMMAND (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout<<"\nINPUT STREAM CLOSED. EXITING..."<<std::endl;
			break;
		}
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
		{
			std::string index;
			std::cout<<"ENTER INDEX (1-8): ";
			std::getline(std::cin, index);
			phonebook.search_contact(index);
		}
		else if (command == "EXIT")
		{
			std::cout<<"EXITING... DELETING ENTIRE PHONEBOOK\n";
			break ;
		}
		else
			std::cout<<"INVALID COMMAND\n";
	}
}