/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:20:24 by librahim          #+#    #+#             */
/*   Updated: 2025/05/21 17:37:14 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"

#include <string>
#include <iostream>

class Dog : public Animal
{
        public :
        Dog();
        ~Dog();
        Dog(const Dog& obj);
        Dog&            operator=(const Dog& obj);
        void            makeSound() const;
        std::string     getType() const;
};

#endif