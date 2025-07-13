
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
        static bool checkIfValidNumber(std::string &input, DataType type);
    
    public:
        static void convert(std::string input);
};

// std::string ScalarConverter::lessSpaces(std::string &input) {
//     return "";
// }

bool ScalarConverter::checkIfValidNumber(std::string &input, DataType type) {
    int dotsNum = 0, signsNum = 0, scienNotation = 0, floatSym = 0;
    for (int i = 0; (i < input.length()); i++) {
        if (type == INT && !isdigit(input[i]) && input[i] != '.' && input[i] != '+' && input[i] != '-')
            return false;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == 'e' || input[i] == 'E') {
                if (!input[i+1] || scienNotation) { return false; }
                scienNotation++;
            }
        }
        
        // std::string newInput = ScalarConverter::lessSpaces(input);
        if (input[i] == '+' || input[i] == '-') { // for all data types 
            if (i != 0 && type == INT) { return false; }
            else if (signsNum && input[i-1] != 'e' && input[i-1] != 'E' || signsNum == 2) {return false;}
            signsNum++;
        }  else if (input[i] == '.') { // for all data types
            if (!input[i+1] || dotsNum) { return false; }
            dotsNum++;
        }
    }

    return true;
}
// 1e2 eE2 -1e-2  1E-1  1E -1e
bool ScalarConverter::isChar(std::string &input) {
    return (input.length() == 1 && !isdigit(input[0]) && isprint(input[0]));
}

bool ScalarConverter::isInt(std::string &input) {
   return checkIfValidNumber(input, DataType::INT);
//    for (int i = 0; i < input.length(); i++)
//    {
//     if (!isdigit(input[i]) && input[i] != '.' && input[i] != '+' && input[i] != '-' && type == INT)
//             return false;
//    }
   
}

bool ScalarConverter::isDouble(std::string &input) {
    return checkIfValidNumber(input, DataType::DOUBLE);
}

bool ScalarConverter::isFloat(std::string &input) {
    return checkIfValidNumber(input, DataType::FLOAT);
}

void ScalarConverter::convert(std::string input) {
    if (input.empty()) {
        std::cout << "Error: Cant't Convert An Empty String!\n";
        return ;
    }

    std::cout << "check if int: " <<(isInt(input) ? "true" : "false") << std::endl;
    std::cout << "check if double: " <<(isDouble(input) ? "true" : "false") << std::endl;
    std::cout << "check if char: " <<(isChar(input) ? "true" : "false") << std::endl;

    if (isChar(input)) {
        std::cout << "# type: CHAR\n";
        
    } else if (isInt(input)) {
        std::cout << "# type: INT\n";
    } else if (isDouble(input)) {

    } else
        std::cout << "type: impossible\n";

}

#include <iomanip>
int main(int argc, char const *argv[])
{
    (void)argc;
    try {
        std::string input = argv[1];
        std::cout << "passed arg: " << input << std::endl;
        ScalarConverter::convert(input);
    }
    catch(...) {
        std::cerr << "Too few number of arguments ma man!" << '\n';    
    }
    // fucking around to find out
    // float x = 2E; // false
    float x = -12e1;

    std::cout << std::fixed << static_cast<double>(x) << std::endl;
    return 0;
}


// 1337 24 1 0 00 1.0 1.02f -1 -2 -5.0
