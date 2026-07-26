/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:28:59 by librahim          #+#    #+#             */
/*   Updated: 2025/05/15 11:39:15 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		static const int 	frac_bits = 8;
		int					raw_val;
    public:
		Fixed();
		~Fixed();	
		Fixed(const Fixed& other_obj);
		Fixed&      operator=(const Fixed& other_obj);
		int         getRawBits(void) const;
		void        setRawBits(int const raw);
};


#endif