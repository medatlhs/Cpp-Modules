
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

        static bool validateSienNotation(std::string &input);
        static int  checkSign(std::string &input); 

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
    return (input.length() == 1 && !isdigit(input[0]) && isprint(input[0]));
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

void ScalarConverter::handleAsChar(std::string &input) {
    std::cout << "CHAR: " << input[0] << std::endl;
    std::cout << "INT : " << static_cast<int>(input[0]) << std::endl;
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
        std::cout << "# type: FLOAT\n";
    } else if (isDouble(input)) {
        std::cout << "# type: Double\n";
    } else
        std::cout << "type: impossible\n";
}

int main(int argc, char const *argv[])
{
    if (argc == 2)
        return ScalarConverter::convert(argv[1]), 0;
    std::cout << "Error: Number Of Arguments!\n";
    return 1;
}


// -1.1e-1 1.0 1.02f -5.0
