#include "../Includes/Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed::Fixed() : fixedPoint(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed&oldObj) {
    std::cout << "Copy constructor called\n";
    fixedPoint = oldObj.fixedPoint;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called\n";
    this->fixedPoint = value * 256;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called\n";
    this->fixedPoint = roundf(value * 256);
}

Fixed& Fixed::operator=(const Fixed&oldObj) {
    std::cout << "Copy assignment operator called\n";
    if (this != &oldObj) {
        this->fixedPoint = oldObj.fixedPoint;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed &obj) {
    out << obj.toFloat();
    return (out);
}

float Fixed::toFloat(void) const {
    return (this->fixedPoint / 256.0f);
}

int Fixed::toInt(void) const {
    return (this->fixedPoint / 256);
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called\n";
    return this->fixedPoint;
}

void Fixed::setRawBits( int const raw ) {
    this->fixedPoint = raw;
}
