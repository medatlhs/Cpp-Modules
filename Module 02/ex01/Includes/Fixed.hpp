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

    Fixed&  operator=(const Fixed&oldObj);

    friend std::ostream& operator<<(std::ostream& out, const Fixed &obj);

    int toInt( void ) const;
    float toFloat( void ) const;

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

/*

class obj;

obj << std::cout;
std::cout << obj;

*/
