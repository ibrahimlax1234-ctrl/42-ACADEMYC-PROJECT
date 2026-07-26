/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 01:27:49 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 00:00:17 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unamed"), grade(150) {}

Bureaucrat::~Bureaucrat() {}


Bureaucrat::Bureaucrat(const std::string n, int g) : name(n)
{
    this->grade = g;
    if (g < 1)
        throw GradeTooHighException();
    else if (g > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name)
{
    this->grade = obj.grade;
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    this->grade = obj.grade;
    return *this;
}


std::string	Bureaucrat::getName() const
{
    return name;
}

int	Bureaucrat::getGrade() const
{
    return grade;
}

void    Bureaucrat::increm_grade()
{
    this->grade--;
    if (this->grade < 1)
        throw GradeTooHighException();
}

void    Bureaucrat::decrem_grade()
{
    this->grade++;
    if (this->grade > 150)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& stream, Bureaucrat& b)
{
    stream << b.getName() << ", bureaucrat grade " << b.getGrade() <<"."<<std::endl;
    return stream;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade was set lower than 150";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade was set higher than 1";
}

