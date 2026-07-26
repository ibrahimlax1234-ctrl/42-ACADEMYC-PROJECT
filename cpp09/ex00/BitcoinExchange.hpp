/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:33:13 by librahim          #+#    #+#             */
/*   Updated: 2025/12/08 09:46:09 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#define CSV_PATH "data.csv"

class BitcoinExchange 
{
    private:
        std::map<std::string, float>    t;
        std::string                     csv_file;
        std::string                     txt_file;
    public:
        BitcoinExchange();

        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &o);        
        BitcoinExchange& operator=(BitcoinExchange const& o);
    
    
        BitcoinExchange(std::string path);
    
        void loadcsv(std::string cvspath);
        void    process_inputfile(std::string txtpath);
        int run();
};


#endif
