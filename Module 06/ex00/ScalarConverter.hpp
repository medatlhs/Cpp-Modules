#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER8HPP
#include <iostream>
#include <cstdlib> // atof
#include <climits>  // for INT_MIN and INT_MAX
#include <cmath>    // for isnan, isinf
enum TYPES {INT, FLOAT, DOUBLE, CHAR};
class ScalarConverter
{
    public:
        static void convert(std::string input);

        static void handleFloat(std::string &input);
        static void handleInt(std::string &input);
        static void handleDouble(std::string &input);
        static void handleChar(std::string &input);

        static bool isFloat(std::string &input);
        static bool isDouble(std::string &input);
        static bool isInt(std::string &input);
        static bool isChar(std::string &input);
        static bool isSpecialLiteral(std::string &input, TYPES type);

        static bool validateSienNotation(std::string &input);
        static int  fractionLength(std::string &input);
        static void logToConsole(char c, int i, double d, float f, TYPES ty);

    private:
        ScalarConverter();
        ~ScalarConverter();
};

#endif