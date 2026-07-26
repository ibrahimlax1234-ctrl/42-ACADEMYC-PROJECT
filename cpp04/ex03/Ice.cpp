/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:40:58 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 02:13:25 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
    // std::cout << "Default constructor of Ice has been called " << std::endl;
    type = "ice";
}

Ice::~Ice()
{
    // std::cout << "Default destructor of Ice has been called " << std::endl;
}

Ice::Ice(const Ice& o)
{
    // std::cout << "Copy contructor of Ice has been called " << std::endl;
    type = o.type;
}

Ice&    Ice::operator=(const Ice& o)
{
    // std::cout << "Copy assigment operator of Ice has been called " << std::endl;
    type = o.type;
    return *this;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

 void Ice::use(ICharacter& target)
 {
    std::cout <<"* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
 }