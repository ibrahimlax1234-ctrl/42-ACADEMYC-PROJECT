/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:35:52 by librahim          #+#    #+#             */
/*   Updated: 2025/08/22 14:03:30 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm
{
    private :
        const std::string   name;
        bool                issigned;
        const int           g_tosign;
        const int           g_toex;
    public :
        AForm();
        virtual ~AForm();
        AForm(std::string n, int sign_grade, int ex_grade);
        AForm(AForm& o);
        AForm& operator=( AForm& o);
        virtual void execute(Bureaucrat const & executor) const = 0;
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
    class FormNotSigned : public std::exception
    {
        public :
            virtual const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, AForm& b);


#endif