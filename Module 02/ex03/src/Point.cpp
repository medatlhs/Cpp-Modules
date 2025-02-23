#include "../Includes/Point.hpp"

Point::Point(const float xPoint, const float yPoint) : x(xPoint), y(yPoint) {
}

Point::Point(const Point &other) {
    this->y = other.y;
    this->x = other.x; 
}

Point& Point::operator=(const Point &other) {
    if (this == &other)
        return *this;
    this->x = other.x;
    this->y = other.y;
    return *this;
}

float Point::getX() const {
    return x.toFloat();
}

float Point::getY() const {
    return y.toFloat();
}

Point::~Point() {
}

