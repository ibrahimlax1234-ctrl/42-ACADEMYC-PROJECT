/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:58:23 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 01:45:13 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type)
{
    // std::cout<< "parametrized constructor of AMateria has been called" << std::endl;
    this->type = type;
}


AMateria::AMateria()
{
    // std::cout << "default constructor of AMateria hsa been called" << std::endl;
    this->type = "default";
}


AMateria::~AMateria()
{
    // std::cout << "default destructor of AMateria has been called" << std::endl;
}


AMateria::AMateria(const AMateria&  o)
{
    // std::cout << "Copy constructor of AMateria has been called" << std::endl;
    type = o.type;
}


AMateria& AMateria::operator=(const AMateria&  o)
{
    // std::cout << "Copy constructor of AMateria ahs been called" << std::endl;
    type = o.type;
    return *this;
}


std::string const& AMateria::getType() const
{
    // std::cout << "getType of AMateria has been called" << std::endl;
    return type;
}


void    AMateria::use(ICharacter& target)
{
    std::cout << "* materia power getting used on " << target.getName()<< " *" << std::endl;
}
