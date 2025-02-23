#include "../Includes/Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPoint(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed&other) {
    std::cout << "Copy constructor called\n";
    fixedPoint = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed&other) {
    std::cout << "Copy assignment operator called\n";
    if (this != &other) {
        this->fixedPoint = other.getRawBits();
    }
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
