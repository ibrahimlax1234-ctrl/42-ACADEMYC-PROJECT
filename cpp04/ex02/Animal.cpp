/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:51:07 by librahim          #+#    #+#             */
/*   Updated: 2025/05/21 20:08:04 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    type = "Default";
    std::cout << "Default constructor of Animal has been called" << std::endl;
}

Animal::~Animal()
{    
    std::cout << "Default destructor of Animal has been called" << std::endl;
}

Animal::Animal(const Animal& obj)
{
    std::cout << "Constructor by copy of Animal has been called" << std::endl;
    type = obj.type;
}

Animal& Animal::operator=(const Animal& obj)
{
    type = obj.type;
        std::cout << "Copy assignement operator of Animal has been called" << std::endl;
    return *this;
}

void    Animal::makeSound() const
{
    std::cout << "TYPICAL ANIMAL SOUND"<<std::endl;
}

std::string Animal::getType() const
{
    std::cout << "getType of Animal has been called " <<std::endl;
    return this->type;
}
