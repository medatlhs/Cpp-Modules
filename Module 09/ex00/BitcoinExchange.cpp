#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    _data = other._data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        _data = other._data;
    return *this;
}

void BitcoinExchange::loadData(const std::string &dataFile)
{
    std::ifstream file(dataFile);
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl; 
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string value;
        getline(ss, date, ',');
        getline(ss, value);
        std::stringstream ss_value(value);
        double rate;
        ss_value >> rate;
        _data[date] = rate;
    }
    file.close();
}

std::string BitcoinExchange::trimSpaces(const std::string &s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    size_t end = s.find_last_not_of(" \t\n\r");
    return s.substr(start, end - start + 1);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    std::string trimmedDate = trimSpaces(date);
    if (trimmedDate.length() != 10 || trimmedDate[4] != '-' || trimmedDate[7] != '-') 
        return false; 
    int year = std::atoi(trimmedDate.substr(0, 4).c_str());
    int month = std::atoi(trimmedDate.substr(5, 2).c_str());
    int day = std::atoi(trimmedDate.substr(8, 2).c_str()); 
 
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false; 

    if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
        return false;

    if (month == 2)  {
        bool isLeapYear =  ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
        if (isLeapYear && day > 29)
            return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(const std::string &value)
{
    std::stringstream ss(trimSpaces(value));
    double val;
    ss >> val;
    if (ss.fail()) return false;
    char leftover;
    if (ss >> leftover) return false;
    return true;
}


void BitcoinExchange::processInputFile(const std::string &inputFile)
{
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {

        std::stringstream ss(line);
        std::string date; 
        std::string valueAsStr;
        getline(ss, date, '|'); 
        getline(ss, valueAsStr);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        if (!isValidValue(valueAsStr)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value;
        std::stringstream ssValue(valueAsStr);
        ssValue >> value;
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        } 
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, double>::iterator it = _data.lower_bound(trimSpaces(date));
        if (it == _data.begin() && it->first != trimSpaces(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue ;
        } else if (it == _data.end() || it->first != trimSpaces(date))
            --it;
    
        double rate = it->second;
        double result = value * rate;
        std::cout << trimSpaces(date) << " => " << value << " = " << result << std::endl;
    }
    file.close();
}