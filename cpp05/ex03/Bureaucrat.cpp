/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:35:50 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 16:58:33 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unamed"), grade(150){}

Bureaucrat::~Bureaucrat(){}

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


const std::string	Bureaucrat::getName() const
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

void	Bureaucrat::signForm(AForm& f)
{
    if ((&f) == NULL)
        return ;
    try
    {
        f.beSigned(*this);
    }
    catch (std::exception &e)
    {
        std::cout << getName() <<" couldn’t sign " << f.getName() << " because " << e.what() <<std::endl;
    }
}


void    Bureaucrat::executeForm(AForm const & form) const
{
    if ((&form) == NULL)
        return ;
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldnt execute this "  << form.getName() << " because " << e.what() <<std::endl;
    }
}
