/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:35:54 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 16:58:11 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("unamed"),issigned(false), g_tosign(75), g_toex(75)  {}

AForm::AForm(std::string n, int sign_grade, int ex_grade) : name(n),issigned(false) , g_tosign(sign_grade), g_toex(ex_grade)
{
    if (g_tosign > 150)
        throw AForm::GradeTooLowException();
    else if (g_tosign < 1)
        throw AForm::GradeTooHighException();
    if (g_toex > 150)
        throw AForm::GradeTooLowException();
    else if (g_toex < 1)
        throw AForm::GradeTooHighException();
}

AForm::~AForm(){}


AForm::AForm(AForm& o) : name(o.getName()), g_tosign(o.get_g_tosign()), g_toex(o.get_g_toex())
{
    issigned = o.get_issign();
}


AForm& AForm::operator=(AForm& o)
{
    issigned = o.get_issign();
    return *this;
}


std::string AForm::getName() const {return name;}
bool        AForm::get_issign()const{return issigned;}
int         AForm::get_g_tosign() const {return g_tosign;}
int         AForm::get_g_toex() const {return g_toex;}



void     AForm::beSigned(Bureaucrat& b)
{
    if ((&b) == NULL)
        return ;
    if  (b.getGrade() > this->g_tosign)
        throw AForm::GradeTooLowException();
    else
    {
        std::cout <<  b.getName() <<" signed " << this->getName() << std::endl;
        this->issigned = true;
    }
}


const char *    AForm::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}


const char *    AForm::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char *    AForm::FormNotSigned::what() const throw()
{
    return "Form not signed";
}


std::ostream& operator<<(std::ostream& stream, AForm& b)
{
    stream << "the form name is \""<<b.getName()<<"\" and its signature is " << b.get_issign() << ", its grade to sign is "<< b.get_g_tosign() <<" and its grade to exec is "<< b.get_g_toex()<<std::endl;
    return stream;
}
