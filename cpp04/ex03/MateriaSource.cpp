/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:25:06 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 02:58:19 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
    // std::cout << "constructor of MateriaSouce has been called" << std::endl;
    int i = -1;
    while (++i < 4)
        ms[i] = NULL;
}


MateriaSource::~MateriaSource()
{
    // std::cout << "Destructor of MateriaSouce has been called" << std::endl;
    int i = -1;
    while (++i < 4)
    {
        if (ms[i] != NULL)
        {
            delete ms[i];
            ms[i] = NULL;
        }
    }
}


MateriaSource::MateriaSource(const MateriaSource& ob)
{
    // std::cout << "Copy constructor of MateriaSouce has been called" << std::endl;
    int i = -1;
    while (++i < 4)
        ms[i] = NULL;
    i = -1;
    while (++i < 4)
    {
        if (ob.ms[i] != NULL)
            this->ms[i] = ob.ms[i]->clone();
    }
}


MateriaSource& MateriaSource::operator=(const MateriaSource& ob)
{
    // std::cout << "Copy assignmement operator of MateriaSouce has been called" << std::endl;
    if (&ob == this)
        return *this;
    int i = -1;
    while (++i < 4)
        ms[i] = NULL;
    i = -1;
    while (++i < 4)
    {
        if (ob.ms[i] != NULL)
            this->ms[i] = ob.ms[i]->clone();
    }
    return *this;
}


void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
        return ;
    if (this->ms[0] == NULL)
        this->ms[0] = m;
    else if (this->ms[1] == NULL)
        this->ms[1] = m;
    else if (this->ms[2] == NULL)
        this->ms[2] = m;
    else if (this->ms[3] == NULL)
        this->ms[3] = m;
}


AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i;
    AMateria *re = NULL;

    i = -1;
    while (++i < 4)
    {
        if (ms[i] != NULL && ms[i]->getType().compare(type) == 0)
        {
            re = ms[i]->clone();
            break ;
        }
    }
    return re;
}
