/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:32:49 by librahim          #+#    #+#             */
/*   Updated: 2025/12/10 08:48:53 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

void BitcoinExchange::loadcsv(std::string cvspath)
{
    std::ifstream file(cvspath.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open csv file." << std::endl;
        throw std::exception();
    }
    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
            continue;
        if (!line.find("date"))
            continue ;
        size_t coma = line.find(',');
        if (coma == std::string::npos)
            continue;
        std::string date = line.substr(0, coma);
        std::string value = line.substr(coma + 1);
        t[date] = std::atof(value.c_str());
    }

    file.close();
}


int validatedate(std::string& d)
{
    if (d.empty())
        return 1;
    size_t first = d.find_first_not_of(" ");
    size_t last = d.find_last_not_of(" ");
    if (first == std::string::npos)
        return 1;
    d = d.substr(first, (last - first + 1));
    //10 dyal characters YYYY-MM-DD
    if (d.size() != 10)
        return 1;
    if (d[4] != '-' || d[7] != '-')
        return 1;
    int year = std::atoi(d.substr(0, 4).c_str());
    int month = std::atoi(d.substr(5, 2).c_str());
    int day = std::atoi(d.substr(8, 2).c_str());
    
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return 1;
    // std::cout << year<<" " << month << " " << day << std::endl;
    // while (1);
    return 0;
}


void BitcoinExchange::process_inputfile(std::string txtpath)
{
    std::ifstream file(txtpath.c_str());
    size_t del;
    float val;

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        throw std::exception();
    }
    // std::cout <<"hello from process_incput fct";
    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
            continue ;
        if (!line.find("date"))
            continue ;
        del = line.find('|');
        if (del == std::string::npos)
        {
            std::cerr << "Error: bad input =>" <<line<<std::endl;
            continue;
        }
        std::string date = line.substr(0, del);
        std::string value = line.substr(del + 1);
        if (validatedate(date))
        {
            std::cerr << "Error: bad input =>" <<line<<std::endl;
            continue;
        }
        val = std::atof(value.c_str());
        if (val < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (val > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string, float>::iterator pt = this->t.upper_bound(date);
        if (pt == this->t.begin())
        {
            std::cerr << "Error: no value" << std::endl;
            continue;
        }
        --pt;
        std::cout << date << " => " << val << " = " << std::fixed  << std::setprecision(4)<< (val * pt->second) << std::endl;
    }
    file.close();
}


int BitcoinExchange::run()
{
    if (this->csv_file.size() >= 4)
    {
        // V S C .
        if (!(csv_file[csv_file.size() - 1] == 'v' &&
            csv_file[csv_file.size() - 2] == 's' &&
            csv_file[csv_file.size() - 3] == 'c'&&
            csv_file[csv_file.size() - 4] == '.'))
            throw std::exception();
    }
    else
    {
        std::cerr << "Error : csv file extension invalid" << std::endl;
        throw std::exception();
    }
    loadcsv(csv_file);
    process_inputfile(txt_file);
    return 1;
}


BitcoinExchange::BitcoinExchange(std::string path)
{
    this->txt_file = path;
    this->csv_file = CSV_PATH;
}


BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &o)
{
    if (this != &o)
    {
        this->t = o.t;
        this->csv_file =o.csv_file;
        this->txt_file =o.txt_file;
    }
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& o)
{
    if (this != &o)
    {
        this->t = o.t;
        this->csv_file =o.csv_file;
        this->txt_file =o.txt_file;
    }
    return *this;
}
