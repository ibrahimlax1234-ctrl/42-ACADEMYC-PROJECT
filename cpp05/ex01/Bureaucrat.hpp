/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:58:58 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 00:02:23 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;
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
	std::string			getName() const;
	int					getGrade() const;
	void				increm_grade();
	void				decrem_grade();
	void				signForm(Form& f);

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
