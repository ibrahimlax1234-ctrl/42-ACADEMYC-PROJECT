/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:28:57 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 02:59:23 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character()
{
    // std::cout << "default constructor of Character has been called" << std::endl;
    int i = -1;
    while (++i < 4)
        m[i] = NULL;
    name = "default name";
}

Character::Character(std::string name)
{
    // std::cout << "Paramerized constructor of Character has been called" << std::endl;
    int i = -1;
    while (++i < 4)
        m[i] = NULL;
    this->name = name;
}


Character::~Character()
{
    int i = -1;
    // std::cout << "default destructor of Character has been called" << std::endl;
    while (++i < 4)
    {
        if (m[i] != NULL)
            delete m[i];
    }
}

Character::Character(const Character& o)
{
    // std::cout << "Copy constructor of Character has been called" << std::endl;
    int i = -1;
    while (++i < 4)
        m[i] = NULL;
    i = -1;
    while (++i < 4)
    {
        if (o.m[i] != NULL)
            this->m[i] = o.m[i]->clone();
    }
    name = o.name;
}

Character& Character::operator=(Character const& o)
{   
    // std::cout << "Copy assigment operator of Character has been called" << std::endl;
    if (&o == this)
        return *this;
    int i = -1;
    while (++i < 4)
    {
        if (o.m[i] != NULL)
            this->m[i] = o.m[i]->clone();
    }
    name = o.name;
    return *this;
}


std::string const& Character::getName() const
{
    return name;
}


void Character::equip(AMateria* m)
{
    if (m == NULL)
        return ;
    if (this->m[0] == NULL)
        this->m[0] = m;

    else if (this->m[1] == NULL)
        this->m[1] = m;

    else if (this->m[2] == NULL)
        this->m[2] = m;

    else if (this->m[3] == NULL)
        this->m[3] = m;
}


void Character::unequip(int idx)
{
    if (idx > 3 || idx < 0)
        return ;

    if (this->m[idx] == NULL)
        return ;
    else
        m[idx] = NULL;
}


void Character::use(int idx, ICharacter& target)
{
    if (idx > 3 || idx < 0)
        return ;
    if (m[idx] == NULL)
        return ;
    
    m[idx]->use(target);
}
