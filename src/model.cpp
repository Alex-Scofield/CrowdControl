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
    obstacles = {};
}

bool Model::step() {
    //if(niter >= ITER_MAX) {return true;}
    for (int i = 0; i < balls.size(); i++) {
        balls[0].cr();
    }
    return true;
}