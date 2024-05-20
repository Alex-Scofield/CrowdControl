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

// Function prototypes
void display();
void reshape(int width, int height);


void display() {
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set the color to red
    glColor3f(1.0f, 0.0f, 0.0f);

    // Set up the circle parameters
    float radius = 0.5f; // Adjust the radius as needed
    int numSegments = 100; // Number of line segments to approximate the circle
    float angleIncrement = 2.0f * 3.14159f / numSegments;

    // Begin drawing the circle
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i) {
        float angle = i * angleIncrement;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Swap buffers (double buffering)
    glutSwapBuffers();
}

void reshape(int width, int height) {
    // Set the viewport to cover the new window size
    glViewport(0, 0, width, height);
}

void graphics(Model &model) {
    // Initialize GLUT
    glutInit(0, NULL);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Crowd Control Simulation");

    // Register callback functions
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // Main loop
    glutMainLoop();
}