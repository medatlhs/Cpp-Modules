#pragma once 

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
    private:
        std::map<std::string, double>  _data;
        bool isValidDate(const std::string& date);
        bool isValidValue(const std::string& value);
        std::string trimSpaces(const std::string &s);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other); 
        ~BitcoinExchange();

        void    loadData(const std::string& dataFile);
        void    processInputFile(const std::string& inputFile);
};
