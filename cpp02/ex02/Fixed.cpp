/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:03:37 by librahim          #+#    #+#             */
/*   Updated: 2025/05/15 14:58:24 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout<< "Default constructor called"<<std::endl;
    raw_val = 0;
    return ;
}

Fixed::~Fixed()
{
	// std::cout<<  "Destructor called" <<std::endl;

    return ;
}

Fixed::Fixed(const Fixed  &other_obj)
{
	// std::cout<< "Copy constructor called" <<std::endl;
	raw_val = other_obj.getRawBits();
    return ;
}

int		Fixed::getRawBits() const
{
	// std::cout <<"getRawBits member function called"<< std::endl;

	return raw_val;
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout <<"setRawBits member function called"<< std::endl;
	raw_val = raw;
    return ;
}

Fixed&	Fixed::operator=(const Fixed& other_obj)
{
	// std::cout << "Copy assignment operator called" <<std::endl;

	raw_val = other_obj.getRawBits();

	return *this;
}


Fixed::Fixed(const int a)
{
	// std::cout<<"Int constructor called"<<std::endl;
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
	// std::cout<<"Float constructor called"<<std::endl;

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

	ret_val = (float) raw_val / (float) 256;
    return ret_val;
}


std::ostream&   operator<<(std::ostream& stream_obj, const Fixed& other_obj)
{
	stream_obj << other_obj.toFloat();
	return stream_obj;
}



// + - * /

// for integer min    -8,388,608 to max 8,388,607
//  for integer min    -8,388,608 to max 8,388,607
// for float max 8,388,607.9960937 and min -8,388,608

Fixed	Fixed::operator+(const Fixed  &other_obj)
{
	long long new_raw = this->getRawBits() + other_obj.getRawBits();
	if (new_raw > ((long long )2147483647))
		new_raw = (long long) 2147483647;
	Fixed ret;
	ret.setRawBits((int)new_raw);
	return ret;
}

Fixed	Fixed::operator-(const Fixed &other_obj)
{
	long long new_raw = this->getRawBits() - other_obj.getRawBits();
	if (new_raw > ((long long )2147483647))
		new_raw = (long long) 2147483647;	
	Fixed ret;
	ret.setRawBits((int)new_raw);
	return ret;
}

Fixed	Fixed::operator*(const Fixed &other_obj)
{
	long long new_raw = roundf((this->toFloat() * other_obj.toFloat()) * 256);
	if (new_raw > ((long long )2147483647))
		new_raw = (long long) 2147483647;
	Fixed ret;
	ret.setRawBits((int)new_raw);
	return ret;
}

Fixed	Fixed::operator/(const Fixed  &other_obj)
{
	long long new_raw = roundf((this->toFloat() / other_obj.toFloat()) * 256);
	if (new_raw > ((long long )2147483647))
		new_raw = (long long) 2147483647;	
	Fixed ret;
	ret.setRawBits((int)new_raw);
	return ret;
}


// bool operatiors



bool	Fixed::operator<(const Fixed  &other_obj)
{
	bool ret;

	if (this->getRawBits() < other_obj.getRawBits())
		ret = true;
	else
		ret = false;
	return ret;
}

bool	Fixed::operator>(const Fixed  &other_obj)
{
	bool ret;

	if (this->getRawBits() > other_obj.getRawBits())
		ret = true;
	else
		ret = false;
	return ret;
}

bool	Fixed::operator<=(const Fixed  &other_obj)
{
	bool ret;

	if (this->getRawBits() <= other_obj.getRawBits())
		ret = true;
	else
		ret = false;
	return ret;
}

bool	Fixed::operator>=(const Fixed  &other_obj)
{
	bool ret;

	if (this->getRawBits() >= other_obj.getRawBits())
		ret = true;
	else
		ret = false;
	return ret;
}

bool	Fixed::operator==(const Fixed  &other_obj)
{
	bool ret;

	if (this->getRawBits() == other_obj.getRawBits())
		ret = true;
	else
		ret = false;
	return ret;
}

bool	Fixed::operator!=(const Fixed  &other_obj)
{
	bool ret;

	if (this->getRawBits() != other_obj.getRawBits())
		ret = true;
	else
		ret = false;
	return ret;
}



//pre inc
Fixed&	Fixed::operator++(void)
{
	this->raw_val = this->raw_val + 1;
	return *this;
}

Fixed&	Fixed::operator--()
{
	this->raw_val = this->raw_val - 1;
	return *this;
}

// post inc
Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->raw_val = this->raw_val + 1;
	return tmp;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->raw_val = this->raw_val - 1;
	return tmp;
}


Fixed&	Fixed::min(Fixed &obj, Fixed &other_obj)
{
	if (obj.getRawBits() < other_obj.getRawBits())
		return obj;
	return other_obj;
}

const Fixed&	Fixed::min(const Fixed &obj, const Fixed &other_obj)
{
	if (obj.getRawBits() < other_obj.getRawBits())
		return obj;
	return other_obj;
}

Fixed&	Fixed::max(Fixed &obj, Fixed &other_obj)
{
	if (obj.getRawBits() > other_obj.getRawBits())
		return obj;
	return other_obj;
}

const Fixed&	Fixed::max(Fixed const &obj, Fixed const &other_obj)
{
	if (obj.getRawBits() > other_obj.getRawBits())
		return obj;
	return other_obj;
}
