/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:26:47 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/27 13:31:03 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

bool is_valid_number(const std::string num)
{
	std::string::const_iterator it = num.begin();
	while (it != num.end() && std::isdigit(*it)) { ++it; }
	return (!num.empty() && (it == num.end()));
}

void Phonebook::add_contact()
{
	std::string first, last, nickname, number, secret;
	std::cout<<"Enter First Name: ";
	std::getline(std::cin, first);
	if (first.empty())
	{
		std::cout<<"First Name cannot be empty."<<std::endl;
		return ;
	}
	std::cout<<"Enter Last Name: ";
	std::getline(std::cin, last);
	if (last.empty())
	{
		std::cout<<"Last Name cannot be empty."<<std::endl;
		return ;
	}
	std::cout<<"Enter Nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.empty())
	{
		std::cout<<"Nickname cannot be empty."<<std::endl;
		return ;
	}
	std::cout<<"Enter Contact Number: ";
	std::getline(std::cin, number);
	if (number.empty())
	{
		std::cout<<"Contact Number DEFINITELY cannot be empty."<<std::endl;
		return ;
	}
	if (!is_valid_number(number))
	{
		std::cout<<"Contact Number should ideally be a number."<<std::endl;
		return ;
	}
	std::cout<<"What is their DARKEST secret? ";
	std::getline(std::cin, secret);
	if (secret.empty())
	{
		std::cout<<"Come on... they've gotta have one."<<std::endl;
		return ;
	}
	contacts[next_index].setContact(first, last, nickname, number, secret);
	next_index = ((next_index + 1) % 8);
}

void Phonebook::search_contact(std::string index)
{
	std::string	temp;
	int 		i;
	std::stringstream ss(index);
	if (!(ss >> i))
	{
		std::cout << "Invalid index format." << std::endl;
		return;
	}
	i--;
	if (i < 0 || i > 7)
	{
		std::cout<<"Enter contact index between 1 and 8."<<std::endl;
		return ;
	}
	if (contacts[i].isEmpty())
	{
		std::cout<<"This contact index is EMPTY."<<std::endl;
		return;
	}
	std::cout<<std::right<<std::setw(10)<<"Index";
	std::cout<<"|";
	std::cout<<std::right<<std::setw(10)<<"First Name";
	std::cout<<"|";
	std::cout<<std::right<<std::setw(10)<<"Last Name";
	std::cout<<"|";
	std::cout<<std::right<<std::setw(10)<<"Nickname"<<std::endl;
	std::cout<<std::right<<std::setw(10)<<i+1;
	std::cout<<"|";
	temp = contacts[i].getFirst();
	if (temp.length() > 10)
		std::cout<<std::right<<std::setw(10)<<temp.substr(0, 9)+".";
	else
		std::cout<<std::right<<std::setw(10)<<temp;
	std::cout<<"|";
	temp = contacts[i].getLast();
	if (temp.length() > 10)
		std::cout<<std::right<<std::setw(10)<<temp.substr(0, 9)+".";
	else
		std::cout<<std::right<<std::setw(10)<<temp;
	std::cout<<"|";
	temp = contacts[i].getNick();
	if (temp.length() > 10)
		std::cout<<std::right<<std::setw(10)<<temp.substr(0, 9)+"."<<std::endl;
	else
		std::cout<<std::right<<std::setw(10)<<temp<<std::endl;
}