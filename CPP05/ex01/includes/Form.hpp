/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:06:01 by rpadasia          #+#    #+#             */
/*   Updated: 2026/05/18 13:54:48 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Form {
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;



	public:
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
		Form();
		Form(const std::string& name, int signgrade, int execgrade);
		Form(const Form& ori);
		Form& operator=(const Form &ori);
		~Form();

		std::string getName() const;
		bool		getSignStatus() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		void		beSigned(Bureaucrat &rando);
};

std::ostream& operator<<(std::ostream& out, const Form& formOut);

#endif