/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:15:08 by librahim          #+#    #+#             */
/*   Updated: 2025/05/09 21:14:12 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <cctype>
# include <string>

class PhoneBook
{
	private:
		Contact c[8];
		int		curr_nbr;
		int		con_nbr;

    public:
		PhoneBook();
		void	do_add();
		void	do_search();
};

#endif
