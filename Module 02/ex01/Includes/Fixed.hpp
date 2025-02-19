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
    Fixed& operator=(const Fixed&oldObj);

    int toInt( void ) const;
    float toFloat( void ) const;

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};
