/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:31:57 by librahim          #+#    #+#             */
/*   Updated: 2025/05/15 11:12:54 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<< "Default constructor called"<<std::endl;
    raw_val = 0;
    return ;
}


Fixed::~Fixed()
{
	std::cout<<  "Destructor called" <<std::endl;

    return ;
}


Fixed::Fixed(const Fixed  &other_obj)
{
	std::cout<< "Copy constructor called" <<std::endl;
	raw_val = other_obj.getRawBits();
    return ;
}


int		Fixed::getRawBits() const
{
	std::cout <<"getRawBits member function called"<< std::endl;

	return raw_val;
}


void	Fixed::setRawBits(int const raw)
{
	std::cout <<"setRawBits member function called"<< std::endl;
	raw_val = raw;
    return ;
}


Fixed&	Fixed::operator=(const Fixed& other_obj)
{
	std::cout << "Copy assignment operator called" <<std::endl;

	raw_val = other_obj.getRawBits();

	return *this;
}
