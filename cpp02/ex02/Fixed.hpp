/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:03:10 by librahim          #+#    #+#             */
/*   Updated: 2025/05/15 14:56:27 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		static const int	frac_bits = 8;
		int					raw_val;

    public:

		Fixed();
		~Fixed();
		Fixed(const int a);
		Fixed(const float b);
		Fixed(const Fixed& other_obj);

		int         	getRawBits(void) const;
		void        	setRawBits(int const raw);
		int         	toInt( void ) const;
		float	     	toFloat( void ) const;
		Fixed&      	operator=(const Fixed& other_obj);

		Fixed					operator+(const Fixed  &other_obj);
		Fixed					operator-(const Fixed  &other_obj);
		Fixed					operator*(const Fixed  &other_obj);
		Fixed					operator/(const Fixed  &other_obj);

		bool					operator<(const Fixed  &other_obj);
		bool					operator>(const Fixed  &other_obj);
		bool					operator<=(const Fixed  &other_obj);
		bool					operator>=(const Fixed  &other_obj);
		bool					operator==(const Fixed  &other_obj);
		bool					operator!=(const Fixed  &other_obj);

		Fixed&					operator++();
		Fixed&					operator--();
		Fixed					operator++(int);
		Fixed					operator--(int);

		static Fixed&			min(Fixed& obj, Fixed& other_obj);
		static Fixed&			max(Fixed& obj, Fixed& other_obj);
		
		static const Fixed&		min(const Fixed& obj, const Fixed& other_obj);
		static const Fixed&		max(const Fixed& obj, const Fixed& other_obj);
};

std::ostream&   operator<<(std::ostream& stream_obj, const Fixed& other_obj);

#endif