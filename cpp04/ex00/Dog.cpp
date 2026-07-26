/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:22:01 by librahim          #+#    #+#             */
/*   Updated: 2025/05/20 22:00:55 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Default constructor of Dog has been called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Default destructor of Dog has been called" << std::endl;
}

Dog::Dog(const Dog& obj)
{
    std::cout << "Constructor by copy of Dog has been called" << std::endl;
    type = obj.type;
}

Dog& Dog::operator=(const Dog& obj)
{
    type = obj.type;
    std::cout << "Copy assignement operator of Dog has been called" << std::endl;
    return *this;
    
}

void    Dog::makeSound() const
{
    std::cout << "WOOF"<<std::endl;
}

std::string Dog::getType() const
{
    std::cout << "getType of Dog has been called " <<std::endl;
    return this->type;
}
