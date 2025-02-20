#include "../Includes/Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::~Fixed() {
}

Fixed::Fixed() : fixedPoint(0) {
}

Fixed::Fixed(const Fixed&oldObj) {
    fixedPoint = oldObj.fixedPoint;
}

Fixed::Fixed(const int value) {
    this->fixedPoint = value << 8;
}

Fixed::Fixed(const float value) {
    this->fixedPoint = roundf(value * 256);
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
    return this->fixedPoint;
}

void Fixed::setRawBits( int const raw ) {
    this->fixedPoint = raw;
}

Fixed& Fixed::operator=(const Fixed&other) {
    if (this != &other) {
        this->fixedPoint = other.fixedPoint;
    }
    return *this;
}

bool Fixed::operator==(const Fixed&obj) {
    return (this->fixedPoint == obj.fixedPoint);
}

bool Fixed::operator!=(const Fixed&obj) {
    return (this->fixedPoint != obj.fixedPoint);
}

bool Fixed::operator<=(const Fixed&obj) {
    return (this->fixedPoint <= obj.fixedPoint);
}

bool Fixed::operator>=(const Fixed&obj) {
    return (this->fixedPoint >= obj.fixedPoint);
}

bool Fixed::operator>(const Fixed&obj) {
    return (this->fixedPoint > obj.fixedPoint);
}

bool Fixed::operator<(const Fixed&obj) {
    return (this->fixedPoint < obj.fixedPoint);
}

float Fixed::operator+(const Fixed&obj) {
    return (this->toFloat() + obj.toFloat());
}

float Fixed::operator-(const Fixed&obj) {
    return (this->toFloat() - obj.toFloat());
}

float Fixed::operator*(const Fixed&obj) {
    return (this->toFloat() * obj.toFloat());
}

float Fixed::operator/(const Fixed&obj) {
    return (this->toFloat() / obj.toFloat());
}

Fixed& Fixed::operator++() {
    this->fixedPoint += 1;
    return (*this);
}

Fixed& Fixed::operator--() {
    this->fixedPoint -= 1;
    return (*this);
}

Fixed Fixed::operator ++(int) {
    Fixed temp = *this;
    this->fixedPoint += 1;
    return (temp);
}

Fixed Fixed::operator --(int) {
    Fixed temp = *this;
    this->fixedPoint -= 1;
    return (temp);
}

const Fixed& Fixed::min( const Fixed &obj1, const Fixed &obj2) {
    if (obj1.fixedPoint <= obj2.fixedPoint)
        return obj1;
    return obj2;
}

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2) {
    if (obj1.fixedPoint <= obj2.fixedPoint)
        return obj1;
    return obj2;
}

const Fixed& Fixed::max( const Fixed &obj1, const Fixed &obj2) {
    if (obj1.fixedPoint >= obj2.fixedPoint)
        return obj1;
    return obj2;
}

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2) {
    if (obj1.fixedPoint >= obj2.fixedPoint)
        return obj1;
    return obj2;
}
