#include <iostream>
#include <string>

class Fixed
{
private:
    int fixedPoint;
    static const int fractionalBits;
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed&oldObj);

    ~Fixed();

    int toInt( void ) const;
    float toFloat( void ) const;

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    Fixed&  operator=(const Fixed&other);

    bool operator ==(const Fixed&obj);
    bool operator !=(const Fixed&obj);
    bool operator <=(const Fixed&obj);
    bool operator >=(const Fixed&obj);
    bool operator >(const Fixed&obj);
    bool operator <(const Fixed&obj);

    float operator +(const Fixed&obj);
    float operator -(const Fixed&obj);
    float operator *(const Fixed&obj);
    float operator /(const Fixed&obj);

// prefix
    Fixed &operator ++();
    Fixed &operator --();
// postfix
    Fixed operator ++(int);
    Fixed operator --(int);

    static const Fixed& min( const Fixed &obj1, const Fixed &obj2);
    static Fixed& min( Fixed &obj1, Fixed &obj2);
    static const Fixed& max(const Fixed &obj1, const Fixed &obj2);
    static Fixed& max( Fixed &obj1,  Fixed &obj2);

    friend std::ostream& operator<<(std::ostream& out, const Fixed &obj);
};
