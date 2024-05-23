/**
 * @file graphics.cpp
 * @author Alex Scofield
 * @brief Implements a graphical interface for the simulation, providing a layer of abstraction over openGL
 * 
 */

#include <GL/glut.h>
#include <math.h>
#include <memory>

#include "graphics.hpp"
#include "model.hpp"


std::unique_ptr<Model> model_ptr = nullptr; // Global variable containing the model to be displayed

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

void displayBall(double radius, double pos_x, double pos_y) {
    glColor3f(1.0f, 0.0f, 0.0f);
    displayCircle(radius, pos_x, pos_y);
}


void displayObstacle(double radius, double pos_x, double pos_y) {
    glColor3f(0.0f, 0.0f, 1.0f);
    displayCircle(radius, pos_x, pos_y);
}


void display() {
    model_ptr->step();
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(Ball ball : model_ptr->getBalls()) {
        displayCircle(ball.getRadius(), ball.getPosX(), ball.getPosY());
    }

    for (Object circle_obstacle : model_ptr->getCircleObstacles()){
        displayObstacle(circle_obstacle.getRadius(), circle_obstacle.getPosX(), circle_obstacle.getPosY());
    }

    // Swap buffers (double buffering)
    glutSwapBuffers();
}

void reshape(int width, int height) {
    // Set the viewport to cover the new window size
    glViewport(0, 0, width, height);
}

void graphics(int argc, char** argv, Model &model) {
    model_ptr = std::make_unique<Model>(model);
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