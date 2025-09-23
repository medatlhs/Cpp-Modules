#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

void ScalarConverter::convert(const std::string &literal) {
    std::string literaltrim = literal;
    size_t begin, end;
    for (begin = 0; std::isspace(literal[begin]); begin++);
    for (end = literal.length() - 1; std::isspace(literal[end]); end--);
    literaltrim = literal.substr(begin, end - begin + 1);
    if (literaltrim.empty())
        throw std::invalid_argument("Empty literal!");

    double value = 0.0;
    bool   isPseudo = _isPseudolit(literaltrim);
    if (_isCharlit(literaltrim) && !isPseudo)
        value = static_cast<double>(literaltrim[0]);
    else if (!_isNumericlit(literaltrim, value) && !isPseudo)
        throw std::invalid_argument("Invalid literal!");
    
    _printChar(value, isPseudo);
    _printInt(value, isPseudo);
    _printFloat(literaltrim, value);
    _printDouble(literaltrim, value);
}

// Checkers
bool ScalarConverter::_isCharlit(const std::string &literal) {
    return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool ScalarConverter::_isPseudolit(const std::string &literal) {
    return (literal == "nan" || literal == "+inf" || literal == "-inf"
            || literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool ScalarConverter::_isNumericlit(std::string &literal, double &value) {
    bool isfloat = false;
    size_t len = literal.length();
    if (literal[len-1]=='f' || literal[len-1]=='F') {
        isfloat = true;
        literal = literal.substr(0, literal.length() - 1);
    }
    size_t pos = literal.find('.');
    if ((isfloat && pos == std::string::npos ) || !pos || pos == (len-1) )
        return false;
    
    std::stringstream ss(literal);
    ss >> value;
    if (!ss.eof()) return false;
    return true;
}

// Printers
void ScalarConverter::_printChar(double value, bool isPseudo) {
    std::cout << "char: ";
    if (isPseudo || value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(value))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";
}

void ScalarConverter::_printInt(double value, bool isPseudo) {
    std::cout << "int: ";
    if (isPseudo || value < std::numeric_limits<int>::min() 
        || value > std::numeric_limits<int>::max()) {
        std::cout << "impossible\n";    
    } else
        std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::_printFloat(const std::string &literal, double value) {
    std::cout << "float: ";
    if (literal == "nan" || literal == "nanf") std::cout << "nanf\n";
    else if (literal == "+inf" || literal == "+inff") std::cout << "+inff\n";
    else if (literal == "-inf" || literal == "-inff") std::cout << "-inff\n";
    else {
        std::cout << std::fixed << static_cast<float>(value);
        std::cout << "f" << std::endl;
    }
}

void ScalarConverter::_printDouble(const std::string &literal, double value) {
    std::cout << "double: ";
    if (literal == "nan" || literal == "nanf") std::cout << "nan\n";
    else if (literal == "+inf" || literal == "+inff") std::cout << "+inf\n";
    else if (literal == "-inf" || literal == "-inff") std::cout << "-inf\n";
    else
        std::cout << std::fixed << value << std::endl;
}
