#include <GL/glut.h>
#include <cmath>
#include<iostream>
#include<vector>
#include "include/point.h"
#include "include/draw.h"

using namespace std;
double frequency = .1;
GLint amplitude = 50;

void restrict_wave_vector(vector<Point> &points, unsigned int cont) {
    if (points.size() > cont)
        points.erase(points.begin());

}


void translate_wave_vector(vector<Point> &points, Point c_translate) {
    for (unsigned int i = 0; i < points.size(); i++) {
        points[i].x = points[i].x + c_translate.x;
        points[i].y = points[i].y + c_translate.y;
    }
}

Point center_circle = {amplitude * 2, amplitude * 2};

vector<Point> wave;
Point c_translate = {2, 0};


// angles of the three needles
double radius_degree = 0;

void display() {
    // Terminal Points for Needle
    Point end_radius;

    end_radius.y = (GLint) (center_circle.y + (amplitude * sin(radius_degree)));
    end_radius.x = (GLint) center_circle.x + (amplitude * cos(radius_degree));

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 1.0);
    draw_circle(center_circle.x, center_circle.y, amplitude, 10000);

    glColor3f(0.0, 0.0, 1.0);
    draw_line(center_circle, end_radius);


    Point init_Perpendicular;
    init_Perpendicular.x = center_circle.x + amplitude;
    init_Perpendicular.y = end_radius.y;


    Point end_Perpendicular;
    end_Perpendicular.x = center_circle.x + amplitude;
    if (end_radius.x >= amplitude)
        end_Perpendicular.y = end_radius.y + 2 * amplitude;
    else
        end_Perpendicular.y = end_radius.y + amplitude + 2 * amplitude;


    glColor3f(0.0, 1.0, 0.0);
    draw_line(init_Perpendicular, end_Perpendicular);


    glColor3f(0.0, 1.0, 1.0);
    draw_line(init_Perpendicular, end_radius);


    glColor3f(1.0, 0.0, 0.0);
    translate_wave_vector(wave, c_translate);
    wave.push_back(end_Perpendicular);
    restrict_wave_vector(wave, 500);
    draw_wave_vector(wave);


    glFlush();
    radius_degree += frequency;

}

void Timer(int value) {
    glutTimerFunc(50, Timer, 0);
    glutPostRedisplay();
}

void init() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.5f);
    glLineWidth(1.5f);
    gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

int main(int argc, char **argv) {
    frequency = .1;
    amplitude = 50;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(640 * 2, 480 * 2);
    glutCreateWindow("Square");
    glutDisplayFunc(display);
    init();
    Timer(50);
    glutMainLoop();

    return 0;
}
