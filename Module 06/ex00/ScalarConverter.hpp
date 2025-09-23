#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter {
    private:
        static bool _isCharlit(const std::string &literal);
        static bool _isPseudolit(const std::string &literal);
        static bool _isNumericlit(std::string &literal, double &value);
        
        static void _printChar(double value, bool isPseudo);
        static void _printInt(double value, bool isPseudo);
        static void _printFloat(const std::string &literal, double value);
        static void _printDouble(const std::string &literal, double value);

        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter&copy);
        ScalarConverter& operator=(const ScalarConverter&copy);

    public:
        static void convert(const std::string &literal);
};
