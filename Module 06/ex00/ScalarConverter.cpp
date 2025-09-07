#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter &copy) { 
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {  
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {  }

bool ScalarConverter::ispseudoLiteral(const std::string &literal) {
    if (literal == "nan" ||  literal == "+inf" || literal == "-inf" 
        || literal == "nanf" ||  literal == "+inff" || literal == "-inff") {
        return true;
    }
    return false;
}

void ScalarConverter::convert(const std::string &input) {
    bool isPseudoLiteral = false;
    double  value = 0.0;

    std::string literal = input;
    if (!isValidLiteral(literal) || literal.empty())
        throw std::invalid_argument("Invalid Literal!");

    if (ispseudoLiteral(literal)) {
        std::cout << "here\n";
        isPseudoLiteral = true;
    } else if (literal.length() == 1 && !std::isdigit(literal[0])) {
        value = literal[0];
    } else
        value = std::atof(literal.c_str());
    
    // CHAR
    std::cout << "char: ";
    if ( isPseudoLiteral || value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(value))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";

    // INT
    std::cout << "int: ";
    if (isPseudoLiteral || (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()))
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << std::endl;

    // FLOAT
    std::cout << "float: ";
    if (literal == "nan" || literal == "nanf")
        std::cout << "nanf\n";
    else if (literal == "+inf" || literal == "+inff")
        std::cout << "+inff\n";
    else if (literal == "-inf" || literal == "-inff")
        std::cout << "-inff\n";
    else {
        float fval = static_cast<float>(value);
        std::cout << std::fixed << std::setprecision(1) << fval << "f\n";
    }

    // DOUBLE
    std::cout << "double: ";
    if (literal == "nan" || literal == "nanf")
        std::cout << "nan\n";
    else if (literal == "+inf" || literal == "+inff")
        std::cout << "+inf\n";
    else if (literal == "-inf" || literal == "-inff")
        std::cout << "-inf\n";
    else
        std::cout << std::fixed << std::setprecision(1) << value << "\n";
}

bool ScalarConverter::isValidLiteral(std::string &literal) {
    if (literal.empty()) return false;

    size_t begin, end;
    for (begin = 0; std::isspace(literal[begin]); begin++);
    for (end = literal.length() - 1; std::isspace(literal[end]); end--);
    literal = literal.substr(begin, end - begin + 1);

    if (ispseudoLiteral(literal)) return true;

    if (literal.length() == 1 && !std::isdigit(literal[0])) return true;

    int start = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
    bool sawDot = false, sawF = false;
    for (size_t i = start; i < literal.length(); ++i) {
        char c = literal[i];
        if (c == '.') {
            if (sawDot || i == 0 || i == literal.length() - 1)
                return false;
            sawDot = true;
        } else if (c == 'f' || c == 'F') {
            if (sawF || i != (literal.length() - 1) || !sawDot)
                return false;
            sawF = true;
        } else if (!std::isdigit(c) || std::isspace(c))
            return false;
    }
    return true;
}

/*
Some casts don’t get fully validated until the program is running.
Example: dynamic_cast.
*/