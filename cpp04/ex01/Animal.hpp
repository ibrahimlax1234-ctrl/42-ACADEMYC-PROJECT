/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:46:59 by librahim          #+#    #+#             */
/*   Updated: 2025/05/20 22:32:05 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal
{
    protected :
        std::string type;
    public :
        Animal();
        virtual ~Animal();
        Animal(const Animal& obj);
        Animal&         operator=(const Animal& obj);
        virtual void    makeSound() const;
        virtual std::string     getType() const;
};

#endif