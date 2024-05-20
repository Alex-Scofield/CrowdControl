/**
 * @file graphics.cpp
 * @author Alex Scofield
 * @brief Implements a graphical interface for the simulation, providing a layer of abstraction over openGL
 * 
 */

#include <GL/glut.h>
#include <math.h>

#include "graphics.hpp"
#include "model.hpp"


Model *model_ptr = NULL; // Global variable containing the model to be displayed

void displayCircle(double radius, double pos_x, double pos_y) {
    radius = 2 * radius / (model_ptr->WIDTH + model_ptr->HEIGHT);
    pos_x = pos_x / model_ptr->WIDTH;
    pos_y = pos_y / model_ptr->HEIGHT;

    int numSegments = 100; // Number of line segments to approximate the circle
    float angleIncrement = 2.0f * 3.14159f / numSegments;

    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i) {
        float angle = i * angleIncrement;
        float x = pos_x + radius * cos(angle);
        float y = pos_y + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}


void display() {
    model_ptr->step();
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set the color to red
    glColor3f(1.0f, 0.0f, 0.0f);

    for(Ball ball : model_ptr->getBalls()) {
        displayCircle(ball.getRadius(), ball.getPosX(), ball.getPosY());
    }

    // Swap buffers (double buffering)
    glutSwapBuffers();
}

void reshape(int width, int height) {
    // Set the viewport to cover the new window size
    glViewport(0, 0, width, height);
}

void graphics(int argc, char** argv, Model *model) {
    model_ptr = model;
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Crowd Control Simulation");

    // Register callback functions
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);

    // Main loop
    glutMainLoop();
}