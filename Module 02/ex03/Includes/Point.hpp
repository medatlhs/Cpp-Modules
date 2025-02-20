#include <iostream>

class Point
{
private:
    float x;
    float y;
public:
    Point() : x(0), y(0) {};
    Point(const float x, const float y);
    Point(const Point &other);
    Point& operator =(const Point &other);
    ~Point();
};

