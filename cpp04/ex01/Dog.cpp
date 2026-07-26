/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:22:01 by librahim          #+#    #+#             */
/*   Updated: 2025/05/21 18:49:31 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default constructor of Dog has been called" << std::endl;
    type = "Dog";
    b = new Brain();
    b->set_ideas("BONE");
}

Dog::~Dog()
{
    std::cout << "Default destructor of Dog has been called" << std::endl;
    delete this->b;
}

Dog::Dog(const Dog& obj)
{
    std::cout << "Constructor by copy of Dog has been called" << std::endl;
    type = obj.type;
    this->b = new Brain();
    *b = *obj.b;
}

Dog& Dog::operator=(const Dog& obj)
{
    std::cout << "Copy assignement operator of Dog has been called" << std::endl;
    type = obj.type;
    *b = *obj.b;
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

void    Dog::express_an_idea(int i)
{
    if (i < 0 || i > 99)
        return ;
    std::cout << b->get_idea(i) << std::endl;
}
