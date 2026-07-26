/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:30:00 by librahim          #+#    #+#             */
/*   Updated: 2025/05/20 22:06:27 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "Default";
    std::cout << "Default constructor of WrongAnimal has been called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{    
    std::cout << "Default destructor of WrongAnimal has been called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
    std::cout << "Constructor by copy of WrongAnimal has been called" << std::endl;
    type = obj.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
    type = obj.type;
        std::cout << "Copy assignement operator of WrongAnimal has been called" << std::endl;
    return *this;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "wrong TYPICAL ANIMAL SOUND"<<std::endl;
}

std::string WrongAnimal::getType() const
{
    std::cout << "getType of WrongAnimal has been called " <<std::endl;
    return this->type;
}
