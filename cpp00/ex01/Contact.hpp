/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:04:25 by librahim          #+#    #+#             */
/*   Updated: 2025/05/09 03:23:20 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iomanip>
# include <iostream>

class Contact
{
	private :
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_nbr;
		std::string	dark_secret;
		int	filled;

    public :
		Contact();
		std::string	get_last_name();
		std::string	get_first_name();
		std::string	get_nickname();
		std::string	get_phone_nbr();
		std::string	get_dark_secret();
		void		set_first_name(std::string	new_value);
		void		set_last_name(std::string	new_value);
		void		set_nickname(std::string	new_value);
		void		set_phone_nbr(std::string	new_value);
		void		set_dark_secret(std::string	new_value);
		void    	set_flag(int	new_value);
		int			get_flag();
		void		display_all(int i);
};

#endif
