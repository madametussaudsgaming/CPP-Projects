/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:41:04 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/02 21:35:29 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

#define MAXGRADE 1
#define MINGRADE 150

class Bureaucrat{
	private:
		const std::string name;
		int			grade;

		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		Bureaucrat(void);

	public:
		Bureaucrat(const std::string& name, int initGrade);
		Bureaucrat(const Bureaucrat& ori);
		Bureaucrat& operator=(const Bureaucrat ori);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& gradeName);

#endif