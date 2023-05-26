#include <GL/glut.h>
#include <cmath>
#include <vector>
#include "include/point.h"
#include "include/draw.h"

using namespace std;

// Global variables
double frequency = 0.1;
GLint amplitude = 50;
Point centerCircle = {amplitude * 2, amplitude * 2};
vector<Point> wave;
Point cTranslate = {2, 0};
double radiusDegree = 0;

// Function prototypes
void restrictWaveVector(vector<Point> &points, unsigned int count);
void translateWaveVector(vector<Point> &points, const Point &translation);
void display();
void timer(int value);
void initialize();

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(640 * 2, 480 * 2);
    glutCreateWindow("Square");
    glutDisplayFunc(display);
    initialize();
    timer(50);
    glutMainLoop();
    return 0;
}

void restrictWaveVector(vector<Point> &points, unsigned int count) {
    if (points.size() > count) {
        points.erase(points.begin());
    }
}

void translateWaveVector(vector<Point> &points, const Point &translation) {
    for (auto & point : points) {
        point.x += translation.x;
        point.y += translation.y;
    }
}

void display() {
// Terminal Points for Needle
    Point endRadius;
    endRadius.y = centerCircle.y + static_cast<GLint>(amplitude * sin(radiusDegree));
    endRadius.x = centerCircle.x + static_cast<GLint>(amplitude * cos(radiusDegree));

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 1.0);
    drawCircle(static_cast<float>(centerCircle.x), static_cast<float>(centerCircle.y), static_cast<float>(amplitude), 10000);

    glColor3f(0.0, 0.0, 1.0);
    drawLine(centerCircle, endRadius);

    Point initPerpendicular;
    initPerpendicular.x = centerCircle.x + amplitude;
    initPerpendicular.y = endRadius.y;


    Point endPerpendicular;
    endPerpendicular.x = centerCircle.x + amplitude;
    if (endRadius.x >= amplitude) {
        endPerpendicular.y = endRadius.y + 2 * amplitude;
    } else {
        endPerpendicular.y = endRadius.y + amplitude + 2 * amplitude;
    }

    glColor3f(0.0, 1.0, 0.0);
    drawLine(initPerpendicular, endPerpendicular);

    glColor3f(0.0, 1.0, 1.0);
    drawLine(initPerpendicular, endRadius);

    glColor3f(1.0, 0.0, 0.0);
    translateWaveVector(wave, cTranslate);
    wave.push_back(endPerpendicular);
    restrictWaveVector(wave, 500);
    drawWaveVector(wave);

    glFlush();
    radiusDegree += frequency;
}

void timer(int value) {
    glutTimerFunc(value, timer, value);
    glutPostRedisplay();
}

void initialize() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.5f);
    glLineWidth(1.5f);
    gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}