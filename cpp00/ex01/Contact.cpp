/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:12:07 by librahim          #+#    #+#             */
/*   Updated: 2025/05/09 03:22:01 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact(void)
{
	filled = 0;
    return ;
}

void    Contact::set_last_name(std::string	new_value)
{
	last_name = new_value;
}

void    Contact::set_first_name(std::string	new_value)
{
	first_name = new_value;
}

void    Contact::set_nickname(std::string	new_value)
{
	nickname = new_value;
}

void    Contact::set_phone_nbr(std::string	new_value)
{
	phone_nbr = new_value;
}

void    Contact::set_dark_secret(std::string	new_value)
{
	dark_secret = new_value;
}

void    Contact::set_flag(int	new_value)
{
	filled = new_value;
}

int	Contact::get_flag()
{
	return filled;
}

std::string	Contact::get_last_name()
{
	return last_name;
}

std::string	Contact::get_first_name()
{
	return first_name;
}

std::string	Contact::get_nickname()
{
	return nickname;
}

std::string	Contact::get_phone_nbr()
{
	return phone_nbr;
}

std::string	Contact::get_dark_secret()
{
	return dark_secret;
}

std::string trunc_dot(std::string str)
{
    if (str.size() > 9)
    {
        str = str.substr(0, 9);
        str.append(".");
    }
    return (str);
}

void	Contact::display_all(int i)
{
	if (filled == 0)
		return ;
	std::cout << std::setw(10) << i << "|";
	
    std::cout << std::setw(10) << trunc_dot(first_name) << "|";
    std::cout << std::setw(10) << trunc_dot(last_name) << "|";
    std::cout << std::setw(10) << trunc_dot(nickname) << std::endl;
}
