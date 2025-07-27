#include "ScalarConverter.hpp"

int isSpecialLiteral(std::string &input) {
    if (input == "nan" ||  input == "+inf" || input == "-inf")
        return TYPES::DOUBLE;
    if (input == "nanf" ||  input == "+inff" || input == "-inff")
        return TYPES::FLOAT;
    return TYPES::OTHER;
}

void logToConsole(std::string &input) {
    int     isSpeacial = isSpecialLiteral(input);
    bool    isChar = (input.length() == 1 && !isdigit(input[0]));
    double  value;
    if (!isChar)
        value = std::atof(input.c_str());
    else
        value = input[0];
    std::cout << "value is: " << value << std::endl;
    //CHAR
    std::cout << value << std::endl;
    std::cout << "#CHAR: ";
    if (!isChar && (value >= 0 && value <= 31  || value == 127))
        std::cout << "non displayable\n";
    else if (!isChar && (value >= 32 && value <= 126))
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "impossible" << std::endl;
    //INT
    std::cout << "#INT: ";
    if (isSpeacial || value >= INT_MAX || value <= INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
    //FLOAT
    std::cout << "#FLOAT: ";
    if (isSpeacial != TYPES::OTHER) {
        std::cout << input;
        if (isSpeacial == DOUBLE || input == "nan")
            std::cout << "f";
    }
    else {
        std::cout << static_cast<float>(value);
        if (value == static_cast<int>(value))
            std::cout << ".0";
        std::cout << "f";
    }
    std::cout << std::endl;
    //DOUBLE
    std::cout << "#DOUBLE: ";
    if (isSpeacial == TYPES::DOUBLE)
        std::cout << input;
    else if (isSpeacial == TYPES::FLOAT)
        std::cout << input.substr(0, input.length() - 1);
    else {
        std::cout << value;
        if (value == static_cast<int>(value))
            std::cout << ".0";
    }
    std::cout << std::endl;
}

bool validateInput(std::string &input) {
    if (input.empty())
        return false;
    if (isSpecialLiteral(input) || (input.length() == 1 && !std::isdigit(input[0])))
        return true;
    int signNum = input[0] == '-' || input[0] == '+';
    bool sawE = false, sawFloat = false, sawPoint = false;
    int len = input.length();
    for (int i = signNum; i < len; i++) {
        char c = input[i];
        if (c == '-' || c == '+') {
            if ((input[i-1] != 'e' && input[i-1] != 'E') || signNum == 2)
                return false;
            if (i == len-1 || !isdigit(input[i+1]))
                return false;
            signNum++;
        } else if (c == 'e' || c == 'E') {
            if (i == 1 || (!input[i+1] || (input[i-1] != '.' && !isdigit(input[i-1]))))
                return false;
            sawE = true;
        } else if (c == 'f' || c == 'F') {
            if (sawFloat || i != len-1) return false;
            sawFloat = true;
        } else if (c == '.') {
            if (sawPoint || i == 0 || i == len-1) return false;
            sawPoint = true;
        } else if (!isdigit(c) && c!='e' && c!='+' && c!='-' && c!='E' && c!='.' && c!='f')
            return false;
    }
    return true;
}

void ScalarConverter::convert(std::string input) {
    if (validateInput(input))
        logToConsole(input);
    else
        std::cout << "not valid\n";
}
