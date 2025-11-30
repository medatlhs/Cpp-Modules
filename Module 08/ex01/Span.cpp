#include "./Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) { }

Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data) { }

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

Span::~Span() { }

void Span::addNumber(int number) {
    if (_data.size() >= _maxSize)
        throw SpanFullException();
    _data.push_back(number);
}

unsigned int Span::shortestSpan() const 
{
    if (_data.size() <= 1)
        throw NotEnoughNumbersException();
  
    std::vector<int> sortedData = _data;
    std::sort(sortedData.begin(), sortedData.end());
 
    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sortedData.size(); ++i)
    {
        unsigned int span = sortedData[i] - sortedData[i - 1];
        if (span < minSpan) 
            minSpan = span; 
    }
    return minSpan;
}

unsigned int Span::longestSpan() const 
{
    if (_data.size() <= 1)
        throw NotEnoughNumbersException();
    
    int minElement = *std::min_element(_data.begin(), _data.end());
    int maxElement = *std::max_element(_data.begin(), _data.end());
    
    return (maxElement - minElement);
}

const char *Span::SpanFullException::what() const throw() {
    return "Span is full. Can't add more numbers!";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
    return "Not enough numbers to find a span!";
}
