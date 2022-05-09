#ifndef POINT2D_H_INCLUDED
#define POINT2D_H_INCLUDED

#include "cmath"

#include <iostream>

class Point2d
{
    double m_x{}, m_y{};

    public:
    Point2d(const double x = 0.0, const double y = 0.0);
    void print() const;
    double distanceTo(const Point2d& p) const;

    friend double distanceFrom(const Point2d& p1, const Point2d& p2);
};

#endif // POINT2D_H_INCLUDED
