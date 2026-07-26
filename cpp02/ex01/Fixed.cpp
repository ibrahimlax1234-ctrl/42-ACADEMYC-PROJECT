/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:21:31 by librahim          #+#    #+#             */
/*   Updated: 2025/05/15 11:43:41 by librahim         ###   ########.fr       */
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


Fixed::Fixed(const int a)
{
	std::cout<<"Int constructor called"<<std::endl;
	if (a > 8388607)
		raw_val = 2147483392;
	else if (a < -8388608)
		raw_val = -2147483648;
	else
		raw_val = a * 256;
	return ;
}


Fixed::Fixed(const float a)
{ 
	std::cout<<"Float constructor called"<<std::endl;
	raw_val = roundf(a *(1 << 8));

	if (a > 8388607.49)
		raw_val = 2147483392;
	else if (a < -8388608.49)
		raw_val = -2147483648;
	else
		raw_val = roundf(a * 256);
	return ;
}

int         Fixed::toInt( void ) const
{
	int	ret_val;
	ret_val = raw_val >> frac_bits;
    return ret_val;
}


float	    Fixed::toFloat( void ) const
{
	float ret_val;

	ret_val = (float) raw_val / 256.0f;
    return ret_val;
}


std::ostream&   operator<<(std::ostream& stream_obj, const Fixed& other_obj)
{
	stream_obj << other_obj.toFloat();
	return stream_obj;
}

