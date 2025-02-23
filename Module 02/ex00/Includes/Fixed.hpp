#include <iostream>
#include <string>

class Fixed
{
private:
    int fixedPoint;
    static const int fractionalBits;
public:
    Fixed();
    Fixed(const Fixed&other);
    ~Fixed();
    Fixed& operator=(const Fixed&other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};
