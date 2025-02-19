#include <iostream>
#include <string>

class Fixed
{
private:
    int fixedPoint;
    static const int fractionalBits;
public:
    Fixed();
    Fixed(const Fixed&oldObj);
    ~Fixed();
    Fixed& operator=(const Fixed&oldObj);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};
