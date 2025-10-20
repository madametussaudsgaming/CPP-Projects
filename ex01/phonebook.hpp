/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:19:36 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/05 21:57:38 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "contact.hpp"

class Phonebook
{
	private:
	Contact contacts[8];
	int total_contacts;
	int next_index;

	public:
	Phonebook() : total_contacts(0), next_index(0) {}

	void add_contact();
	void search_contact(std::string index);
	// void display_contact(int index);
	// void display_phonebook();
};