#include "GL/gl.h"
#include "GL/freeglut.h"
#include <cmath>
#include <iostream>
#include "point.h"
#include <vector>


using namespace std;

void draw_circle(float cx, float cy, float r, int num_segments) {
    float theta = (float) (2 * 3.1415926 / float(num_segments));
    float tangential_factor = tanf(theta);//calculate the tangential factor
    float radial_factor = cosf(theta);//calculate the radial factor
    float x = r;//start at angle = 0;
    float y = 0;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {

        glVertex3f(x + cx, y + cy, 0);//output vertex
        //calculate the tangential vector
        //the radial vector is (x,y)
        //to get the tangential vector you flip those coordinates and negate one

        float tx = -y;
        float ty = x;

        //add tangential vector

        x += tx * tangential_factor;
        y += ty * tangential_factor;

        //correct using radial factor

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}

void draw_line(Point p1, Point p2) {
    glBegin(GL_LINES);
    glVertex2d(p1.x, p1.y);
    glVertex2d(p2.x, p2.y);
    glEnd();
}

void draw_wave_vector(vector<Point> points) {
    for (unsigned int i = 0; i < points.size() - 1; i++) {
        glBegin(GL_LINES);
        glVertex2i(points[i].x, points[i].y);
        glVertex2i(points[i + 1].x, points[i + 1].y);
        glEnd();
    }
}
