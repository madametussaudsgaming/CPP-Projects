/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:06:01 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/05 17:49:34 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
# define A_FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	protected:
		void	canExecute(const Bureaucrat& executor) const;
	public:
		AForm();
		AForm(const std::string& name, int signgrade, int execgrade);
		AForm(const AForm& ori);
		AForm& operator=(const AForm &ori);
		~AForm();

		std::string getName() const;
		bool		getSignStatus() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		void		beSigned(Bureaucrat &rando);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& formOut);

#endif