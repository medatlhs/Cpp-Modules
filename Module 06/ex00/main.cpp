
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
        static bool checkScNotation(std::string &input);
        static int  checkSign(std::string &input); 

    public:
        static void convert(std::string input);
};

int ScalarConverter::checkSign(std::string &input) {
    int start = 0;
    if (input[0] == '-' || input[0] == '+') {
        start = 1;
    }
    return start;
}

bool ScalarConverter::checkScNotation(std::string &input) {
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
    if (!checkScNotation(input))
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

bool ScalarConverter::isDouble(std::string &input) {
    if (!checkScNotation(input))
        return false;
    if (isSpecialLiteral(input, true))
        true;
    
    int start = checkSign(input);
    bool sawDot = false;
    bool sawFSymbol = false;
    for (int i = start; i < input.length(); i++) {
        char c = input[i];
        if (isdigit(input[i]))
            continue;
        else if (input[i] == '.') {
            if (sawDot || !input[i+1]) { return false; }
            sawDot = true;
        } else if (c == 'f' || c == 'e' 
                || c == 'E' || c == '-' || c == '+') {
            continue;
        } else
            return false;
    }
    return (sawDot ? true : false);
}

bool ScalarConverter::isFloat(std::string &input) {
    if (!checkScNotation(input))
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

void ScalarConverter::convert(std::string input) {
    if (input.empty()) {
        std::cout << "Error: Cant't Convert An Empty String!\n";
        return ;
    }

    // std::cout << "check if int: " <<(isInt(input) ? "true" : "false") << std::endl;
    // std::cout << "check if Float: " <<(isFloat(input) ? "true" : "false") << std::endl;
    // std::cout << "check if double: " <<(isDouble(input) ? "true" : "false") << std::endl;
    // std::cout << "check if char: " <<(isChar(input) ? "true" : "false") << std::endl;

    if (isChar(input)) {
        std::cout << "# type: CHAR\n";
    } else if (isFloat(input)) {
        std::cout << "# type: FLOAT\n";
    } else if (isDouble(input)) {
        std::cout << "# type: DOUBLE\n";
    } else if (isInt(input)) {
        std::cout << "# type: INT\n";
    } else
        std::cout << "type: impossible\n";
    
    // handle as char
    /*
        
    */
}

#include <iomanip>
int main(int argc, char const *argv[])
{
    (void)argc;
    try {
        std::string input = argv[1];
        ScalarConverter::convert(input);
    }
    catch(...) {
        std::cerr << "Too few number of arguments ma man!" << '\n';    
    }
    // fucking around to find out
    // float x = 2E; // false
    double x = 1e-1;

    std::cout << std::fixed << static_cast<double>(x) << std::endl;
    return 0;
}


// -1.1e-1 1.0 1.02f -5.0
