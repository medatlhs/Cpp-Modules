#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(std::string &input) {
    return (input.length() == 1 && !isdigit(input[0]));
}

void ScalarConverter::convert(std::string input) {
    else if (isFloat(input)) {
        std::cout << "he is a valid float\n";
        handleFloat(input);
    } else if (isDouble(input)) {
        std::cout << "he is a valid double\n";
        handleDouble(input);
    } else if (isInt(input)) {
        std::cout << "Motherfucler is an INT\n";
    } else if (isChar(input)) {
        std::cout << "he is a char\n";
        // handleChar(input);
    } else
        std::cout << "impossible\n";
}

bool ScalarConverter::isInt(std::string &input) {
    if (!validateSienNotation(input))
        return false;
    int start = input[0] == '-' || input[0] == '+';
    for (int i = start; i < input.length(); i++) {
        char c = input[i];
        if (!isdigit(c)) {
            if (c=='.') {
                return false;
            } else if (c=='e' || c=='E' || c=='-'||c=='+')
                continue;
            return false;
        }
    }
    return true;
}

void ScalarConverter::handleChar(std::string &input) {
    std::cout << "#CHAR: " << static_cast<char>(input[0]) << std::endl;
    std::cout << "#INT : " << static_cast<>
}

bool ScalarConverter::isFloat(std::string &input) {
    if (!validateSienNotation(input)) return false;
    if (isSpecialLiteral(input, TYPES::FLOAT)) return true;
    int start = input[0] == '-' || input[0] == '+';

    bool sawDot = false, sawFSymbol = false;
    for (int i = start; i < input.length(); i++) {
        if (isdigit(input[i]))
            continue;
        else if (input[i] == '.') {
            if (sawDot || !input[i+1]) { return false; }
            sawDot = true;
        } else if (input[i] == 'f') {
            if (sawFSymbol || i != input.length()-1 || !sawDot) {return false;}
            sawFSymbol = true;
        }
    }
    return sawFSymbol;
}

// already checked if valid float
void ScalarConverter::handleFloat(std::string &input) {
    float fValue = std::atof(input.c_str());

    std::cout << "#CHAR: ";
    if (fValue >= 0 && fValue <= 31 || fValue == 127)
        std::cout << "Non DisplayAble\n";
    else if (fValue >= 32 && fValue <= 126)
        std::cout << "'" << static_cast<char>(fValue) << "'" << std::endl;
    else
        std::cout << "Impossible" << std::endl;

    std::cout << "#INT: ";
    if (fValue >= INT_MAX || fValue <= INT_MIN)
        std::cout << "Impossible\n";
    else
        std::cout << static_cast<int>(fValue) << std::endl;

    std::cout << "#DOUBLE: ";
    std::cout << static_cast<double>(fValue);
    if (input.find('.') == std::string::npos)
        std::cout << ".0";
    std::cout << std::endl;
    std::cout << "#FLOAT: " << fValue;
    if (input.find('.') == std::string::npos)
        std::cout << ".0";
    std::cout << "f\n";
}

bool ScalarConverter::isDouble(std::string &input) {
    if(!validateSienNotation(input)) return false;
    if(isSpecialLiteral(input, TYPES::DOUBLE)) return true;

    bool sawDot = false;
    std::string allowed = "eE+-";
    int start = input[0] == '-' || input[0] == '+';
    for(int i = start; i < input.length(); i++){
        char c = input[i];
        if(isdigit(c)) continue;
        else if (c == 'f') return false;
        else if(c == '.') {
            if (sawDot || i == input.length()-1) {return false;}
            sawDot = true;
        } else if(allowed.find(c) != std::string::npos) continue;
        else
            return false;
    }
    return sawDot;
}


bool ScalarConverter::isSpecialLiteral(std::string &input, TYPES type) {
    if (type == TYPES::FLOAT)
        return input == "nan" ||  input == "+inf" || input == "-inf";
    return input == "nanf" ||  input == "+inff" || input == "-inff";
}

bool ScalarConverter::validateSienNotation(std::string &input) {
    bool sawEflag = false;
    for (int i = 0; i < input.length(); i++) {
        if ((input[i] == '-' || input[i] == '+') && i != 0) {
            if (input[i-1] != 'e' && input[i-1] != 'E')
                return false;
        }
        if (input[i] == 'e' || input[i] == 'E') {
            if (i == 0 || !input[i+1] || input[i+1] == 'f' || sawEflag)
                return false;
            sawEflag = true;
            continue ;
        }
    }
    return true;
}

void ScalarConverter::handleDouble(std::string &input) {
    double dValue = std::atof(input.c_str());

    std::cout << "#CHAR: ";
    if ((dValue >= 0 && dValue <= 31) || dValue == 127)
        std::cout << "Non DisplayAble\n";
    else if (dValue >= 32 && dValue <= 126)
        std::cout << "'" << static_cast<char>(dValue) << "'" << std::endl;
    else
        std::cout << "Impossible" << std::endl;

    std::cout << "#INT: ";
    if (dValue > INT_MAX || dValue < INT_MIN)
        std::cout << "Impossible\n";
    else
        std::cout << static_cast<int>(dValue) << std::endl;

    std::cout << "#FLOAT: ";
    float f = static_cast<float>(dValue);
    std::cout << f;
    if (input.find('.') == std::string::npos)
        std::cout << ".0";
    std::cout << "f\n";

    std::cout << "#DOUBLE: ";
    std::cout << dValue;
    if (input.find('.') == std::string::npos)
        std::cout << ".0";
    std::cout << std::endl;
}

