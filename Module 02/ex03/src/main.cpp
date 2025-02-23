#include "../Includes/Fixed.hpp"
#include "../Includes/Point.hpp"


int main()
{
    Point a(1, 1);
    Point b(6, 1);
    Point c(3, 4);
    Point point(5, 8);

    bsp(a, b, c, point) ? std::cout << "true\n" : std::cout << "false\n";
    return 0;
}
