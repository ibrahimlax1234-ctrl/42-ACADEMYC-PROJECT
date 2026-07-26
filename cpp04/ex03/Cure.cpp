/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:17:06 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 02:13:48 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    // std::cout << "Default constructor of Cure has been called " << std::endl;
    type = "cure";
}

Cure::~Cure()
{
    // std::cout << "Default destructor of Cure has been called " << std::endl;
}

Cure::Cure(const Cure& o)
{
    // std::cout << "Copy contructor of Cure has been called " << std::endl;
    type = o.type;
}

Cure&    Cure::operator=(const Cure& o)
{
    // std::cout << "Copy assigment operator of Cure has been called " << std::endl;
    type = o.type;
    return *this;
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void    Cure::use(ICharacter& target)
{
    std::cout <<"* heals " << target.getName() << "'s wounds *" <<std::endl;
}
