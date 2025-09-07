#pragma once

#include <iostream>
#include <string>
#include <iomanip> 

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(ScalarConverter const &other);
        ~ScalarConverter();

    public:
        static void convert(const std::string &input);
        static bool ispseudoLiteral(const std::string &literal);
        static bool isValidLiteral(std::string &literal);
};
