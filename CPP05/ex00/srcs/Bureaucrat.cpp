/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:41:01 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/02 22:00:44 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const std::string& name, int initGrade) : name(name)
{
	std::cout<<"Calling Bureaucrat Parameterized Constructor."<<std::endl;
	if (initGrade > 150)
		throw (GradeTooLowException());
	else if (initGrade < 1)
		throw (GradeTooHighException());
	this->grade = initGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ori) : name(ori.name), grade(ori.grade) {
	std::cout<<"Calling Bureaucrat Copy Constructor."<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat ori)
{
	std::cout<<"Calling Bureaucrat Copy Assignment Operator."<<std::endl;
	this->grade = ori.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Killing Bureaucrat."<<std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int		Bureaucrat::getGrade() const
{
	return (this->grade);
}
void	Bureaucrat::incrementGrade()
{
	std::cout<<"Attempting Incrementation"<<std::endl;
	if (this->grade == MAXGRADE)
		throw (GradeTooHighException());
	this->grade--;
}
void	Bureaucrat::decrementGrade()
{
	std::cout<<"Attempting Decrementation"<<std::endl;
	if (this->grade == MINGRADE)
		throw (GradeTooLowException());
	this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is TOO HIGH");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is TOO LOW");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& gradeName)
{
	out<<gradeName.getName()<<"bureaucrat grade "<<gradeName.getGrade();
	return (out);
}
