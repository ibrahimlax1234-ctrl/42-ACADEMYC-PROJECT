/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:24:14 by librahim          #+#    #+#             */
/*   Updated: 2025/05/20 22:06:48 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "Default constructor of WrongCat has been called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Default destructor of WrongCat has been called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
    std::cout << "Constructor by copy of WrongCat has been called" << std::endl;
    type = obj.type;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
    type = obj.type;
    std::cout << "Copy assignement operator of WrongCat has been called" << std::endl;
    return *this;
}

void    WrongCat::makeSound() const
{
    std::cout << "Wrongmeow"<<std::endl;
}


std::string WrongCat::getType() const
{
    std::cout << "getType of WrongCat has been called " <<std::endl;
    return this->type;
}
