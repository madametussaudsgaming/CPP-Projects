/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:41:06 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/05 18:13:42 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat John = Bureaucrat("John", 100);
	Bureaucrat Jill = Bureaucrat("Jill", 150);

	ShrubberyCreationForm fromy = ShrubberyCreationForm("out");
	fromy.beSigned(John);
	John.executeForm(fromy);
}