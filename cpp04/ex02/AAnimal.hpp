/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:46:59 by librahim          #+#    #+#             */
/*   Updated: 2025/05/23 01:13:58 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP
#include <string>
#include <iostream>

class AAnimal
{
    protected :
        std::string type;
    public :
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal& obj);
        AAnimal&                operator=(const AAnimal& obj);
        virtual void            makeSound() const = 0;
        virtual std::string     getType() const;
};

#endif