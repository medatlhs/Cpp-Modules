#pragma once

#include <sstream>
#include <stdexcept>
#include <stack>
#include <string>
#include <iostream>
#include <list>

class RPN {
    private:
        std::stack<int, std::list<int> > _stack;
        bool isOperator(const std::string& token);
        int  operation(int first, int second, const std::string& oper);

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        int calculate(const std::string& line);
};