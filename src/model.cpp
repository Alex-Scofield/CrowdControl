/**
 * @file model.cpp
 * @author Alex Scofield
 * @brief Implementation of the simulation
 */

#include <vector>

#include "model.hpp"

Model::Model(int nballes, int nobstacles) {
    niter = 0;
    for (int i = 0; i < nballes; i++) {
        Ball ball = Ball(5, 10 * i, 10 * i);
        balls.push_back(ball);
    }
    circle_obstacles = {};
    for(int i = 0; i < nobstacles; i++) {
        CircleObstacle circle_obstacle = CircleObstacle(10, 60 * i, 80);
        circle_obstacles.push_back(circle_obstacle);
    }
}

bool Model::step() {
    //if(niter >= ITER_MAX) {return true;}
    for (int i = 0; i < balls.size(); i++) {
        balls[i].cr();
    }
    return true;
}