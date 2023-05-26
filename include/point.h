#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

struct Point {
    GLint x = 0;
    GLint y = 0;

    Point() = default;

    Point(GLint xVal, GLint yVal) : x(xVal), y(yVal) {}
};

#endif // POINT_H_INCLUDED
