/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:05:52 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/02 23:52:34 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return "[Form grade is TOO HIGH]";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "[Form grade is TOO LOW]";
}

Form::Form() : name(), isSigned(false), signGrade(1), execGrade(1) {}

Form::Form(const std::string& name, int signgrade, int execgrade) : name(name), signGrade(signgrade), execGrade(execgrade)
{
	std::cout<<"Calling Form Parameterized Constructor."<<std::endl;
	if (signgrade > 150 || execgrade > 150)
		throw (GradeTooLowException());
	else if (signgrade < 1 || execgrade < 1)
		throw (GradeTooHighException());
	this->isSigned = false;
}

Form::Form(const Form& ori) : name(ori.name), signGrade(ori.signGrade), execGrade(ori.execGrade) {
	std::cout<<"Calling Form Copy Constructor."<<std::endl;
	this->isSigned = false;
}

Form& Form::operator=(const Form ori)
{
	std::cout<<"Calling Form Copy Assignment Operator."<<std::endl;
	this->isSigned = ori.isSigned;
	return (*this);
}

Form::~Form()
{
	std::cout<<"Burning Form."<<std::endl;
}

std::string Form::getName() const
{
	return (this->name);
}

bool		Form::getSignStatus() const
{
	return (this->isSigned);
}

int			Form::getSignGrade() const
{
	return (this->signGrade);
}

int			Form::getExecGrade() const
{
	return (this->execGrade);
}

std::ostream& operator<<(std::ostream& out, const Form& formOut)
{
	out<<formOut.getName()<<std::endl<<(formOut.getSignStatus() ? "true" : "false")<<std::endl<<formOut.getSignGrade()<<std::endl<<formOut.getExecGrade()<<std::endl;
	return (out);
}

void		Form::beSigned(Bureaucrat &rando)
{
	try {
		if (rando.getGrade() < this->getSignGrade())
		{
			this->isSigned = true;
			std::cout<<rando.getName()<<" signed "<<this->getName()<<std::endl;
		}
		else
			throw (GradeTooLowException());
	}
	catch (std::exception &e) {
		std::cout<<rando.getName()<<" couldn't sign "<<this->getName()<<" because "<<e.what()<<std::endl;
	}
}