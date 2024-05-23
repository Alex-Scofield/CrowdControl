/**
 * @file model.cpp
 * @author Alex Scofield
 * @brief Implementation of the simulation
 */

#include <vector>
#include <memory>

#include "model.hpp"
#include "object.hpp"

std::vector<std::shared_ptr<Object>> Model::getObjects() {
    std::vector<std::shared_ptr<Object>> result;
    for (int i = 0; i < balls.size(); i++) {
        result.push_back(std::make_shared<Object>(balls[i]));
    }

    for (int i = 0; i < circle_obstacles.size(); i++) {
        result.push_back(std::make_shared<Object>(circle_obstacles[i]));
    }

    return result;
}

Model::Model(int nballes, int nobstacles) {
    niter = 0;
    for (int i = 0; i < nballes; i++) {
        Ball ball = Ball(5, 10 * i, 10 * i);
        balls.push_back(ball);
    }
    circle_obstacles = {};
    for(int i = 0; i < nobstacles; i++) {
        Object circle_obstacle = Object(10, 60 * i, 80);
        circle_obstacles.push_back(circle_obstacle);
    }
}

bool Model::step() {
    //if(niter >= ITER_MAX) {return true;}
    for (int i = 0; i < balls.size(); i++) {
        balls[i].updatePosition(getObjects(), EXIT_X, EXIT_Y);
    }
    return true;
}