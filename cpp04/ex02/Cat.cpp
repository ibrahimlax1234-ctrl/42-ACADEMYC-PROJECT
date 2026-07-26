/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:24:14 by librahim          #+#    #+#             */
/*   Updated: 2025/05/21 18:43:43 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Default constructor of Cat has been called" << std::endl;
    type = "Cat";
    this->b = new Brain();
    b->set_ideas("CATNIP!");
}

Cat::~Cat()
{
    std::cout << "Default destructor of Cat has been called" << std::endl;
    delete this->b;
}

Cat::Cat(const Cat& obj)
{
    std::cout << "Constructor by copy of Cat has been called" << std::endl;
    type = obj.type;
    this->b = new Brain();
    *b = *obj.b;
}

Cat& Cat::operator=(const Cat& obj)
{
    std::cout << "Copy assignement operator of cat has been called" << std::endl;
    type = obj.type;
    *b = *obj.b;
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "MEOW" <<std::endl;
}

std::string Cat::getType() const
{
    std::cout << "getType of Cat has been called " <<std::endl;
    return this->type;
}

void    Cat::express_an_idea(int i)
{
    if (i < 0 || i > 99)
        return ;
    std::cout << b->get_idea(i) << std::endl;
}
