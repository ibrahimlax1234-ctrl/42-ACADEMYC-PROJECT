/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:22:35 by librahim          #+#    #+#             */
/*   Updated: 2025/05/20 22:00:45 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

#include <string>
#include <iostream>

class Cat : public Animal
{
        public :
        Cat();
        ~Cat();
        Cat(const Cat& obj);
        Cat& operator=(const Cat& obj);
        void    makeSound() const;
        std::string getType() const;
};

#endif