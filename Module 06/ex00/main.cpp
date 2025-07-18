
#include <iostream>
#include <string>

enum DataType {INT, DOUBLE, FLOAT};

class ScalarConverter {
    private:
        ScalarConverter();
        ~ScalarConverter();
        
        static bool isChar(std::string &input);
        static bool isInt(std::string &input);
        static bool isDouble(std::string &input);
        static bool isFloat(std::string &input);
        static bool isSpecialLiteral(std::string &input, bool doubleCheck);
        
        static void handleAsChar(std::string &input);
        static void handleAsFloat(std::string &input);

        static bool validateSienNotation(std::string &input);
        static int  checkSign(std::string &input);
        static int  fractionLength(std::string &input);

    public:
        static void convert(std::string input);
};

int ScalarConverter::checkSign(std::string &input) {
    int start = 0;
    if (input[0] == '-' || input[0] == '+')
        start = 1;
    return start;
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

bool ScalarConverter::isChar(std::string &input) {
    return (input.length() == 1 && !isdigit(input[0]));
}

bool ScalarConverter::isInt(std::string &input) {
    if (!validateSienNotation(input))
        return false;
    int start = checkSign(input);
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

bool ScalarConverter::isSpecialLiteral(std::string &input, bool doubleCheck) {
    if (doubleCheck)
        return input == "nan" ||  input == "+inf" || input == "-inf";
    return input == "nanf" ||  input == "+inff" || input == "-inff";
}

// bool ScalarConverter::isDouble(std::string &input) {
//     if (!validateSienNotation(input))
//         return false;
//     if (isSpecialLiteral(input, true))
//         return true;
    
//     int start = checkSign(input);
//     bool sawDot = false;
//     bool sawFSymbol = false;
//     std::string allowed = "+f-eE";
//     for (int i = start; i < input.length(); i++) {
//         char c = input[i];
//         int pos = allowed.find(c);
//         if (isdigit(c) || pos == std::string::npos)
//             continue;
//         else if (c == '.') {
//             if (sawDot || !input[i+1]) { return false; }
//             sawDot = true;
//         }
//         return false;
//     }
//     return (sawDot ? true : false);
// }

bool ScalarConverter::isDouble(std::string &input){
    if(!validateSienNotation(input)) return false;
    if(isSpecialLiteral(input,true)) return true;

    bool sawDot = false;
    std::string allowed = "eE+-";
    for(int i = checkSign(input);i < input.length(); i++){
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


bool ScalarConverter::isFloat(std::string &input) {
    if (!validateSienNotation(input))
        return false;
    if (isSpecialLiteral(input, false))
        return true;
    
    int start = checkSign(input);
    bool sawDot = false;
    bool sawFSymbol = false;
    for (int i = start; i < input.length(); i++) {
        if (isdigit(input[i]))
            continue;
        else if (input[i] != '.' && input[i] != 'f')
            return false;
        else if (input[i] == '.') {
            if (sawDot || !input[i+1]) { return false; }
            sawDot = true;
        } else if (input[i] == 'f') {
            if (sawFSymbol || input[i+1] || !sawDot) {return false;}
            sawFSymbol = true;
        }
    }
    return (!sawFSymbol ? false : true);
}

#include <iomanip>
void ScalarConverter::handleAsChar(std::string &input) {
    std::cout << std::fixed << std::setprecision(1);
    bool displayFlag = isprint(input[0]);
    std::cout << "CHAR  : " << (displayFlag ? input : "Non Display Able") << std::endl;
    std::cout << "INT   : " << static_cast<int>(input[0]) << std::endl;
    std::cout << "DOUBLE: " << static_cast<double>(input[0]) << std::endl;
    std::cout << "DOUBLE: " << static_cast<double>(input[0]) << "f" << std::endl;
}


void ScalarConverter::handleAsFloat(std::string &input) {
    float value = std::strtof(input.c_str(), NULL);

    if (value >= 0 && value <= 127 && isprint(value))
        std::cout << "CHAR  : '" << static_cast<char>(value) << "'" << std::endl;
    else if (value >= 0 && value <= 32 || value == 127)
        std::cout << "CHAR  : Non displayable" << std::endl;
    else
        std::cout << "CHAR  : Impossible" << std::endl;
        
    // std::cout << std::fixed << std::setprecision(20);
    for (int i = 0; i < input.length(); i++)
        if (input[i] == '.')
            std::cout << std::fixed << std::setprecision(1);
    
    std::cout << "int min is: " << INT_MAX << std::endl;
    std::cout << "size of float and double here: " << sizeof(double) << std::endl;
    if (value >= INT_MIN && value <= INT_MAX)
        std::cout << "INT   : " << static_cast<int>(value) << std::endl;
    else
        std::cout << "INT   : Impossible" << std::endl;
    std::cout << "FLOAT : " << value << "f" << std::endl;
    std::cout << "DOUBLE: " << static_cast<double>(value) << std::endl;
}



void ScalarConverter::convert(std::string input) {
    if (input.empty()) {
        std::cout << "Error: Cant't Convert An Empty String!\n";
        return ;
    }
    bool (*typeCheckers[])(std::string &input) = {isChar, isInt, isDouble, isFloat};
    for (int i = 0; i < sizeof(typeCheckers) / sizeof(typeCheckers[0]); i++) {
        if (typeCheckers[i](input)) {
            std::cout << "#TYPE VALID: OK\n";
            break ;
        }
    }
    

    if (isChar(input)) {
        handleAsChar(input);
    } else if (isInt(input)) {
        std::cout << "# type: INT\n";
    } else if (isFloat(input)) {
        handleAsFloat(input);
    } else if (isDouble(input)) {
        std::cout << "# type: Double\n";
    } else
        std::cout << "type: impossible\n";
}
#include <cstdlib>
int main(int argc, char *argv[])
{
    // std::cout << static_cast<float>(inf);
    float f = 3.5e38f;
    std::cout << INFINITY;
    // if (argc == 2)
    //     return ScalarConverter::convert(argv[1]), 0;
    // std::cout << "Error: Number Of Arguments!\n";
    // std::string input = argv[1];
    // float result = std::strtof(input.c_str(), nullptr);
    // std::cout << result << std::endl;
    return 0;
}


// -1.1e-1 1.0 1.02f -5.0
