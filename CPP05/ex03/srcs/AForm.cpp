/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:05:52 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/17 14:25:45 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
	return "[Form grade is TOO HIGH]";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "[Form grade is TOO LOW]";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "[Form not signed!]";
}

AForm::AForm() : name("name"), isSigned(false), signGrade(1), execGrade(1) {}

AForm::AForm(const std::string& name, int signgrade, int execgrade) : name(name), signGrade(signgrade), execGrade(execgrade)
{
	std::cout<<"Calling Form Parameterized Constructor."<<std::endl;
	if (signgrade > MINGRADE || execgrade > MINGRADE)
		throw (GradeTooLowException());
	else if (signgrade < MAXGRADE || execgrade < MAXGRADE)
		throw (GradeTooHighException());
	this->isSigned = false;
}

AForm::AForm(const AForm& ori) : name(ori.name), signGrade(ori.signGrade), execGrade(ori.execGrade) {
	std::cout<<"Calling Form Copy Constructor."<<std::endl;
	this->isSigned = false;
}

AForm& AForm::operator=(const AForm &ori)
{
	std::cout<<"Calling Form Copy Assignment Operator."<<std::endl;
	this->isSigned = ori.isSigned;
	return (*this);
}

AForm::~AForm()
{
	std::cout<<"Burning Form."<<std::endl;
}

std::string AForm::getName() const
{
	return (this->name);
}

bool		AForm::getSignStatus() const
{
	return (this->isSigned);
}

int			AForm::getSignGrade() const
{
	return (this->signGrade);
}

int			AForm::getExecGrade() const
{
	return (this->execGrade);
}

std::ostream& operator<<(std::ostream& out, const AForm& formOut)
{
	out<<formOut.getName()<<std::endl<<(formOut.getSignStatus() ? "true" : "false")<<std::endl<<formOut.getSignGrade()<<std::endl<<formOut.getExecGrade()<<std::endl;
	return (out);
}

void		AForm::beSigned(Bureaucrat &rando)
{
	try {
		if (rando.getGrade() <= this->getSignGrade())
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


void	AForm::canExecute(const Bureaucrat& executor) const
{
	if (this->isSigned == false)
		throw(FormNotSignedException());
	if (executor.getGrade() > this->getExecGrade())
		throw(GradeTooLowException());
}