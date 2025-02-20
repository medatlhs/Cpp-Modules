#include "../Includes/Point.hpp"

Point::Point(const float x, const float y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point &other) {
    this->x = other.x;
    this->y = other.y;
}

Point& Point::operator=(const Point &other) {
    if (this == &other)
        return *this;
    this->x = other.x;
    this->y = other.y;
    return *this;
}

Point::~Point() { }

