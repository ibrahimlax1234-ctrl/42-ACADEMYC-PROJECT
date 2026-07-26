/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:40:08 by librahim          #+#    #+#             */
/*   Updated: 2025/05/21 18:43:53 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    int i=-1;
    std::cout << "Default constructor of Brain has been called" << std::endl;
    while (++i < 100)
        ideas[i] = "Default brain idea";
}

Brain::~Brain()
{
    std::cout << "Default destructor of Brain has been called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
    int i=-1;
    std::cout << "constructor by copy of Brain has been called" << std::endl;
    while (++i < 100)
        ideas[i] = obj.ideas[i];
}

Brain&  Brain::operator=(const Brain& obj)
{
    std::cout << "copy assignement operator of Brain has been called" << std::endl;
    int i=-1;
    while (++i < 100)
        ideas[i] = obj.ideas[i];
    return *this;
}

void        Brain::set_ideas(std::string s)
{
    std::cout << "set_ideas member of class Brain has been called"<< std::endl;
    int i = -1;
    if (s.size() == 0)
        return ;
    while (++i < 100)
        ideas[i] = s;
}

std::string Brain::get_idea(int i)
{
    std::cout << "get_idea member of class Brain has been called"<< std::endl;
    if (i < 0 || i > 99)
        return "";
    return ideas[i];
}
