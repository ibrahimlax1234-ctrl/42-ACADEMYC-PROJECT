/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:21:54 by librahim          #+#    #+#             */
/*   Updated: 2025/05/15 11:25:00 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
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
	Fixed&      	operator=(const Fixed& other_obj);
	int         	toInt( void ) const;
	float	     	toFloat( void ) const;

};

std::ostream&   operator<<(std::ostream& stream_obj, const Fixed& other_obj);

#endif