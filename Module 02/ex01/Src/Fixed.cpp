#include "../Includes/Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPoint(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed&oldObj) {
    fixedPoint = oldObj.fixedPoint;
    std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed&oldObj) {
    if (this != &oldObj) {
        this->fixedPoint = oldObj.fixedPoint;
    }
    std::cout << "Copy assignment operator called\n";
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called\n";
    return this->fixedPoint;
}

void Fixed::setRawBits( int const raw ) {
    this->fixedPoint = raw;
}

Fixed::Fixed(const int value) {
    this->fixedPoint = value * 256; // 256 comes from 2^N, we multply by 2 to shift a bit in base 2
}

Fixed::Fixed(const float value) {
    this->fixedPoint = value * 256;
}

float Fixed::toFloat(void) const {
    return (this->fixedPoint / 256);
}

int Fixed::toInt(void) const {
    return (this->fixedPoint / 256);
}

