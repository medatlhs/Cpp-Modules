#pragma once 

#include <iostream>
#include <map>
#include <string>
#include <stdexcept> 

class BitcoinExchange {
    private:
        std::map<std::string, double>  _data;
        bool isValidDate(const std::string& date);
        bool isValidValue(const std::string& value);
        std::string trimSpaces(const std::string &s);
        int     toInt(const std::string &str);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other); 
        ~BitcoinExchange();

        void    loadData(const std::string& dataFile);
        void    processInputFile(const std::string& inputFile);
};
