/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 06:20:05 by librahim          #+#    #+#             */
/*   Updated: 2025/05/12 23:33:11 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void    process_line(std::string& l, std::string f_s, std::string s_s)
{
    int         first_char;
    std::string tmp = "";

    first_char = l.find(f_s);
    while (first_char != -1)
    {
        tmp.append(l.substr(0, first_char));
        tmp.append(s_s);
        tmp.append(l.substr(first_char + f_s.size()));
        l = tmp;
        tmp = "";
        first_char = l.find(f_s);
    }
}


int main(int arc, char *arv[])
{
    if (arc != 4)
    {
	    std::cout << "Error : Args number must be 3" <<std::endl;
        return 1;
    }


    std::string     first_s = arv[2];
    std::string     second_s = arv[3];
    if (first_s.size() == 0 || second_s.size() == 0)
    {
        std::cout << "Error: empty string detected in 2nd or 3rd arg" <<std::endl;
        return 1;
    }


    std::string     in_file_name = arv[1];
    std::string     out_file_name = in_file_name;
    out_file_name.append(".replace");
    std::ifstream   ifile(in_file_name);

    if (ifile.is_open() == false)
    {
        std::cout << "Error: cannot open the input file, enter a valid file pls." << std::endl;
        return 1;
    }

    std::ofstream   ofile(out_file_name);
    if (ofile.is_open() == false)
    {
        std::cout << "Error opening output" << std::endl;
        ifile.close();
        return 1;
    }


    std::string line;
    while (!ifile.eof())
    {
        std::getline(ifile, line);
        process_line(line, first_s, second_s);
        ofile << line << std::endl;
    }

    ifile.close();
    ofile.close();

    return 0;
}
