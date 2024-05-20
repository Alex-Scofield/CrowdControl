#include <GL/glut.h>
#include <iostream>
#include <math.h>

// Function prototypes
void display();
void reshape(int width, int height);

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Crowd Control Simulation");

    // Register callback functions
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // Main loop
    glutMainLoop();

    return 0;
}

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
    glBegin(GL_LINE_LOOP);
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

