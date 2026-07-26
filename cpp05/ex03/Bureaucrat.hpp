/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:35:48 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 00:35:06 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private :
		const std::string	name;
		int             	grade;

    public :
		Bureaucrat();
		Bureaucrat(const std::string n, int g);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		const std::string	getName() const; 
		int					getGrade() const;
		void				increm_grade();
		void				decrem_grade();
		void				signForm(AForm& f);
		void				executeForm(AForm const & form) const;

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
					const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& b);


#endif
