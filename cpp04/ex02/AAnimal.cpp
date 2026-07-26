/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:15:48 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 01:13:58 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    type = "Default";
    std::cout << "Default constructor of AAnimal has been called" << std::endl;
}

AAnimal::~AAnimal()
{    
    std::cout << "Default destructor of AAnimal has been called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj)
{
    std::cout << "Constructor by copy of AAnimal has been called" << std::endl;
    type = obj.type;
}


AAnimal& AAnimal::operator=(const AAnimal& obj)
{
    type = obj.type;
        std::cout << "Copy assignement operator of AAnimal has been called" << std::endl;
    return *this;
}

std::string AAnimal::getType() const
{
    std::cout << "getType of AAnimal has been called " <<std::endl;
    return this->type;
}
