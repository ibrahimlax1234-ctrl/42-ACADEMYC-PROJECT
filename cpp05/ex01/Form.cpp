/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:44:32 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 20:31:17 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("unamed"), g_tosign(150), g_toex(150) {issigned = false;}

Form::Form(std::string n, int sign_grade, int ex_grade) : name(n), g_tosign(sign_grade), g_toex(ex_grade)
{
    issigned = false;
    if (g_tosign > 150)
        throw Form::GradeTooLowException();
    else if (g_tosign < 1)
        throw Form::GradeTooHighException();
    
    if (g_toex > 150)
        throw Form::GradeTooLowException();
    else if (g_toex < 1)
        throw Form::GradeTooHighException();
}

Form::~Form() {}


Form::Form(Form& o) : name(o.getName()), g_tosign(o.get_g_tosign()), g_toex(o.get_g_toex()) {issigned = o.get_issign();}


Form& Form::operator=(Form& o)
{
    issigned = o.get_issign();
    return *this;
}


std::string Form::getName() const {return name;}
bool        Form::get_issign() const {return issigned;}
int         Form::get_g_tosign() const {return g_tosign;}
int         Form::get_g_toex() const {return g_toex;}



void     Form::beSigned(Bureaucrat& b)
{
    if ((&b) == NULL)
        return ;
    if  (b.getGrade() > this->g_tosign)
        throw Form::GradeTooLowException();
    else
        this->issigned = true;
}


const char *    Form::GradeTooLowException::what() const throw() {return "grade is too low"; }


const char *    Form::GradeTooHighException::what() const throw() {return "grade is too high"; }


std::ostream& operator<<(std::ostream& stream, Form& b)
{
    stream << "the form name is \""<<b.getName()<<"\" and its signature is " << b.get_issign() << ", its grade to sign is "<< b.get_g_tosign() <<" and its grade to exec is "<< b.get_g_toex()<<std::endl;
    return stream;
}

