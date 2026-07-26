/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:02:58 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 00:02:18 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP 
#include <iostream>
#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form
{
    private :
        const std::string   name;
        bool                issigned;
        const int           g_tosign;
        const int           g_toex;
    public :
        Form();
        ~Form();
        Form(std::string n, int sign_grade, int ex_grade);
        Form(Form& o);
        Form& operator=( Form& o);
    
        std::string getName() const;
        bool        get_issign() const;
        int         get_g_tosign() const;
        int         get_g_toex() const;
        void        beSigned(Bureaucrat& b);

    class GradeTooLowException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char * what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, Form& b);

#endif