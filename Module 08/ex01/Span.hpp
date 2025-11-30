#pragma once 
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <climits>

class Span {
    private:
        unsigned int _maxSize;
        std::vector<int> _data; 
     
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
    
        unsigned int shortestSpan() const ; 
        unsigned int longestSpan() const ;

        template <typename Iter>
        void addNumber(Iter begin, Iter end) {
            int rangeSize = std::distance(begin, end);
            if (_data.size() + rangeSize > _maxSize)
                throw SpanFullException();
            _data.insert(_data.end(), begin, end);
        }

        class SpanFullException : public std::exception {
            public:
                const char* what() const throw();
        };

        class NotEnoughNumbersException : public std::exception {
            public:
                const char* what() const throw();
        };
};