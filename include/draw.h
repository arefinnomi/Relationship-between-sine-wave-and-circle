#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include <GL/gl.h>
#include <cmath>
#include "point.h"

void drawCircle(float cx, float cy, float radius, int numSegments) {
    auto theta = static_cast<float>(2 * M_PI / numSegments);
    float tangentialFactor = tanf(theta);
    float radialFactor = cosf(theta);
    float x = radius; //start at angle = 0
    float y = 0;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++) {
        glVertex3f(x + cx, y + cy, 0);//output vertex
        //calculate the tangential vector
        //the radial vector is (x,y)
        //to get the tangential vector you flip those coordinates and negate one

        float tx = -y;
        float ty = x;

        //add tangential vector

        x += tx * tangentialFactor;
        y += ty * tangentialFactor;

        //correct using radial factor

        x *= radialFactor;
        y *= radialFactor;
    }
    glEnd();
}

void drawLine(const Point &p1, const Point &p2) {
    glBegin(GL_LINES);
    glVertex2d(p1.x, p1.y);
    glVertex2d(p2.x, p2.y);
    glEnd();
}

void drawWaveVector(const std::vector<Point> &points) {
    for (unsigned int i = 0; i < points.size() - 1; i++) {
        glBegin(GL_LINES);
        glVertex2i(points[i].x, points[i].y);
        glVertex2i(points[i + 1].x, points[i + 1].y);
        glEnd();
    }
}

#endif // DRAW_H_INCLUDED