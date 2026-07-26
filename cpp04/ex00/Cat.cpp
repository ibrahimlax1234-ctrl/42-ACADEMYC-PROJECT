/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:24:14 by librahim          #+#    #+#             */
/*   Updated: 2025/05/20 22:00:50 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Default constructor of Cat has been called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Default destructor of Cat has been called" << std::endl;
}

Cat::Cat(const Cat& obj)
{
    std::cout << "Constructor by copy of Cat has been called" << std::endl;
    type = obj.type;
}

Cat& Cat::operator=(const Cat& obj)
{
    type = obj.type;
    std::cout << "Copy assignement operator of cat has been called" << std::endl;
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "MEOW"<<std::endl;
}

std::string Cat::getType() const
{
    std::cout << "getType of Cat has been called " <<std::endl;
    return this->type;
}
