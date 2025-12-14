#include "RPN.hpp"

RPN::RPN() { } 

RPN::RPN(const RPN& other) : _stack(other._stack) { } 

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {  } 

bool RPN::isOperator(const std::string& token) { 
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::operation(int first, int second, const std::string& oper) { 
    if (oper == "+") 
        return first + second;
    else if (oper == "-")
        return first - second;
    else if (oper == "*")
        return first * second;
    else if (oper == "/") { 
        if (second == 0) 
            throw std::runtime_error("ERROR"); 
        return first / second;
    } 
    throw std::runtime_error("ERROR");
}

int RPN::calculate(const std::string& line) {
    std::stringstream ss(line);
    std::string token;
    while (ss >> token)
    {
        if (token.length() != 1)
            throw std::runtime_error("ERROR");

        if (isOperator(token))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("ERROR");

            int second = _stack.top();
            _stack.pop();
            int first = _stack.top(); 
            _stack.pop();

            int result;
            result = operation(first, second, token);
            _stack.push(result);
        } else if (isdigit(token[0]))
        {
            std::stringstream converter(token);
            int value;
            converter >> value;
            _stack.push(value);
        } else 
        {
            throw std::runtime_error("ERROR");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("ERROR");
    return _stack.top();
}
