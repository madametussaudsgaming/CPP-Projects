/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:41:01 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/01 17:30:42 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	grade = 150;
}

Bureaucrat::Bureaucrat(int initGrade)
{
	if (initGrade > 150)
		throw std::runtime_error("Bureaucrat::GradeTooLowException");
	if (initGrade < 1)
		throw std::runtime_error("Bureaucrat::GradeTooHighException");
	grade = initGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ori)
{
	
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat ori)
{
	
}
Bureaucrat::~Bureaucrat()
{
	
}

char	Bureaucrat::getName()
{
	
}

int		Bureaucrat::getGrade()
{
	
}
void	Bureaucrat::incrementGrade()
{
	
}
void	Bureaucrat::decrementGrade()
{
	
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& gradeName)
{
	
}
