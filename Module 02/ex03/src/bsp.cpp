#include "../Includes/Point.hpp"

float calculateArea(Point const a, Point const b, Point const c) {
    float Area = (a.getX() * (b.getY() - c.getY()) + 
                    b.getX() * (c.getY() - a.getY()) +
                    c.getX() * (a.getY() - b.getY())) / 2;
    if (Area < 0)
        return Area * -1;
    return Area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

    float fullArea = calculateArea(a, b, c);
    float triangle1 = calculateArea(point, c, a);
    float triangle2 = calculateArea(point, b, c);
    float triangle3 = calculateArea(point, b, a);

    if (!triangle1 || !triangle2 || !triangle3)
        return false;
    if (fullArea == (triangle1 + triangle2 + triangle3))
        return true;
    return false;
}
