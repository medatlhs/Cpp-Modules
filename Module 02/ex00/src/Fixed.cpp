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

/*
decimal value => 3.75
binary repres => 0011.1100
shift d point => 3.75 * 2^4 => 00111100
getback decimal value => 00111100 / 2^4 => 3.75
*/