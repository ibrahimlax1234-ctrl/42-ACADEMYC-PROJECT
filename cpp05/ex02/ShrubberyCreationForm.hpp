/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:35:37 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 00:37:47 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private : 
        std::string target;
    public :
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(std::string tar);
        ShrubberyCreationForm(ShrubberyCreationForm& o);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm& o);
        std::string getTarget() const;
        virtual void execute(Bureaucrat const & executor) const;
        void        setTarget(std::string t);
};
#endif