
#include <iostream>

enum TYPES = {CHAR, INT, FLOAT, DOUBLE};

class ScalarConverter {
    private:
        std::string _input;
        TYPES       _types;
        
    public:
    ScalarConverter(std::string input);

    void checkType(void);
};

void ScalarConverter::convert(std::string input) {
    this->checkType();
}











int main(int argc, char const *argv[])
{
    ScalarConverter::convert("2002");
    return 0;
}
