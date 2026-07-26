/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:35:35 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 00:36:09 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private : 
        std::string target;
    public :
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(std::string tar);
        RobotomyRequestForm(RobotomyRequestForm& o);
        RobotomyRequestForm& operator=(RobotomyRequestForm& o);
        std::string getTarget() const;
        virtual void execute(Bureaucrat const & executor) const;
        void        setTarget(std::string t);
};
#endif