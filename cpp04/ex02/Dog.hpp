/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:20:24 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 01:13:58 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "AAnimal.hpp"

#include <string>
#include <iostream>
#include "Brain.hpp"


class Dog : public AAnimal
{
        private :
                Brain*  b;
        public :
                Dog();
                ~Dog();
                Dog(const Dog& obj);
                Dog&            operator=(const Dog& obj);
                void            makeSound() const;
                std::string     getType() const;
                void            express_an_idea(int i);
};

#endif