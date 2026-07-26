/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:24:33 by librahim          #+#    #+#             */
/*   Updated: 2025/05/09 20:50:42 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int mini_atoi(std::string str)
{
    int nbr = 0;
    int i = -1;

    while (++i < (int) str.size())
    {
        if (str.at(i) == '+')
            i++;
        if (str.at(i) >= '0' && str.at(i) <= '9')
        {
            nbr = nbr * 10 + (str.at(i) - '0');
            if (nbr > 8 || nbr < 0)
                return -1;
        }
        else 
            return -1;
    }
    return nbr;
}

bool is_printble(std::string str)
{
    int i = -1;

    while (++i < (int)str.size())
    {
        if (!std::isprint((unsigned char)(str.at(i))))
            return false;
    }
    return true;
}

bool check_if_all_spaces(std::string str)
{
    int i = -1;

    while (++i < (int) str.size())
    {
        if (!std::isspace(str.at(i)))
            return false;
    }
    return true;
}

bool is_all_num(std::string str)
{
    int i = -1;

    while (++i < (int) str.size())
    {
        if (!std::isdigit(str.at(i)))
            return false;
    }
    return true;
}

PhoneBook::PhoneBook(void)
{
	curr_nbr = 0;
    con_nbr = 0;
    return ;
}

void	PhoneBook::do_add()
{
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phonenbr;
    std::string darksecret;

	curr_nbr = curr_nbr % 8;
    system("clear");
    std::cout << "Creating your contact ..." << std::endl;
    std::cout << "Enter your first name : ";
    std::getline(std::cin, firstname);
    if (std::cin.eof())
        return ;
    if (!is_printble(firstname) || check_if_all_spaces(firstname) || firstname.size() == 0)
    {
        std::cout << "Error in input ... Aborting the ADD operation" << std::endl;
        return ;
    }
    system("clear");
    std::cout << "Creating your contact ..."<< std::endl;
    std::cout << "Enter your last name :";
    std::getline(std::cin, lastname);
    if (std::cin.eof())
        return ;
    if (!is_printble(lastname) || check_if_all_spaces(lastname) || lastname.size() == 0 )
    {
        std::cout << "Error in input ... Aborting the ADD operation" << std::endl;
        return ;
    }
    system("clear");
    std::cout << "Creating your contact ..."<< std::endl;
    std::cout << "Enter your nickname : ";
    std::getline(std::cin, nickname);
    if (std::cin.eof())
        return ;
    if (!is_printble(nickname) || check_if_all_spaces(nickname) || nickname.size() == 0)
    {
        std::cout << "Error in input ... Aborting the ADD operation" << std::endl;
        return ;
    }
    system("clear");
    std::cout << "Creating your contact ..." << std::endl;
    std::cout << "Enter your phone number : ";
    std::getline(std::cin, phonenbr);
    if (std::cin.eof())
        return ;
    if (!is_all_num(phonenbr) || phonenbr.size() == 0)
    {
        std::cout << "Error in input... Aborting the ADD operation" << std::endl;
        return ;
    }
    system("clear");
    std::cout << "Creating your contact ..."<< std::endl;
    std::cout << "Enter your Dark secret : ";
    std::getline(std::cin, darksecret);
    if (std::cin.eof())
        return ;
    if (!is_printble(darksecret) || check_if_all_spaces(darksecret) || darksecret.size() == 0)
    {
        std::cout << "Error in input ... Aborting the ADD operation" << std::endl;
        return ;
    }
    c[curr_nbr].set_first_name(firstname);
    c[curr_nbr].set_last_name(lastname);
    c[curr_nbr].set_nickname(nickname);
    c[curr_nbr].set_phone_nbr(phonenbr);
    c[curr_nbr].set_dark_secret(darksecret);
    c[curr_nbr].set_flag(1);
    curr_nbr++;
    if (con_nbr < 8)
        con_nbr++;
    std::cout << "Your contact has been uploaded successfully !" << std::endl;
}

void	PhoneBook::do_search()
{
    std::string tmp;
    int         chosen_i;

	if (con_nbr == 0)
    {
		std::cout << "Your PhoneBook is empty. Please add some contacts." << std::endl;
        return ;
    }
	int i = 0;
	while (i < con_nbr)
	{
        c[i].display_all(i);
        i++;
	}
    std::cout << "Enter an index to view more information about the contact you're searching for : ";
    std::getline(std::cin, tmp);
    while (tmp.size() == 0)
    {
        std::cout << "You entered nothing ! Please re-enter an index : ";
        std::getline(std::cin, tmp);
    }
    chosen_i = mini_atoi(tmp);
    if (chosen_i > con_nbr - 1 || chosen_i < 0)
    {
        system("clear");
        std::cout << "There is no contact existing in your PhoneBook with this index ... Aborting the SEARCH operation" << std::endl;
        return ;
    }
    system("clear");
    std::cout << std::endl << "First name : " << c[chosen_i].get_first_name() << std::endl;
    std::cout<< "Last name : " << c[chosen_i].get_last_name() << std::endl;
    std::cout<< "Nickname : " << c[chosen_i].get_nickname() << std::endl;
    std::cout<< "Phone number : " << c[chosen_i].get_phone_nbr() << std::endl;
    std::cout<< "Dark secret : " << c[chosen_i].get_dark_secret() << std::endl;
    std::cout << std::endl << std::endl << "Press an <ENTER> to continue ...";
    std::getline(std::cin, tmp);
    system("clear");
    return;
}
