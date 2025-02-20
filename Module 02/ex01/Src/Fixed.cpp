#include "../Includes/Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed::Fixed() : fixedPoint(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed&oldObj) {
    fixedPoint = oldObj.fixedPoint;
    std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int value) {
    this->fixedPoint = value << 8;
    std::cout << "Int constructor called\n";
    // 256 comes from 2^N, we multply by 2 to shift a bit in base 2
}

Fixed::Fixed(const float value) {
    this->fixedPoint = roundf(value * 256);
    std::cout << "Float constructor called\n";
}

Fixed& Fixed::operator=(const Fixed&oldObj) {
    if (this != &oldObj) {
        this->fixedPoint = oldObj.fixedPoint;
    }
    std::cout << "Copy assignment operator called\n";
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed &obj) {
    out << obj.toFloat();
    return (out);
}

float Fixed::toFloat(void) const {
    return (this->fixedPoint / 256.0f); // 256.0f to ensure float division
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

// operator overloading


// number 123 => 1111011
//               111101100000000


/*

Default constructor called
Int constructor called
Float constructor called
Copy constructor called

Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called



Default constructor called
Int constructor called
Float constructor called
Copy constructor called

Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called

*/
